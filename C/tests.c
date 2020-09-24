//
// Created by lyubo on 21.09.20 г..
//

#include <stdlib.h>
#include <stdio.h>
#include "library.h"

int main(){
    char* user_input = calloc(10, sizeof(char));
    strcpy(user_input, "RRBGGRRBG");
    printf("%d", find_longest_len(user_input, 2, 2));

    free(user_input);
    return 0;
}
