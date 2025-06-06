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

void printTree(Node *tree) {
	if (tree->left != 0)
	printTree(tree->left);
	
	printf("%s\n",tree->word);
	
	if (tree->right != 0)
	printTree(tree->right);
	
	
	return;
}

#define indexableSize(A) (sizeof(A) / sizeof(*(A)))

int main()
{
    Node *root = 0;

    char *words[] = {
	"Peter", "Piper", "picked", "a", "peck", "of", "picked", "pepper",
	"where", "is", "the", "peck", "that", "Peter", "Piper", "picked",
    };

    for (int i = 0;  i < indexableSize(words);  ++i)
	findNode(&root, words[i]);

    printTree(root);

    return 0;
}


