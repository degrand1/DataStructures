#include "GFG_Stacks.h"

#include "Stack.h"

static bool GFG_IsBST_GivenPreOrderTraversal( int* array, int n );
static int GFG_LongestSubstringParen( char* string, int length );

static void GFG_Test_PreorderTraversal()
{
	cout << "Testing preorder traversal" << endl;
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

static void GFG_Test_FindSubstringParen()
{
	cout << "Testing find substring of open and closed parentheses" << endl;
	char* char1 = "(((()";
	char* char2 = ")()())";
	char* char3 = "()(()))))";
	char* testResult1 = GFG_LongestSubstringParen( char1, 5 ) == 2 ? "Passed" : "Failed";
	char* testResult2 = GFG_LongestSubstringParen( char2, 6 ) == 4 ? "Passed" : "Failed";
	char* testResult3 = GFG_LongestSubstringParen( char3, 9 ) == 6 ? "Passed" : "Failed";
	cout << testResult1 << " test 1" << endl;
	cout << testResult2 << " test 2" << endl;
	cout << testResult3 << " test 3" << endl;
}

void GFG_Test_Stacks()
{
	GFG_Test_PreorderTraversal();
	GFG_Test_FindSubstringParen();
}

static int GFG_LongestSubstringParen( char* string, int length )
{
	Stack<int> subStringIndices;
	int result = 0;
	subStringIndices.Enqueue(-1);
	for(int i = 0; i < length; i++)
	{
		if( string[i] == '(' )
		{
			subStringIndices.Enqueue(i);
		}
		else if( string[i] == ')' )
		{
			delete subStringIndices.Dequeue();
			if( !subStringIndices.IsEmpty() )
			{
				int newLength = i - subStringIndices.Peek()->data;
				if( result < newLength) result = newLength;
			}
			else
			{
				subStringIndices.Enqueue(i);
			}
		}
	}
	return result;
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