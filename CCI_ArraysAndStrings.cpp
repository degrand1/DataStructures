#include "CCI_ArraysAndStrings.h"

#include <iostream>
using namespace std;

static void CCI_Test_Question1_1();
static void CCI_Test_Question1_2();
static void CCI_Test_Question1_3();
static void CCI_Test_Question1_4();
//Skippng Question 1_5 as it can be solved with the following algorithm:
//Loop through the string and count the number of white spaces
//Either reallocate the size of the string or allocate memory for a new string with the size = OriginalLength + 2*whiteSpaceCount + 1 for null terminator
//Loop backwards through the original string and copy values to the new part of the string, replacing whitespace with %20 as needed.
static void CCI_Test_Question1_6();
static void CCI_Test_Question1_7();
//Skipping Question 1_8 as it can be solved with the following algorithm:
//Allocate a new string that contains s1 printed twice. Return the result of isSubString( s2, doubledString );

static bool Question1_1_StringHasAllUniqueLetters( char* String, int Length );
static void Question1_2_ReverseString( char* String, int Length );
static void Question1_3_RemoveStringDuplicatesNoBuffer( char* String, int Length );
static bool Question1_4_AreStringsAnagrams( char* String1, int String1Length, char* String2, int String2Length );
static void Question1_6_RotateMatrix( int** Matrix, int N );
static void Question1_7_ZeroRowAndColumnContainingZero( int** Matrix, int M, int N );

void CCI_Test_ArraysAndStrings()
{
	CCI_Test_Question1_1();
	CCI_Test_Question1_2();
	CCI_Test_Question1_3();
	CCI_Test_Question1_4();
	CCI_Test_Question1_6();
	CCI_Test_Question1_7();
}

static int CCI_GetStringLength( char* String )
{
	if( String == NULL ) return 0;
	int count = 0;
	while( String[count] != '\0' ) count++;
	return count;
}

static bool CCI_AreStringsIdentical( char* String1, int String1Length, char* String2, int String2Length)
{
	if( String1Length != String2Length ) return false;
	for(int i = 0; i < String1Length; i++ )
	{
		if( String1[i] != String2[i] ) return false;
	}
	return true;
}

static void CCI_Test_Question1_1()
{
	char* UniqueCharacterString = "abcdefghijklmnopqrstuvwxyz";
	int UniqueCharacterLength = CCI_GetStringLength( UniqueCharacterString );
	char* NonUniqueCharacters = "Youknow";
	int NonUniqueCharacterLength = CCI_GetStringLength( NonUniqueCharacters );
	if( Question1_1_StringHasAllUniqueLetters( UniqueCharacterString, UniqueCharacterLength ) )
		cout << "Passed determining that a unique string is unique" << endl;
	else
		cout << "Failed determining that a unique string is unique" << endl;
	if( !Question1_1_StringHasAllUniqueLetters( NonUniqueCharacters, NonUniqueCharacterLength ) )
		cout << "Passed determining that a non-unique string is not unique" << endl;
	else
		cout << "Failed determing that a non-unique string is not unique" << endl;
}

static bool Question1_1_StringHasAllUniqueLetters( char* String, int Length )
{
	//Because this is English, we know there can only be 26 possible characters
	int letterCount[26];
	for( int i = 0; i < 26; i++) letterCount[i] = 0;
	for( int i = 0; i < Length; i++ )
	{
		int currentLetterIndex = (int)String[i];
		bool IsUpperCase = currentLetterIndex >= 'A' && currentLetterIndex <= 'Z';
		bool IsLowerCase = currentLetterIndex >= 'a' && currentLetterIndex <= 'z';
		if( IsUpperCase )      currentLetterIndex -= 'A';
		else if( IsLowerCase ) currentLetterIndex -= 'a';
		else
		{
			cout << "Got a character that is not a letter of the alphabet. This function will need to be changed to handle that case." << endl;
			return false;
		}
		if( currentLetterIndex < 0 || currentLetterIndex >= 26 )
		{
			cout << "Sanity check failed. Somehow the letter " << String[i] << " broke the system." << endl;
			return false;
		}
		if( letterCount[currentLetterIndex] != 0 )
			return false;
		else
			letterCount[currentLetterIndex]++;
	}
	return true;
}

