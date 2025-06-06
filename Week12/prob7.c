#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

int getword(char word[], int size) {
    int i = 0, c;

    while ((c = getchar()) != EOF && !isalpha(c))
        ;

    if (c == EOF) {
        return EOF;
    }
    word[i++] = c;
    while (i < size - 1 && (c = getchar()) != EOF && isalpha(c)) {
        word[i++] = c;
    }
    word[i] = '\0';

    return i;
}

#define indexableSize(A) (sizeof(A) / sizeof(*(A)))

int main() {
    Node *root = NULL;
    char word[100];

    while (getword(word, sizeof(word)) != EOF) {
        findNode(&root, word);
    }

    printTree(root);


    return 0;
}

