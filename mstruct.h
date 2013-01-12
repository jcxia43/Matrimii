#include <stdio.h>


#define SIZE_LIMIT 100		/* The largest length of row/column */

#ifndef MATRIMII
#define MATRIMII
typedef struct matrix
{
	unsigned int size;	/* row  * col */
	unsigned int row;
	unsigned int col;
	float point[SIZE_LIMIT][SIZE_LIMIT];
}MATRIX;
#endif
