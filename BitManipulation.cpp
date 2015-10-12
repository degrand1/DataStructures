
#include "BitManipulation.h"
#include <limits.h>

int BM_SetBitIndexValuesOfNToM( int N, int M, int startIndex, int endIndex )
{
	int numIterations = endIndex - startIndex + 1;
	for( int i = 0; i < numIterations; i++ )
	{
		int ValueOfM = M << 31 - i;
		ValueOfM = ValueOfM >> 31;
		int shiftedValue = 1 << (startIndex + i );;
		if( ValueOfM == 0 )
		{
			shiftedValue = INT_MAX - shiftedValue;
			N = N & shiftedValue;
		}
		else
		{
			N = N | shiftedValue;
		}
	}
	return N;
}