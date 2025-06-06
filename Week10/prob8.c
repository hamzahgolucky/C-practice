#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getchars(char *s, int limit)
{
    int i = 0, c;
    while (i < limit - 1 && EOF != (c = getchar()) && c != '\n')
        s[i++] = c;
    if (EOF == c && i == 0) return -1;
    s[i] = '\0';
    return i;
}

#define LINEMAX 1024

int main(int argc, char **argv)
{
	int length = 0;
	if (argc == 2)
	{
		if ('-' == *(*(argv+1)))
			length = atoi(*(argv+1)+1);
		else {printf("illegal argument\n"); goto exit;}
	}
	else if (argc > 2) 
	{
		if ('-' == *(*(argv+argc-1)))
			length = atoi(*(argv+argc-1)+1);
		else {printf("illegal argument\n"); goto exit;}
	}
	else length = 10;
	
	exit:
    
    char   line[LINEMAX];
    char  **lines = malloc(length*sizeof(*line));

    int index = 0;
    while (getchars(line, sizeof(line)) >= 0) {
	if (index >= length) free(lines[index % length]);
	lines[index++ % length] = strdup(line); // this must be free()d
    }
    for (int i = index - length;  i < index;  ++i) {
	if (i >= 0) { // entry exists in array
	    printf("%s\n", lines[i % length]);
	    free(lines[i % length]);
	}
    }

    return 0;
}

