#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX(x, y) ((x) > (y) ? (x) : (y))

char *rot13(char *s)
{
    int i = 0;
    while (*(s+i) != '\0')
    {
        if (*(s+i) >= 'a' && *(s+i) <= 'z')
        {
            *(s+i) = ((*(s+i) - 'a' + 13) % 26) + 'a';
        }
        else if (*(s+i) >= 'A' && *(s+i) <= 'Z')
        {
            *(s+i) = ((*(s+i) - 'A' + 13) % 26) + 'A';
        }
        i++;
    }
    return s;
}

int main()
{
    char s[] =
	"Fvzcyvpvgl naq ryrtnapr ner hacbchyne orpnhfr gurl erdhver uneq jbex naq "
	"qvfpvcyvar gb npuvrir naq rqhpngvba gb or nccerpvngrq. -- Rqftre Qvwxfgen";
    printf("%s\n", rot13(s));
    return 0;
}