static void CCI_Test_Question1_2()
{
	const int OddStringLength = 6;
	char OddString[OddStringLength] = "abcde";
	const int EvenStringLength = 5;
	char EvenString[EvenStringLength] = "abcd";
	cout << "The odd string: " << OddString << " reversed is: ";
	Question1_2_ReverseString( OddString, OddStringLength );
	cout << OddString << endl;

	cout << "The odd string: " << EvenString << " reversed is: ";
	Question1_2_ReverseString( EvenString, EvenStringLength );
	cout << EvenString << endl;
}

static void Question1_2_ReverseString( char* String, int Length )
{
	Length--; //Let's not count the null terminator
	int numIterations = Length >> 1;
	int lastStringIndex = Length -1;
	for(int i = 0; i < numIterations; i++ )
	{
		char temp = String[i];
		String[i] = String[lastStringIndex];
		String[lastStringIndex] = temp;
		lastStringIndex--;
	}
}

static void CCI_Test_Question1_3()
{
	char* Test1 = NULL;
	const int Test2Length = 2;
	char Test2[Test2Length] = "a";
	const int Test3Length = 6;
	char Test3[Test3Length] = "abcde";
	int Test4Length = 7;
	char Test4[7] = "aaaaaa";
	int Test5Length = 8;
	char Test5[8] = "aaabbba";
	Question1_3_RemoveStringDuplicatesNoBuffer(Test1, 0);
	Question1_3_RemoveStringDuplicatesNoBuffer(Test2, Test2Length);
	Question1_3_RemoveStringDuplicatesNoBuffer(Test3, Test3Length);
	Question1_3_RemoveStringDuplicatesNoBuffer(Test4, Test4Length);
	Question1_3_RemoveStringDuplicatesNoBuffer(Test5, Test5Length);
	//Update the lengths for test4 and 5 since they changed
	Test4Length = CCI_GetStringLength( Test4 )+1;
	Test5Length = CCI_GetStringLength( Test5 )+1;
	char* Test1Result = Test1 == NULL ? "Passed" : "Failed";
	char* Test2Result = CCI_AreStringsIdentical( Test2, Test2Length, "a"    , 2 ) ? "Passed" : "Failed";
	char* Test3Result = CCI_AreStringsIdentical( Test3, Test3Length, "abcde", 6 ) ? "Passed" : "Failed";
	char* Test4Result = CCI_AreStringsIdentical( Test4, Test4Length, "a"    , 2 ) ? "Passed" : "Failed";
	char* Test5Result = CCI_AreStringsIdentical( Test5, Test5Length, "ab"   , 3 ) ? "Passed" : "Failed";
	cout << Test1Result << " test 1, find duplicates in a null string." << endl;
	cout << Test2Result << " test 2, find duplicates in a single letter." << endl;
	cout << Test3Result << " test 3, find duplicates in a string with no duplicates." << endl;
	cout << Test4Result << " test 4, find duplicates in a string with all duplicates." << endl;
	cout << Test5Result << " test 5, find duplicates in a string with repeating duplicates." << endl;
}

static void Question1_3_RemoveStringDuplicatesNoBuffer( char* String, int Length )
{
	if( String == NULL ) return;
	if( Length < 2 ) return;

	int numIterations = Length - 1; //Let's not count the null terminator
	int tail = 1; //The current end of the string
	for( int i = 1; i < numIterations; i++ )
	{
		int j;
		for( j = 0; j < tail; j++ )
		{
			//Found a duplicate. Breaking here prevents the tail from advancing
			if( String[i] == String[j] ) break;
		}
		if( j == tail )
		{
			//Made it all the way to the end of the string without finding a duplicate. Advance the tail.
			String[tail] = String[i];
			tail++;
		}
	}
	String[tail] = '\0';
}

