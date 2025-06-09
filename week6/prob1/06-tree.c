#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifdef TEST_TREE // defined if we are compiling the unit tests
# define ELEMENT_T int
#endif

#ifndef ELEMENT_T // the client program forgot to say what the element type is
# error "Tree: ELEMENT_T is not defined"
#endif

struct Tree {
    ELEMENT_T    data;   // the element stored in this node
    struct Tree *left;   // pointer to left sub-tree, or 0 if none
    struct Tree *right;  // pointer to right sub-tree, or 0 if none
};

struct Tree *newTree(ELEMENT_T e, struct Tree *left, struct Tree *right)
{
    struct Tree *tree = malloc(sizeof(*tree));
    tree->data  = e;
    tree->left  = left;
    tree->right = right;
    return tree;
}

void Tree_applyPreOrder(struct Tree *tree, void (*fn)(ELEMENT_T e))
{
    if (0 == tree) return;
    fn(tree->data);
    Tree_applyPreOrder(tree->left,  fn);
    Tree_applyPreOrder(tree->right, fn);
}

#ifdef TEST_TREE

void printInt(int i)
{
    printf(" %i", i);
}

int main(int argc, char **argv)
{
    struct Tree *t = newTree(4,
			     newTree(2,
			     	newTree(1,0,0), newTree(3, 0, 0)),
			     newTree(6, 
			     	newTree(5, 0, 0), newTree(7, 0, 0)));

    Tree_applyPreOrder(t, printInt);
    putchar('\n');
    
    assert(t != 0);
    assert(t->data == 4);
    assert(t->left != 0);
    assert(t->left->data == 2);
    assert(t->left->left != 0);
    assert(t->left->left->data == 1);


    return 0;
}

#endif
