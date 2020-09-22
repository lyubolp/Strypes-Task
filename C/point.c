//
// Created by lyubo on 21.09.20 г..
//

#include "point.h"

struct Point create_point(uint init_x, uint init_y){
    struct Point temp;
    temp.x = init_x;
    temp.y = init_y;

    return temp;
}
