#include <stdio.h>

void swap(int * a, int * b);
void printarr(int * arr,int size);
void quicksort(int * arr,int start,int end,int size);

void main() {

	printf("hello C world!\n");
	printf("Quick sort\n\n");

	int arr[] = {34,27,35,1,23,19,85,67,4,10};
	
	printarr(arr,sizeof(arr)/4);
	printf("\n\n");
	quicksort(arr,0,sizeof(arr)/4 -1,sizeof(arr)/4);

	printarr(arr,sizeof(arr)/4);

}

void quicksort(int * arr,int start,int end,int size)
{
	
	int pivot = arr[start];
	int left = start+1;
	int right = end;

	if(start == end)
	{
		printf("start = end = %d\n",start);
		printarr(arr,size);
		printf("\n");
	}

		while(start<end)
		{
			while(arr[left]<pivot)
			{
				left++;
			}
			while(arr[right]>pivot)
			{
				right--;
			}
			if(left<right)
			{
				swap(&arr[left],&arr[right]);
				printf("left = %d, right = %d\n",left,right);
				printarr(arr,size);
			}
			else
			{
				swap(&arr[start],&arr[right]);
				printf("left = %d, right = %d\n",left,right);
				printarr(arr,size);
				printf("\n");
				quicksort(arr,start,right-1,size);
				quicksort(arr,left,end,size);
				break;
			}

		}

}

void swap(int * a, int * b)
{
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;

}

void printarr(int * arr, int size)
{
	printf("arr = {");
	for(int i = 0; i<size; i++)
	{
		printf(" %d ",arr[i]);
	}
	printf("}\n");
}

