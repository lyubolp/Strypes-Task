#include "library.h"

#include <stdio.h>
#include <math.h>

void print_graph(const char** graph, const struct Point* bottom_right){
    for(int i = 0; i <= bottom_right->x; i++){
        for(int j = 0; j <= bottom_right->y; j++){
            printf("%c ", graph[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
uint traverse_graph(char** graph, struct Point* start, const struct Point* bottom_right) {
    struct Queue visited = create_queue();
    uint lower_to_upper = 'a' - 'A';
    char target = graph[start->x][start->y];
    graph[start->x][start->y] += lower_to_upper; //Marks it as visited

    if(start->x < bottom_right->x && graph[start->x + 1][start->y] == target){
        push(&visited, create_point(start->x + 1, start->y));
    }

    if(start->y < bottom_right->y && graph[start->x][start->y + 1] == target){
        push(&visited, create_point(start->x, start->y + 1));
    }

    int length = 1;
    while(visited.length > 0){
        struct Point temp = pop(&visited);
        if(graph[temp.x][temp.y] != target){
            continue;
        }
        graph[temp.x][temp.y] += lower_to_upper;
        length += 1;

        if(temp.x < bottom_right->x && graph[temp.x + 1][temp.y] == target){
            push(&visited, create_point(temp.x + 1, temp.y));
        }
        if(temp.y < bottom_right->y && graph[temp.x][temp.y + 1] == target){
            push(&visited, create_point(temp.x, temp.y + 1));
        }
        if(0 < temp.x && graph[temp.x - 1][temp.y] == target){
            push(&visited, create_point(temp.x - 1, temp.y));
        }
        if(0 < temp.y && graph[temp.x][temp.y - 1] == target){
            push(&visited, create_point(temp.x, temp.y - 1));
        }
    }

    destroy(&visited);
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
    return max_path;
}
