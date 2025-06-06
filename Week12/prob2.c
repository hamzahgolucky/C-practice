#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node Node;

struct Node 
{
	char *word;
	struct Node *left;
	struct Node *right;
};

Node *newNode(char *word)
{
	Node *x = malloc(sizeof(*x));
	x->word = strdup(word);
	x->left = 0;
	x->right = 0;
	return x;
}

int main()
{
    struct Node *l    = newNode("left");
    struct Node *r    = newNode("right");
    struct Node *root = newNode("root");
    root->left  = l;
    root->right = r;

    printf("%s\n", root->left->word);
    printf("%s\n", root->right->word);
    printf("%s\n", root->word);

    return 0;
}
