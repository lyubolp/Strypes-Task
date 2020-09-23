//
// Created by lyubo on 21.09.20 г..
//

#ifndef STRYPESTASK_QUEUE_H
#define STRYPESTASK_QUEUE_H

#include <stdlib.h>
#include "point.h"
struct Queue{
    struct Point* items;
    unsigned length;
    unsigned size;
};


struct Queue create_queue();
void resize(struct Queue* this);
void push(struct Queue* this, struct Point item);
struct Point pop(struct Queue* this);
void print(const struct Queue* this);

void free_queue(struct Queue* this);

#endif //STRYPESTASK_QUEUE_H
