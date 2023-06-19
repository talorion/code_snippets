#include <cstdlib>
#include <stdio.h>
#include "config.h"

constexpr const char * CLEAR_SCREEN_STR ="\033[1;1H\033[2J";
constexpr const char * CLEAR_LINE_STR ="\33[2K\r";

void clear_screen(void){
    printf(CLEAR_SCREEN_STR); // clear screen
}

void clear_line(void){
    printf(CLEAR_LINE_STR); // clear screen
}

int main(){
    clear_screen();
    printf("Starting %s v%s\n",PROJECT_NAME,PROJECT_VER);

    for(int i=10 ; i>0; i--){
        clear_line();
        printf("Hello %d", i);
    }
    printf("\n");

    return EXIT_SUCCESS;
}
