#include <stdio.h>


#define SIZE_LIMIT 100		/* The largest length of row/column */


typedef struct matrix
{
	unsigned int size;	/* row  * col */
	unsigned int row;
	unsigned int col;
	int rank;
	double point[SIZE_LIMIT][SIZE_LIMIT];
}MATRIX;
