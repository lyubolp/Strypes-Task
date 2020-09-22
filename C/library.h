#ifndef STRYPESTASK_LIBRARY_H
#define STRYPESTASK_LIBRARY_H

#include <stdlib.h>
#include "queue.h"
#include "point.h"
extern uint find_longest_len(char** graph, const struct Point* bottom_right);


uint traverse_graph(char** graph, struct Point* start, const struct Point* bottom_right);
void hello(void);

#endif //STRYPESTASK_LIBRARY_H
