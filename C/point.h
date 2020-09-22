//
// Created by lyubo on 21.09.20 г..
//

#ifndef STRYPESTASK_POINT_H
#define STRYPESTASK_POINT_H

#include <stdlib.h>
#include <stdbool.h>

struct Point{
    uint x;
    uint y;
};

struct Point create_point(uint init_x, uint init_y);
#endif //STRYPESTASK_POINT_H
