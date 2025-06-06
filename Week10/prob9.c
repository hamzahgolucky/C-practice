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

void ifneg(int length)
{
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
}


void ifpos(int start) {
    char line[LINEMAX];
    char **lines = NULL; 
    int line_count = 0;  

    while (getchars(line, sizeof(line)) >= 0) {
        lines = realloc(lines, (line_count + 1) * sizeof(*lines));
        lines[line_count++] = strdup(line);
    }

    for (int index = start; index < line_count; index++) {
        printf("%s\n", lines[index]);
        free(lines[index]);
    }
    free(lines);
}



int main(int argc, char **argv)
{
	int length = 0;
	int start = 0;
	if (argc == 2)
	{
		if ('-' == *(*(argv+1)))
			length = atoi(*(argv+1)+1);
		else if ('+' == *(*(argv+1)))
			start = atoi(*(argv+1)+1);
		else {printf("illegal argument\n"); goto exit;}
	}
	else if (argc > 2) 
	{
		if ('-' == *(*(argv+argc-1)))
			length = atoi(*(argv+argc-1)+1);
		else if ('+' == *(*(argv+argc-1)))
			start = atoi(*(argv+argc-1)+1);
		else {printf("illegal argument\n"); goto exit;}
	}
	else length = 10;
	
	exit:
    
	if (length) ifneg(length);
	else if (start) ifpos(start);

    return 0;
}