static void CCI_Test_Question1_4()
{
	char* Test1String1 = "cinema";
	int Test1String1Length = CCI_GetStringLength( Test1String1 );
	char* Test1String2 = "iceman";
	int Test1String2Length = CCI_GetStringLength( Test1String2 );
	char* Test2String1 = "cinemas";
	int Test2String1Length = CCI_GetStringLength( Test2String1 );
	char* Test2String2 = "icemens";
	int Test2String2Length = CCI_GetStringLength( Test2String2 );
	char* Test3String1 = "blah";
	int Test3String1Length = CCI_GetStringLength( Test3String1 );
	char* Test3String2 = "blahs";
	int Test3String2Length = CCI_GetStringLength( Test3String2 );
	char* Test1Result =  Question1_4_AreStringsAnagrams( Test1String1, Test1String1Length, Test1String2, Test1String2Length ) ? "Passed" : "Failed";
	char* Test2Result = !Question1_4_AreStringsAnagrams( Test2String1, Test2String1Length, Test2String2, Test2String2Length ) ? "Passed" : "Failed";
	char* Test3Result = !Question1_4_AreStringsAnagrams( Test3String1, Test3String1Length, Test3String2, Test3String2Length ) ? "Passed" : "Failed";
	cout << Test1Result << " test 1, determining if an anagram is an anagram." << endl;
	cout << Test2Result << " test 2, determining that a non-anagram is not an anagram." << endl;
	cout << Test3Result << " test 3, determining that strings of different lengths are not anagrams." << endl;
}

static bool Question1_4_AreStringsAnagrams( char* String1, int String1Length, char* String2, int String2Length )
{
	if( String1Length != String2Length ) return false;

	//Because this is English, we know there can only be 26 possible characters
	int letterCount[26];
	for( int i = 0; i < 26; i++) letterCount[i] = 0;
	//Count up all the letters in the first string
	for( int i = 0; i < String1Length; i++ )
	{
		int currentLetterIndex = (int)String1[i];
		bool IsUpperCase = currentLetterIndex >= 'A' && currentLetterIndex <= 'Z';
		bool IsLowerCase = currentLetterIndex >= 'a' && currentLetterIndex <= 'z';
		if( IsUpperCase )      currentLetterIndex -= 'A';
		else if( IsLowerCase ) currentLetterIndex -= 'a';
		else
		{
			cout << "Got a character that is not a letter of the alphabet. This function will need to be changed to handle that case." << endl;
			return false;
		}
		if( currentLetterIndex < 0 || currentLetterIndex >= 26 )
		{
			cout << "Sanity check failed. Somehow the letter " << String1[i] << " broke the system." << endl;
			return false;
		}
		letterCount[currentLetterIndex]++;
	}

	//Subtract them from the second. We hit the failure case if we see X number of letters in the second string that do not occur in the first
	for( int i = 0; i < String2Length; i++ )
	{
		int currentLetterIndex = (int)String2[i];
		bool IsUpperCase = currentLetterIndex >= 'A' && currentLetterIndex <= 'Z';
		bool IsLowerCase = currentLetterIndex >= 'a' && currentLetterIndex <= 'z';
		if( IsUpperCase )      currentLetterIndex -= 'A';
		else if( IsLowerCase ) currentLetterIndex -= 'a';
		else
		{
			cout << "Got a character that is not a letter of the alphabet. This function will need to be changed to handle that case." << endl;
			return false;
		}
		if( currentLetterIndex < 0 || currentLetterIndex >= 26 )
		{
			cout << "Sanity check failed. Somehow the letter " << String2[i] << " broke the system." << endl;
			return false;
		}
		letterCount[currentLetterIndex]--;
		if( letterCount[currentLetterIndex] < 0 ) return false;
	}

	return true;
}

