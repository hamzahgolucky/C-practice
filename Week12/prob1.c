#include <stdlib.h>
#include <stdio.h>

typedef struct Node Node;

struct Node 
{
	char *word;
	struct Node *left;
	struct Node *right;
};

int main()
{
    struct Node l = {  "left",  0,  0 };
    struct Node r = { "right",  0,  0 };
    struct Node n = {  "root", &l, &r };
    struct Node *root = &n;

    printf("%s\n", root->left->word);
    printf("%s\n", root->right->word);
    printf("%s\n", root->word);

    return 0;
}
