#include "CCI_AdditionalReview.h"

#include <iostream>

using namespace std;

enum Colors {
	NO_COLOR = -1,
	YELLOW = 0,
	RED = 1,
	GREEN = 2,
	BLUE = 3
};

static Colors GetColorFromCharacter( char Value )
{
	Colors currentColor;
	switch( Value )
	{
	case 'Y':
	case 'y':
		currentColor = YELLOW;
		break;
	case 'R':
	case 'r':
		currentColor = RED;
		break;
	case 'G':
	case 'g':
		currentColor = GREEN;
		break;
	case 'B':
	case 'b':
		currentColor = BLUE;
		break;
	default:
		cout << "Got unexpected value: " << Value << endl;
		return NO_COLOR;
	}
	return currentColor;
}

static void GetHitsInGuess( char* Guess, char* Solution, int length, int* Hits, int* PsuedoHits )
{
	if( Hits == NULL || PsuedoHits == NULL || length < 1 ) return;
	*Hits = 0;
	*PsuedoHits = 0;
	int numColors[4] = {0, 0, 0, 0};
	int numReds, numYellows, numGreens, numBlues;
	numReds = numYellows = numGreens = numBlues = 0;

	//Iterate through the solution and count the number of colors
	for(int i = 0; i < length; i++ )
	{
		Colors currentColor = GetColorFromCharacter(Solution[i]);
		if( currentColor != NO_COLOR )
			numColors[(int)currentColor]++;
	}

	//If a color is correct, increment the hits. For psuedo hits, decrement the total of known values in that color
	for(int i = 0; i < length; i++ )
	{
		Colors currentColor = GetColorFromCharacter(Guess[i]);
		if( Guess[i] == Solution[i] )
		{
			*Hits+=1;
		}
		else if( numColors[(int)currentColor] > 0 )
		{
			*PsuedoHits+=1;
			numColors[(int)currentColor]--;
		}
	}
}

static void CCI_Test_HitsInGuess()
{
	char* Guess = "YRGB";
	char* Solution = "RGGB";
	int Hits = 0;
	int PsuedoHits = 0;
	GetHitsInGuess( Guess, Solution, 4, &Hits, &PsuedoHits );
	char* test1Result = Hits == 2 && PsuedoHits == 1 ? "Passed" : "Failed";
	cout << test1Result << " test1 for getting the number of hits." << endl;
}

void CCI_Test_AdditionalReview()
{
	CCI_Test_HitsInGuess();
}
