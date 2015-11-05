#ifndef BITMANIPULATION_H
#define BITMANIPULATION_H
	#include <string>

	int BM_SetBitIndexValuesOfNToM( int N, int M, int startIndex, int endIndex );
	void BM_PrintStringInBinary( std::string value );
	int BM_NumBitsThatAreDifferent( int A, int B );
	int BM_SwapEvenOddBits( int value );
#endif