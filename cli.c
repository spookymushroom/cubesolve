#include "cubesolve.h"


int main(int argc, char **argv)
{
	int ishelp = 0;
	int isquiet = 0;
	for (int i = 0; i < argc; ++i) {
		if (!strncmp(argv[i],"-h",2)) {
			ishelp = 1;
			break;
		}
		if (!strncmp(argv[i],"-q",2)) isquiet = 1;
	}
	if (ishelp) {
		printf("Help template\n");
		exit(0);
	}
	if (!isquiet) {
		printf("Welcome to cubesolver v0.01:\n");
		printf("Solve how to fit together pieces to create 3x3 cube\n");
		printf("Enter piece as indexes blocks separated by spaces\n");
		printf("Empty line quits data entry mode\n\n");
		printf("1  2  3\n4  5  6   (layer 1)\n7  8  9\n\n");
		printf("10 11 12\n13 14 15  (layer 2)\n16 17 18\n\n");
		printf("19 20 21\n22 23 24  (layer 3)\n25 26 27\n\n");
	}

	unsigned int myint = 0;
	unsigned int piecearr [27];

	size_t n = 128;
	ssize_t linelen = 0;
	char *line = malloc(n*sizeof(char));
	size_t offset;
	size_t nread;

	while ((linelen = getline(&line,&n,stdin)) > 1) {
		offset = 0, nread = 0;
		for (int i = 0; i < 27; ++i) piecearr[i] = 0;
		while (sscanf(line+offset,"%u%zn",&myint,&nread) != EOF) {
			offset += nread;
			if (myint>=1 && myint<=27) {
				piecearr[myint-1] = 1;
			}
		}
		for (int i = 0; i < 27; ++i) if (piecearr[i]) printf("%d ",i+1);
		printf("\n");
	}

	free(line);
	/*Must be freed:
	line
	*/

}
