#include <stdio.h>

int main(int argc, char *argv[]) {

	int val, inc;
	char c;

	if (argc != 2) {
		printf("kecerahan: pakai: \"kecerahan {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, +, -}\"\n");
		return 1;
	} else if (argv[1][1] != '\0') {
		printf("kecerahan: pakai: \"kecerahan {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, +, -}\"\n");
		return 1;
	} else {
		switch (c=*argv[1]) {
			case '0':
			case '1':
			case '2': /* for *argv[1] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} */
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9': val = c - '0'; inc = 0; break;
			case '+': val = 1; inc = 1; break;
			case '-': val = 1; inc =-1; break;
			default: printf("kecerahan: pakai: \"kecerahan {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, +, -}\"\n"); break;
		}
	}

	FILE *fp; /* fp = file pointer */
	int br_val;

	/* silahkan edit 'DEVICES' dan sesuaikan dengan devices yang kalian punya */
	if ((fp = fopen("/sys/class/backlight/DEVICES/brightness", "r")) == NULL) {
		printf("kecerahan: Tidak dapat membuka file.\n");
		return 1;
	} else {
		fscanf(fp, "%d", &br_val);
		fclose(fp);

		int br_new = (inc==0) ? val : br_val + inc;
		if (br_new > 7) {
			printf("kecerahan: dalam maximal.\n");
		} else if (br_new < 0) {
			printf("kecerah: dalam minimal.\n");
		}
		
		/* silahkan edit 'DEVICES' dan sesuaikan dengan devices yang kalian punya */
		if ((fp = fopen("/sys/class/backlight/DEVICES/brightness", "w")) == NULL) {
			printf("kecerahan: Tidak dapat membuka file sedang dalam menulis.\n");
			return 1;
		} else {
			fprintf(fp, "%d", br_new);
			fclose(fp);
		}
	}
	return 0;
}
