#include <cerrno>
#include <cstdlib>
#include <cstring>
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


void quit_or_int(){
    constexpr size_t buffer_sz = 20;
    static char buffer[buffer_sz] = {0};

    printf("please enter count to continue or q to quit: ");
    
    memset(buffer,0,buffer_sz);
    if(!fgets(buffer, buffer_sz, stdin)){
        fprintf(stderr, "Could not get input");
        return;
    }

    auto s = &buffer[0];
    auto l = strlen(buffer);
    if(l > buffer_sz){l = buffer_sz;}
    while(iswspace(s[l-1])) --l;
    while(*s && iswspace(*s)) ++s, --l;
    // memset(buffer, 0, buffer_sz);
    memcpy(buffer, s, buffer_sz);
    auto len = strlen(buffer);
    printf("len=%ld\n", len);
    printf("buffer=%s\n", buffer);

    if(len<=0){
        printf("got no input \n");
        return;
    }


    if((len==1 || len==2) && buffer[0] == 'q'){
        printf("quitting... \n");
        return;
    }

    auto tmp_value = strtol(buffer, (char**) NULL, 10);
    if(tmp_value > 0){
        printf("got %ld as input \n", tmp_value);
        return;
    }

    fprintf(stderr, "unexpected input %ld\n", tmp_value);

}

int main(){
    clear::screen();
    printf("Starting %s v%s\n",PROJECT_NAME,PROJECT_VER);

    // spinns a cursor for 10s
    // for(int i = 0; i <100; i++){
    //     clear::line();
    //     printf("processing... ");
    //     spinning_cursor::tick();
    //     std::this_thread::sleep_for(100ms);
    // }
    // printf("\n");

    printf("enter 'q' or number:");
    quit_or_int();

    return EXIT_SUCCESS;
}
