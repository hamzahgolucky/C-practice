#include <stdio.h>

int main()
{
    int i;

    // do loop

    i = 0;
    do {
	if (i == 3) continue;
	printf("%2d", i);
    } while (i++ < 5);
    printf("\n");

    // do loop using labels and goto

    i = 0;
  doBody:
    if (i == 3) goto doTest;
    printf("%2d", i);
  doTest:
    if (i++ < 5) goto doBody;
    printf("\n");




    // while loop

    i = 0;
    while (i++ < 5) {
	if (i == 3) continue;
	printf("%2d", i);
    }
    printf("\n");

    // while loop using labels and goto

    i = 0;
    dotest:
    	if (i++ < 5) goto dothing;
    	else goto getout;
    dothing:
    	if (i == 3) goto dotest;
    	printf("%2d",i);
    	goto dotest;
    getout:
    	printf("\n");




    // for loop

    for (i = 0;  i < 5;  ++i) {
	if (i == 3) continue;
	printf("%2d", i);
	if (i == 4) break;
    }
    printf("\n");

    // for loop using labels and goto

    i = 0;
    dothing2:
    	if (i < 5)
    	{
    		if (i == 3) goto dochanges;
    		printf("%2d",i);
    	}
    	else goto getout2;
    dochanges:
    	i++;
    	goto dothing2;
    getout2:
    	printf("\n");
    	

    return 0;
}

