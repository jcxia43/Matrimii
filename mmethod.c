#include "mmethod.h"
float get_value(MATRIX m, unsigned int row, unsigned int col)
{
	row--;			/*index starts from 0 and mind starts from 1 */
	col--;
	if (row > m.row || col > m.col){
		printf("Matrix query out of range! Trying to query(%d, %d), but matrix only has %d rows and %d cols", row, col, m.row, m.col);
		exit(1);
	}
	return m.point[col][row];

}


void print_matrix(MATRIX m)
{
	unsigned int i = 0;
	unsigned int n = 0;
	printf("Matrix has %d rows and %d cols\n", m.row, m.col);
	for (; i < m.row; ++i){
		for (n = 0; n < m.col; ++n){
			printf("%-10.3f", m.point[i][n]);
		}
		printf("\n");
	}
}

MATRIX add(MATRIX a, MATRIX b, int coa, int cob)
{
	MATRIX result;
	unsigned int i;
	unsigned int n;
	if (a.row != b.row || a.col != b.col){
		printf("add error, different size!");
		exit(1);
	}
	else{
		result.row = a.row;
		result.col = a.col;
		result.size = a.size;
		for (i = 0; i < a.row; ++i){
			for (n = 0; n < a.col; ++n){
				result.point[i][n] = a.point[i][n] * coa + b.point[i][n] * cob;
			}
		}
		return result;
	}

}

MATRIX get_transpose(MATRIX m)
{
	MATRIX result;
	unsigned int i;
	unsigned int n;
	
	result.size = m.size;
	result.row = m.col;
	result.col = m.row;
	
	for (i = 0; i < m.row; ++i){
		for (n = 0; n < m.col; ++n){
			result.point[n][i] = m.point[i][n];
		}
	}
	return result;
}

MATRIX multiply(MATRIX a, MATRIX b)
{
	MATRIX result;
	unsigned int i, n, p;
	float temp;
	if (a.col != b.row){
		printf("Multiply error, a's row not equal to b's column");
		exit(1);
	}
	result.row = a.row;
	result.col = b.col;
	result.size = a.row * b.col;
	for (i = 0; i < result.row; ++i){
		for (n = 0; n < result.col; ++n){
			temp = 0;
			for (p = 0; p < a.col; ++p){
				temp += a.point[i][p] * b.point[p][n];
			}
			result.point[i][n] = temp;
		}
	}
	return result;
}
