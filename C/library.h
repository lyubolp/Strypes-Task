#ifndef STRYPESTASK_LIBRARY_H
#define STRYPESTASK_LIBRARY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "queue.h"
#include "point.h"
extern int find_longest_len(char* unparsed_graph, const int bottom_right_x, const int bottom_right_y);

void free_graph(char** graph, const int rows);
void print_graph(const char** graph, const struct Point* bottom_right);
bool is_point_valid(const struct Point* target, const struct Point* bottom_right);
char** parse_graph(const char* unparsed_graph, struct Point* bottom_right);
uint traverse_graph(char** graph, struct Point* start, const struct Point* bottom_right);

#endif //STRYPESTASK_LIBRARY_H
