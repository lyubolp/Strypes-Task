//
// Created by lyubo on 21.09.20 г..
//
#include "queue.h"
#include <assert.h>
#include <string.h>
struct Queue new(){
    struct Queue temp;
    temp.length = 0;
    temp.size = 1;
    temp.items = calloc(1, sizeof(struct Point));
    return temp;
}

void copy_memory(const struct Point* source,  struct Point* destination, uint length){
    // Assume that destination is already allocated
    for(uint i = 0; i < length; i++){
        destination[i] = source[i];
    }
}

void clear_memory(struct Point* source){
    free(source);
}
void resize(struct Queue* this){
    this->size *= 2;
    struct Point* new_memory = calloc(this->size, sizeof(struct Point));

    copy_memory(this->items, new_memory, this->length);
    clear_memory(this->items);
    this->items = new_memory;
}
void push(struct Queue* this, const struct Point item){
    if(this->length == this->size){
        resize(this);
    }
    this->items[this->length] = item;
    this->length += 1;
}

struct Point pop(struct Queue* this){
    this->length -= 1;
    return this->items[this->length];
}

void destroy(struct Queue* this){
    clear_memory(this->items);
}
