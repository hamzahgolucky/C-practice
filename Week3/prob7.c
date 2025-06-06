#include <stdio.h>

int main()
{
    int c;
    int d[127];
    int i = 0;
    
    for (i = 0; i <= 126; i = i + 1)
    {
        d[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        if (0 <= c && c <= 126)
        {
            ++d[c];
        }
    }

    // Print counts for control characters and space
    for (i = 0; i <= 32; i = i + 1)
    {
        if (d[i] != 0)
        {
            if (i == '\t')
            {
                printf("\\t\t %d\t", d[i]);
            }
            else if (i == '\n')
            {
                printf("\\n\t %d\t", d[i]);
            }
            else if (i == ' ')
            {
                printf(" \t %d\t", d[i]);
            }
            else
            {
                printf("\\%03o\t %d\t", i, d[i]);
            }

            // Print histogram
            for (int a = 1; a <= d[i]; a = a + 1)
            {
                putchar('*');
            }
            printf("\n");
        }
    }

    // Print counts for printable characters
    for (i = 33; i <= 126; i = i + 1)
    {
        if (d[i] != 0)
        {
            printf("%c\t %d\t", i, d[i]);

            // Print histogram
            for (int a = 1; a <= d[i]; a = a + 1)
            {
                putchar('*');
            }
            printf("\n");
        }
    }

    return 0;
}

