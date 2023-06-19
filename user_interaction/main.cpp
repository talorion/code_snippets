#include <cstdlib>
#include <stdio.h>
#include <thread>
#include "config.h"
#include <chrono>

using namespace std::chrono_literals;

constexpr const char * CLEAR_SCREEN_STR ="\033[1;1H\033[2J";
constexpr const char * CLEAR_LINE_STR ="\33[2K\r";

namespace clear{
    void screen(void){
        printf(CLEAR_SCREEN_STR); // clear screen
    }

    void line(void){
        printf(CLEAR_LINE_STR); // clear screen
    }
} // namespace clear


namespace spinning_cursor{
    constexpr size_t count = 5;
    constexpr const char states[count]={'/','-','\\','|','-' };
    static int pos=0;

    void tick(){
        pos = (pos+1) % count;
        printf("%c", states[pos]);
        fflush(stdout);
    }
} // namespce spinning_cursor

int main(){
    clear::screen();
    printf("Starting %s v%s\n",PROJECT_NAME,PROJECT_VER);

    // spinns a cursor for 10s
    for(int i = 0; i <100; i++){
        clear::line();
        printf("processing... ");
        spinning_cursor::tick();
        std::this_thread::sleep_for(100ms);
    }
    printf("\n");

    return EXIT_SUCCESS;
}
