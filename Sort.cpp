#include "Sort.h"

static void MergeSortCombine( int* array, int start, int middle, int end, int* workArray )
{
	int leftIndex = start, rightIndex = middle;
	for(int i = start; i < end; i++ )
	{
		if( leftIndex < middle && ( rightIndex >= end || array[leftIndex] <= array[rightIndex] ) )
		{
			workArray[i] = array[leftIndex];
			leftIndex++;
		}
		else
		{
			workArray[i] = array[rightIndex];
			rightIndex++;
		}
	}
}

static void MergeSortSplit( int* array, int start, int end, int* workArray )
{
	if( end - start < 2 ) //if there's only one item in the list, then it's already sorted
		return;
	int middle = (start + end) / 2.0f;
	MergeSortSplit( array, start, middle, workArray );
	MergeSortSplit( array, middle, end, workArray );
	MergeSortCombine( array, start, middle, end, workArray );
	for( int i = start; i < end; i++ )
		array[i] = workArray[i];
}

void MergeSort( int* array, int n )
{
	int* workArray = new int[n];
	MergeSortSplit( array, 0, n, workArray );
	delete[] workArray;
}

static void SwapValues( int* array, int firstIndex, int secondIndex )
{
	int temp = array[firstIndex];
	array[firstIndex] = array[secondIndex];
	array[secondIndex] = temp;
}

static int QuickSortPartition( int* array, int start, int end )
{
	int pivot = array[end];
	int swapIndex = start; //start off assuming the pivot belongs at the beginning of the array
	for( int i = start; i < end; i++ )
	{
		if( array[i] <= pivot) //turns out the pivot needs to be one spot forward
		{
			SwapValues( array, i, swapIndex); //This swap will push bigger elements to the right since the gap between i and swap index represents how many elements are bigger than the pivot
			swapIndex++;
		}
	}
	SwapValues( array, swapIndex, end );
	return swapIndex;
}

static void QuickSortHelper( int* array, int start, int end )
{
	if( start < end )
	{
		int p = QuickSortPartition( array, start, end );
		QuickSortHelper( array, start, p - 1 );
		QuickSortHelper( array, p+1, end );
	}
}

void QuickSort( int* array, int n )
{
	QuickSortHelper( array, 0, n-1 );
}