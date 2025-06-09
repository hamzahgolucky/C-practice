#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <sys/time.h>


int millis(void)
{
struct timeval tv;
static unsigned long epoch = 0;
gettimeofday(&tv, 0);
if (!epoch) epoch = tv.tv_sec * 1000L + tv.tv_usec / 1000;
return tv.tv_sec * 1000L + tv.tv_usec / 1000 - epoch;
}

int bubbleSort(int array[], int left, int right)
{
	int t1=millis();
	while (right>left) {
		for (int i=0;i<right;i++) {
			if (array[i] > array[i+1]) {
				int temp = array[i];
				array[i] = array[i+1];
				array[i+1] = temp;
			}
		}
		right--;
	}
	int t2=millis();
	return t2-t1;
}

int selectionSort(int array[], int left, int right)
{
	int t1=millis();
	while (right>left) {
		int minIndex=left;
		for (int i=left+1;i<right+1;i++) {
			if (array[i] < array[minIndex]) {
				minIndex = i;
			}
		}
		int temp = array[left];
		array[left] = array[minIndex];
		array[minIndex] = temp;
		left++;
	}
	int t2=millis();
	return t2-t1;
}

int insertionSort(int array[], int left, int right)
{
	int t1=millis();
	for (int i=left+1;i<right+1;i++) {
		for (int j=i;j>left;j--) {
			if (array[j-1] <= array[j]) {
				break;
			}
			int temp = array[j-1];
			array[j-1] = array[j];
			array[j] = temp;
		}
	}
	int t2=millis();
	return t2-t1;
}

void quickSort(int array[], int left, int right)
{
}

void fill(int array[], int left, int right)
{
    for (int i = left;  i <= right;  ++i)
	array[i] = rand() & 4095; // random number in the range [0..4095]
}

#define NMAX 2000 // increase to maximum required number of elements in the array

int main(int argc, char **argv)
{
    for (int j=0;j<21;j++) {
    
		int array[NMAX*j];

		
		fill(array, 0, NMAX*j - 1);
		int b = bubbleSort(array, 0, NMAX*j - 1);

		
		fill(array, 0, NMAX*j - 1);
		int s = selectionSort(array, 0, NMAX*j - 1);


		fill(array, 0, NMAX*j - 1);
		int i = insertionSort(array, 0, NMAX*j - 1);

		
		printf("%d,%d,%d,%d\n",j,b,s,i);
		
	}

    

    puts("all tests passed");

    return 0;
}

