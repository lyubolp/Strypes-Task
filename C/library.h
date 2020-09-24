#ifndef STRYPESTASK_LIBRARY_H
#define STRYPESTASK_LIBRARY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "queue.h"
#include "point.h"
extern int find_longest_len(char* unparsed_graph, int bottom_right_x, int bottom_right_y);

/*extern void print_str(char* string){
    printf("%s", string);
}*/
char** parse_graph(const char* unparsed_graph, struct Point* bottom_right);
uint traverse_graph(char** graph, struct Point* start, const struct Point* bottom_right);

#endif //STRYPESTASK_LIBRARY_H
