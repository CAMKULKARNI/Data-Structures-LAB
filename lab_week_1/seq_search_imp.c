//Implementation for session1_seq_search.h

#include "ss.h"
#include <stdio.h>
//Search for the first occurrence of key in arr
//Returns the 0-based index of the first occurrence of key in arr on successful search.
//Otherwise, returns -1.
int seqsearch(int *arr, int n, int key)
{
	for (int i = 0; i < n; i++) //for loop runs for n iterations searching for the element
		if (*(arr + i) == key)	//checks if the element being searched is found or not
			return i;			//if found returns the 0-based index of the first occurence of the key in arr and exits the function
	return -1;					//returns -1 by default if the element being searched is not found
}
