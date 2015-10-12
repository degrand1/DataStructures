
#include "BitManipulation.h"
#include <iostream>

using namespace std;

int BM_SetBitIndexValuesOfNToM( int N, int M, int startIndex, int endIndex )
{
	//Flip all of the bits in N from startIndex to endIndex to be 0, then or them with the numbers from M
	int numBits = endIndex = startIndex + 1;
	int setDesiredBitsToZero = 1 << numBits;
	setDesiredBitsToZero--; // will result in numBits 1s
	setDesiredBitsToZero = setDesiredBitsToZero << startIndex; //move them to the right spot
	setDesiredBitsToZero = ~setDesiredBitsToZero; //flip them all to 0s with 1s in every other position
	N &= setDesiredBitsToZero;
	M = M << startIndex;
	N |= M;

	return N;
}

static void BM_PrintInBinary( int intPart, float decimalPart )
{
	int intPartArray[32];
	int intBitCount = 0;
	while( intPart >= 1 )
	{
		int remainder = intPart % 2;
		intPart = intPart >> 1;
		intPartArray[intBitCount] = remainder;
		intBitCount++;
	}
	int decimalBitCount = 0;
	int decimalPartArray[32];
	while( decimalPart > 0 )
	{
		if( decimalBitCount > 32 )
		{
			cout << "ERROR" << endl;
			return;
		}
		decimalPart *= 2;
		if( decimalPart >= 1 )
		{
			decimalPart--;
			decimalPartArray[decimalBitCount] = 1;
		}
		else
		{
			decimalPartArray[decimalBitCount] = 0;
		}
		decimalBitCount++;
	}
	for(int i = 0; i < intBitCount; i++ ) cout << intPartArray[i];
	cout << ".";
	for(int i = 0; i < decimalBitCount; i++ ) cout << decimalPartArray[i];
	cout << endl;
}

void BM_PrintStringInBinary( string value )
{
	int intPart = atoi( value.substr(0, value.find(".")).c_str() );
	float floatPart = stof( value.substr(value.find(".")) );
	BM_PrintInBinary( intPart, floatPart );
}