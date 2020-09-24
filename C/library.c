#include "library.h"

/*
 * @Author: Lyuboslav Karev
 * This file contains the main library code for the task
 */

/*
 * Function: print_graph
 *
 * Prints to the screen a graph, represented by a character matrix.
 *
 * graph - the pointer to the graph
 * bottom_right - location of the bottom right point in the graph.
 *      For example, if the graph has 3 rows and 4 columns, bottom_right's value
 *      should be (2, 3)
 */
void print_graph(const char** graph, const struct Point* bottom_right){
    for(int i = 0; i <= bottom_right->x; i++){
        for(int j = 0; j <= bottom_right->y; j++){
            printf("%c ", graph[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/*
 * Function: is_point_valid
 *
 * Returns whether target is inside the rectangle formed by the points (0, 0) and bottom_right (inclusive)
 *
 * bottom_right - location of the bottom right point in the graph.
 *      For example, if the graph has 3 rows and 4 columns, bottom_right's value
 *      should be (2, 3)
 */
bool is_point_valid(const struct Point* target, const struct Point* bottom_right){
    return (0 <= target->x && target->x <= bottom_right->x) && (0 <= target->y && target->y <= bottom_right->y);
}

/*
 * Function: traverse_graph
 *
 * Returns the maximum length of a valid path, starting at start, in the graph.
 * The main idea is:
 *      1. Create a queue to store the neighbours
 *      2. Mark the start node as visited (we set it to lowercase letter)
 *      3. Add the right and down neighbour of the start node
 *      4. While there are elements in the queue, get the first node from it
 *      5. Mark it as visited
 *      6. Add its neighbours to the queue, which have not been visited, and have the same letter as the start node
 *      7. Increase the length of the current path by 1
 *      8. Repeat 4.
 *      9. When there are no more valid neighbours, return the length
 *
 */
uint traverse_graph(char** graph, struct Point* start, const struct Point* bottom_right) {
    struct Queue neighbours = create_queue();
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
            push(&neighbours, current_point);
        }
    }

    int length = 1;
    while(neighbours.length > 0){
        struct Point temp = pop(&neighbours);
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
                push(&neighbours, current_point);
            }
        }
    }

    free_queue(&neighbours);
    return length;

}

/*
 * Function: parse_graph
 *
 * Convert the linear representation of the graph to a 2d one.
 * For example, the linear representation of the graph 'RRGGGBBBR` as a 2D array is
 *
 *  R R G
 *  G G B
 *  B B R
 */
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

/*
 * Function find_longest_len
 *
 * The main entry point of the algorithm
 *
 * Accepts a linear representation for the graph (its easier to pass it that way) and the coordinates of the bottom
 *  right point
 *
 * Then for each point that is not visited (has a upper case valid letter), we run traverse_graph.
 * If the current point is visited, we skip it.
 * If the point is not visited, we traverse the graph from it, and compare the length to the current maximum.
 */
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
