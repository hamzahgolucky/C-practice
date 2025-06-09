#include <stdio.h>
#include <stdlib.h>

#ifndef ELEMENT_T
# define ELEMENT_T int
#endif

struct Array
{
    size_t     size;      // number of elements in array
    ELEMENT_T *elements;  // storage for size elements
};

/* Return a new, empty array.
 */
struct Array *newArray(void)
{
    // size and elements are both initially 0
    return calloc(1, sizeof(struct Array));
}




void Array_clear(struct Array *array)
{
	free(array->elements);
	array->size = 0;
	array->elements = 0;
}

void Array_delete(struct Array *array)
{
	free(array);
}

ELEMENT_T Array_first(struct Array *array)
{
	if (0 == array->size) {
	fprintf(stderr, "no entries in array\n");
	exit(1);
    }
    return array->elements[0];
}

ELEMENT_T Array_last(struct Array *array)
{
	if (0 == array->size) {
	fprintf(stderr, "no entries in array\n");
	exit(1);
    }
    return array->elements[array->size - 1];
}



/* Return the number of elements in the array.
 */
size_t Array_size(struct Array *array)
{
    return array->size;
}

/* Append an element to the end of the array.
 */
void Array_addLast(struct Array *array, ELEMENT_T element)
{
    size_t lastIndex = array->size;
    size_t newSize   = lastIndex + 1;
    // if elements is 0, realloc will allocate the initial storage
    array->elements  = realloc(array->elements, sizeof(ELEMENT_T) * newSize);
    array->elements[lastIndex] = element;
    array->size = newSize;
}

/* Store the element into the array at the given index.
 * Print an error message and exit if the index is out of bounds.
 */
void Array_set(struct Array *array, size_t index, ELEMENT_T element)
{
    if (index >= array->size) {
	fprintf(stderr, "index %zi too large for array size %zi\n", index, array->size);
	exit(1);
    }
    array->elements[index] = element;
}

/* Return the element stored in array at the given index.
 * Print an error message and exit if the index is out of bounds.
 */
ELEMENT_T Array_get(struct Array *array, size_t index)
{
    if (index >= array->size) {
	fprintf(stderr, "index %zi too large for array size %zi\n", index, array->size);
	exit(1);
    }
    return array->elements[index];
}



#ifdef UNIT_TEST

#include <assert.h>

int main(int argc, char **argv)
{
    struct Array *array = newArray();

    for (int i = 0;  i < 10;  ++i) {
	assert(Array_size(array) == i);
	Array_addLast(array, i*i);
    }

    for (int i = 0;  i < 10;  ++i) {
	printf("%d\n", Array_get(array, i));
	assert(Array_get(array, i) == i*i);
    }

    printf("all tests passed\n");
    
    Array_clear(array);
    
    for (int i = 0;  i < 5;  ++i) {
	assert(Array_size(array) == i);
	Array_addLast(array, i*i);
    }
    
    for (int i = 0;  i < 5;  ++i) {
	printf("%d\n", Array_get(array, i));
	assert(Array_get(array, i) == i*i);
    }

    printf("all tests passed\n");
    
    printf("%d is the first element\n", Array_first(array));
    printf("%d is the last element\n", Array_last(array));

    return 0;
}

#endif

