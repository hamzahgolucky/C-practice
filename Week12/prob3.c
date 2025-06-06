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

Node *findNode(Node *tree, char *word)
{
	if (tree == NULL || strcmp(tree->word, word) == 0) {
        return tree;
    }
    
	if (strcmp(word, tree->word) < 0) {
        return findNode(tree->left, word);
    }
    
	return findNode(tree->right, word);
}

int main()
{
    struct Node *l    = newNode("left");
    struct Node *r    = newNode("right");
    struct Node *root = newNode("middle");
    root->left  = l;
    root->right = r;

    printf("%s\n", findNode(root,   "left")->word);
    printf("%s\n", findNode(root, "middle")->word);
    printf("%s\n", findNode(root,  "right")->word);
    printf("%p\n", findNode(root,   "none")      );

    return 0;
}
