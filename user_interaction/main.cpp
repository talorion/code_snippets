#include <cstdlib>
#include <stdio.h>
#include "config.h"

int main(){
    printf("\033[1;1H\033[2J"); // clear screen
    printf("Starting %s v%s\n",PROJECT_NAME,PROJECT_VER);
    return EXIT_SUCCESS;
}
