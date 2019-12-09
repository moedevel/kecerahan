#include <stdio.h>
/* silahkan edit 'DEVICES' dan sesuaikan dengan devices yang kalian punya */
#define TARGET "/sys/class/backlight/DEVICES/brightness"

int char_toint(char *arr) {
        int num = 0;
        short digit, mult = 1, offset = 0;
        if (*arr == '-') {
                mult = -1;
                offset++;
        } else if (*arr == '+') {
                offset++;
        }
        while (*(arr + offset) != '\0') {
                digit = * (arr + offset) - 48;
                num = num * 10 + digit;
                offset++;
        }
        return num * mult;
}

void int_tochar(int num, char *buf) {
        short digit, offset = 0;
        int save = num, div = 1;
        while (save > 0) {
                div *= 10;
                save /= 10;
        }
        div /= 10;

        while (div >= 1) {
                digit = num / div % 10;
                div /= 10;
                *(buf + offset) = digit + 48;
                offset++;
        }
        *(buf + offset) = '\0';
}

int main(int argc, char *argv[]) {
        if (argc == 2) {
                FILE *korban;
                if (argv[1][0] != '-' && argv[1][0] != '+') {
                        korban = fopen(TARGET, "w");
                        fprintf(korban, "%s", argv[1]);
                        fclose(korban);
                } else {
                        char buff[4];
                        korban = fopen(TARGET, "r");
                        fscanf(korban, "%s", buff);
                        fclose(korban);
                        int d = char_toint(buff);
                        int step = char_toint(argv[1]);
                        d += step;
                        int_tochar(d, buff);
                        korban = fopen(TARGET, "w");
                        fprintf(korban, "%s", buff);
                        fclose(korban);
                }
                return 0;
        } else {
                printf("please input a valid number and run as root \n");
                return 0;
        }
}