static void CCI_Test_Question1_6()
{
	int n = 2;
	int** TwoByTwoArray = new int*[n];
	for(int i = 0; i < n; i++ )
		TwoByTwoArray[i] = new int[n];
	for( int i = 0; i < n*n; i++ )
	{
		int y = i / n;
		int x = i % n;
		TwoByTwoArray[y][x] = i+1;
	}
	int TwoByTwoArrayRotated[2][2] = { { 2, 4 }, { 1, 3 } };
	Question1_6_RotateMatrix( TwoByTwoArray, 2 );
	bool PassedTest1 = true;
	for(int y = 0; y < n; y++ )
	{
		for( int x = 0; x < n; x++ )
		{
			if( TwoByTwoArray[y][x] != TwoByTwoArrayRotated[y][x] )
			{
				PassedTest1 = false;
				break;
			}
		}
	}

	for( int i = 0; i < n; i++ )
		delete [] TwoByTwoArray[i];
	delete [] TwoByTwoArray;

	n = 3;
	int** ThreeByThreeArray = new int*[n];
	for(int i = 0; i < n; i++ )
		ThreeByThreeArray[i] = new int[n];
	for( int i = 0; i < n*n; i++ )
	{
		int y = i / n;
		int x = i % n;
		ThreeByThreeArray[y][x] = i+1;
	}

	int ThreeByThreeArrayRotated[3][3] = { { 3, 6, 9 }, { 2, 5, 8 }, { 1, 4 , 7 } };
	Question1_6_RotateMatrix( ThreeByThreeArray, 3 );
	bool PassedTest2= true;
	for(int y = 0; y < n; y++ )
	{
		for( int x = 0; x < n; x++ )
		{
			if( ThreeByThreeArray[y][x] != ThreeByThreeArrayRotated[y][x] )
			{
				PassedTest2 = false;
				break;
			}
		}
	}

	for( int i = 0; i < n; i++ )
		delete [] ThreeByThreeArray[i];
	delete [] ThreeByThreeArray;

	char* Test1Result = PassedTest1 ? "Passed" : "Failed";
	char* Test2Result = PassedTest2 ? "Passed" : "Failed";
	cout << Test1Result << " test 1, rotate a 2x2 matrix" << endl;
	cout << Test2Result << " test 2, rotate a 3x3 matrix" << endl;
}

static void Question1_6_RotateMatrix( int** Matrix, int N )
{
	int numIterations = N >> 1;
	for( int layer = 0; layer < numIterations; layer++ )
	{
		int first = layer;
		int last = N - layer - 1;
		for( int i = first; i < last; i++ )
		{
			int offset = i - first;
			int topLeft = Matrix[i][first];
			Matrix[i][first] = Matrix[first][last-offset];
			Matrix[first][last-offset] = Matrix[last-offset][last];
			Matrix[last-offset][last] = Matrix[last][i];
			Matrix[last][i] = topLeft;
		}
	}
}

static void CCI_Test_Question1_7()
{
	int m = 3;
	int n = 2;
	int** ThreeByTwoArray = new int*[m];
	for(int i = 0; i < m; i++ )
		ThreeByTwoArray[i] = new int[n];
	for( int i = 0; i < m*n; i++ )
	{
		int y = i / n;
		int x = i % n;
		ThreeByTwoArray[y][x] = i+1;
	}
	ThreeByTwoArray[1][1] = 0;
	int ThreeByTwoArrayZeroedOut[3][2] = { { 1, 0 }, { 0, 0 }, { 5, 0 } };
	Question1_7_ZeroRowAndColumnContainingZero( ThreeByTwoArray, 3, 2 );
	bool PassedTest1 = true;
	for(int y = 0; y < m; y++ )
	{
		for( int x = 0; x < n; x++ )
		{
			if( ThreeByTwoArray[y][x] != ThreeByTwoArrayZeroedOut[y][x] )
			{
				PassedTest1 = false;
				break;
			}
		}
	}

	for( int i = 0; i < m; i++ )
		delete [] ThreeByTwoArray[i];
	delete [] ThreeByTwoArray;

	char* Test1Result = PassedTest1 ? "Passed" : "Failed";
	cout << Test1Result << " test 1, zero out a 3x2 matrix" << endl;
}

static void Question1_7_ZeroRowAndColumnContainingZero( int** Matrix, int M, int N )
{
	int* rows = new int[M];
	int* columns = new int[N];
	for( int i = 0; i < M; i++ ) rows[i] = 0;
	for( int i = 0; i < N; i++ ) columns[i] = 0;

	for( int y = 0; y < M; y++ )
	{
		for( int x = 0; x < N; x++ )
		{
			if( Matrix[y][x] == 0 )
			{
				rows[y] = 1;
				columns[x] = 1;
			}
		}
	}

	for( int y = 0; y < M; y++ )
	{
		for( int x = 0; x < N; x++ )
		{
			if( rows[y] == 1 || columns[x] == 1 )
				Matrix[y][x] = 0;
		}
	}

	delete [] rows;
	delete [] columns;
}