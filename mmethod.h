#include <stdio.h>
#include "mstruct.h"

#define sub(x,y) add(x,y,1,-1)
float get_value(MATRIX m, unsigned int row, unsigned int col);
void print_matrix(MATRIX m);
MATRIX get_transpose(MATRIX m);
MATRIX add(MATRIX a, MATRIX b, int coa, int cob);
MATRIX multiply(MATRIX a, MATRIX b);
