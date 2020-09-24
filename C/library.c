#include "library.h"

void print_graph(const char** graph, const struct Point* bottom_right){
    for(int i = 0; i <= bottom_right->x; i++){
        for(int j = 0; j <= bottom_right->y; j++){
            printf("%c ", graph[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool is_point_valid(const struct Point* target, const struct Point* bottom_right){
    return (0 <= target->x && target->x <= bottom_right->x) && (0 <= target->y && target->y <= bottom_right->y);
}

uint traverse_graph(char** graph, struct Point* start, const struct Point* bottom_right) {
    struct Queue visited = create_queue();
    const uint lower_to_upper = 'a' - 'A';

    char target = graph[start->x][start->y];
    graph[start->x][start->y] += lower_to_upper; //Marks it as visited

    int x_offset[2] = {1, 0};
    int y_offset[2] = {0, 1};

    for(int i = 0; i < 2; i++){
        uint target_x = start->x + x_offset[i];
        uint target_y = start->y + y_offset[i];

        struct Point current_point = create_point(target_x, target_y);
        if(is_point_valid(&current_point, bottom_right)){
            push(&visited, current_point);
        }
    }

    int length = 1;
    while(visited.length > 0){
        struct Point temp = pop(&visited);
        if(graph[temp.x][temp.y] != target){
            continue;
        }
        graph[temp.x][temp.y] += lower_to_upper;
        length += 1;

        int x_offset[4] = {1, 0, -1, 0};
        int y_offset[4] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++){
            uint target_x = temp.x + x_offset[i];
            uint target_y = temp.y + y_offset[i];

            struct Point current_point = create_point(target_x, target_y);
            if(is_point_valid(&current_point, bottom_right)){
                push(&visited, current_point);
            }
        }
    }

    free_queue(&visited);
    return length;

}
char** parse_graph(const char* unparsed_graph, struct Point* bottom_right){
    char** result = calloc(bottom_right->x + 1, sizeof(char*));

    for(uint i = 0; i <= bottom_right->x; i++){
        result[i] = calloc(bottom_right->y + 1, sizeof(char));
    }
    for(uint i = 0; i <= bottom_right->x; i++){
        for(uint j = 0; j <= bottom_right->y; j++){
            result[i][j] = unparsed_graph[(i * (bottom_right->x + 1)) + j];
        }
    }
    return result;
}

void free_graph(char** graph, const int rows){
    for(int i = 0; i < rows; i++){
        free(graph[i]);
    }
    free(graph);
}
extern int find_longest_len(char* unparsed_graph, const int bottom_right_x, const int bottom_right_y){
    int max_path = 0;
    struct Point bottom_right = create_point(bottom_right_x, bottom_right_y);
    char** graph = parse_graph(unparsed_graph, &bottom_right);

    for(uint i = 0; i <= bottom_right.x; i++){
        for(uint j = 0; j <= bottom_right.y; j++){
            if(graph[i][j] == 'R' || graph[i][j] == 'G' || graph[i][j] == 'B'){
                struct Point temp = create_point(i, j);
                uint current_result = traverse_graph(graph, &temp, &bottom_right);
                if(current_result > max_path){
                    max_path = current_result;
                }
            }
        }
    }
    free_graph(graph, bottom_right_x + 1);
    return max_path;
}
