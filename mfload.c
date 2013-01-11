#include "mfload.h"

MATRIX * load_matrix(char * filename)
{
	float value;
	char c;
	int row = 0, col = SIZE_LIMIT + 1, temp = 0;
	FILE * f;
	MATRIX * mptr;
	f = fopen(filename, "r+");
	while(!feof(f)){
		fscanf(f, "%f", &value);
		mptr->point[row][temp % col] = value;
		temp++;
	        c = fgetc(f);
		if ('\n' == c){
			row++;
			if (1 == row){
				col = temp;
				if (col > SIZE_LIMIT){
					perror("Size out of range");
				}
			}
		    
		}
		else if ('e' == c){
			
		}
	}
	printf("%d", num);


}
