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
	unsigned int i, n;
	printf("Matrix has %d rows and %d cols\n", m.row, m.col);
	for (i = 0; i < m.row; ++i){
		for (n = 0; n < m.col; ++n){
			printf("%-10.3f", m.point[i][n]);
		}
		printf("\n");
	}
}

MATRIX add(MATRIX a, MATRIX b, int coa, int cob)
{
	MATRIX result;
	unsigned int i, n;
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
	unsigned int i, n;
	
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

void multiply_co(MATRIX * m, float a)
{
	unsigned int i, n;
	for (i = 0; i < m->row; ++i){
		for (n = 0; n < m->col; ++n){
			m->point[i][n] *= a;
		}
	}
}
/* fill matrix with zeros */
void clear(MATRIX *m)
{
	unsigned int i, n;
	for (i = 0; i < m->row; ++i){
		for (n = 0; n < m->col; ++n){
			m->point[i][n] = 0.0;
		}
	}
}


MATRIX * unity(unsigned int order)
{
	unsigned int i, n;
	MATRIX * p = (MATRIX *)malloc(sizeof(MATRIX));
	if (order > SIZE_LIMIT){
		printf("Size out of range, when constructing unity matrix!");
		exit(1);
	}
	p->row = order;
	p->col = order;
	p->size = order * order;
	clear(p);
	for (i = 0; i < order; ++i){
		p->point[i][i] = 1;
	}
	return p;
}

void cat(MATRIX * a, MATRIX * b)
{
	unsigned int i, n;
	if (a->row != b->row){
		printf("cannot cat two matrixes, different rows!");
		exit(1);
	}
	else if (a -> col + b->col > SIZE_LIMIT){
		printf("size out of limit! cannot cat!");
		exit(1);
	}
	for (i = 0; i < a->row ; ++i){
		for (n = a->col; n < a->col + b->col; ++n){
			a->point[i][n] = b->point[i][n-a->col];
		}
	}
	a->col += b->col;
	a->size = a->row * a->col;
}

void copy(MATRIX * src, MATRIX * tgt)
{
	unsigned int i, n;
	src->row = tgt->row;
	src->col = tgt->col;
	src->size =tgt->size;
	for (i = 0; i < src->row; ++i){
		for (n = 0; n < src->col; ++n){
			src->point[i][n] = tgt->point[i][n];
		}
	}
}

MATRIX inverse(MATRIX a)
{
	unsigned i, n, k, l;
	float c, aik, kk;
	float kn[a.row];
	MATRIX result;
	MATRIX * temp;
	temp = (MATRIX *)malloc(sizeof(MATRIX));
	if (a.row != a.col){
		printf("Not a squared matrix, no inverse!");
		exit(1);
	}
	copy(&result, &a);
	copy(temp, &result);
	for (k = 0; k < result.row; ++k){
		for (i = 0; i < result.row; ++i){
			for (n = 0; n < result.col; ++n){
				if (i == k && n != k){
					result.point[k][n] = temp->point[k][n] / temp->point[k][k];
				}
				else if(i == k && n == k){
					/* result.point[k][k] != 0 */
					result.point[k][k] = 1 / temp->point[k][k];
				}
				else if (n == k){
					result.point[i][k] = 0 - temp->point[i][k] / temp->point[k][k];
				}
				else{
					c = temp->point[i][k] * temp->point[k][n] / temp->point[k][k];
					result.point[i][n] = temp->point[i][n] - c;
				}
			}
		}
		copy(temp, &result);
	}
	free(temp);
	return result;
}

