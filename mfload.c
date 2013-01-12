#include "mfload.h"

MATRIX load_matrix(FILE * fp)
{
	float value;
	char c;
	int row = 0, col = SIZE_LIMIT + 1, temp = 0;
	MATRIX m;
	while(!feof(fp)){
		if(1 == fscanf(fp, "%f", &value)){
			m.point[row][temp % col] = value;
			temp++;
		}
	        c = fgetc(fp);
		if ('\n' == c){
			row++;
			if (1 == row){
				col = temp;
				if (col > SIZE_LIMIT){
					printf("Size out of range!");
					exit(1);
				}
			}
			if (row > SIZE_LIMIT){
				printf("Size out of range!");
				exit(1);
			}
		}
		else if ('e' == c){
			m.row = row;
			m.col = col;
			m.size = temp;
			printf("Matrix loaded, row: %d, col: %d\n", row, col);
			return m;
		}
	}
}
