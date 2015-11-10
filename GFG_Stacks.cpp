#include "GFG_Stacks.h"

#include "Stack.h"

static bool GFG_IsBST_GivenPreOrderTraversal( int* array, int n );

void GFG_Test_Stacks()
{
	int test1[3] = {2, 4, 3};
	int test2[3] = {2, 4, 1};
	int test3[5] = {40, 30, 35, 80, 100};
	int test4[6] = {40, 30, 35, 20, 80, 100};
	char* test1Result = GFG_IsBST_GivenPreOrderTraversal( test1, 3 ) ? "Passed" : "Failed";
	char* test2Result = !GFG_IsBST_GivenPreOrderTraversal( test2, 3 ) ? "Passed" : "Failed";
	char* test3Result = GFG_IsBST_GivenPreOrderTraversal( test3, 5 ) ? "Passed" : "Failed";
	char* test4Result = !GFG_IsBST_GivenPreOrderTraversal( test4, 6 ) ? "Passed" : "Failed";
	cout << test1Result << " test 1" << endl;
	cout << test2Result << " test 2" << endl;
	cout << test3Result << " test 3" << endl;
	cout << test4Result << " test 4" << endl;

}

static bool GFG_IsBST_GivenPreOrderTraversal( int* array, int n )
{
	Stack<int> parents;
	int prevMin;
	bool prevMinInitialised = false;
	//Continue pushing parents onto the stack until we discover a right subtree
	//If a right subtree is discovered, pop all the left nodes off the stack onto the array until the stack is empty or we find a parent of the right subtree
	for(int i = 0; i < n; i++)
	{
		if( parents.IsEmpty() || parents.Peek()->data > array[i] )
		{
			parents.Enqueue(array[i]);
		}
		else //right subtree discovered
		{
			while( !parents.IsEmpty() && parents.Peek()->data < array[i] )
			{
				int Value = parents.Dequeue()->data;
				//Test to see that the resulting array is sorted
				if( prevMinInitialised && prevMin > Value )
				{
					return false;
				}
				prevMinInitialised = true;
				prevMin = Value;
			}
			parents.Enqueue(array[i]);
		}
	}
	//Put all of the remaining parents into our array
	while( !parents.IsEmpty() ) { 
		int Value = parents.Dequeue()->data;
		//Test to see that the resulting array is sorted
		if( prevMinInitialised && prevMin > Value )
		{
			return false;
		}
		prevMinInitialised = true;
		prevMin = Value;
	}
	
	return true;
}