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

void Tree_applyPostOrder(struct Tree *tree, void (*fn)(ELEMENT_T e))
{
    if (0 == tree) return;
    Tree_applyPostOrder(tree->left,  fn);
    Tree_applyPostOrder(tree->right, fn);
    fn(tree->data);
}

void Tree_applyInOrder(struct Tree *tree, void (*fn)(ELEMENT_T e))
{
    if (0 == tree) return;
    Tree_applyInOrder(tree->left,  fn);
    fn(tree->data);
    Tree_applyInOrder(tree->right, fn);
}

struct Tree *Tree_search(struct Tree *tree, ELEMENT_T target) {
	if (tree == 0) return 0;
	else if (target == tree->data) return tree;
	if (target < tree->data) Tree_search(tree->left, target);
	else Tree_search(tree->right, target);
}

struct Tree *Tree_insert(struct Tree **treep, ELEMENT_T target) {
	if (*treep == 0) return (*treep) = newTree(target,0,0);
	else if (target == (*treep)->data) return *treep;
	if (target < (*treep)->data) Tree_insert(&(*treep)->left, target);
	else Tree_insert(&(*treep)->right, target);
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
    
    Tree_applyInOrder(t,printInt);
    putchar('\n');
    
    assert(t == Tree_search(t,4));
    assert(t->right == Tree_search(t,6));
    assert(0 == Tree_search(t,0));
    assert(0 == Tree_search(t,10));
    
    assert(Tree_insert(&t, 4) == t);
assert(Tree_insert(&t, 6) == t->right);
struct Tree *ta = Tree_insert(&t, 0);
assert(ta != 0);
struct Tree *tb = Tree_insert(&t, 10);
assert(tb != 0);
assert(Tree_insert(&t, 0) == ta);
assert(Tree_insert(&t, 10) == tb);
    
    printf("all tests passed!\n");

    return 0;
}

#endif
