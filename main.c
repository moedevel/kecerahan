#include <stdio.h>
#include <stdlib.h>

#define ERROR(...) do { fprintf(stderr, __VA_ARGS__); return 2; } while(0)

/* silahkan edit 'DEVICES' dan sesuaikan dengan devices yang kalian punya */
#define TARGET "/sys/class/backlight/radeon_bl0/brightness"

int main(int argc, char **argv) {

    if(argc != 2)
        ERROR("[%s] untuk cara penggunaan silaskan baca manpage 'man %s'\n", argv[0], argv[0]);

    FILE *device_file;
    device_file = fopen(TARGET, "w");

    if(device_file == NULL)
        ERROR("[%s] silahkan edit DEVICES di main.c! dan jalankan sebagai root!\n", argv[0]);
        
    fprintf(device_file, "%s", argv[1]);
    fclose(device_file);

    return 0;
}
