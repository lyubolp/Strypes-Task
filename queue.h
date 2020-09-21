//
// Created by lyubo on 21.09.20 г..
//

#ifndef STRYPESTASK_QUEUE_H
#define STRYPESTASK_QUEUE_H

#include <stdlib.h>

struct Queue{
    char* items;
    unsigned length;
    unsigned size;
};


struct Queue new();
void resize(struct Queue* this);
void push(struct Queue* this, char item);
char pop(struct Queue* this);

void destroy(struct Queue* this);

#endif //STRYPESTASK_QUEUE_H
