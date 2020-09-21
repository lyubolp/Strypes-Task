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
    temp.items = calloc(1, sizeof(char));
    return temp;
}

void copy_memory(const char* source,  char* destination, uint length){
    // Assume that destination is already allocated
    for(uint i = 0; i < length; i++){
        destination[i] = source[i];
    }
}

void clear_memory(char* source){
    free(source);
}
void resize(struct Queue* this){
    this->size *= 2;
    char* new_memory = calloc(this->size, sizeof(char));

    copy_memory(this->items, new_memory, this->length);
    clear_memory(this->items);
    this->items = new_memory;
}
void push(struct Queue* this, const char item){
    if(this->length == this->size){
        resize(this);
    }
    this->items[this->length] = item;
    this->length += 1;
}

char pop(struct Queue* this){
    this->length -= 1;
    return this->items[this->length];
}

void destroy(struct Queue* this){
    clear_memory(this->items);
}
