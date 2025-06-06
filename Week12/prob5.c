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

Node *findNode(Node **treep, char *word)
{
	Node *tree = *treep;
	if (tree == 0) {
	*treep = newNode(word);
	return *treep;
	}
	if (strcmp(tree->word, word) == 0) {
        return tree;
    	}
    
	if (strcmp(word, tree->word) < 0) {
        return findNode(&tree->left, word);
    	}
    	
    	if (strcmp(word, tree->word) > 0) {
	return findNode(&tree->right, word);
	}
}

int main()
{
    struct Node *root = 0;
    findNode(&root, "middle");
    findNode(&root, "left");
    findNode(&root, "right");

    printf("%s\n", findNode(&root,   "left")->word);
    printf("%s\n", findNode(&root, "middle")->word);
    printf("%s\n", findNode(&root,  "right")->word);

    return 0;
}

