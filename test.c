#include <stdio.h>
#include "mfload.h"
#include "mmethod.h"
#include "mstruct.h"


int main(int argc, char *argv[])
{
	if (argc > 1){
		FILE * fp = fopen(argv[1],"r+");
		MATRIX p, q;
		p = load_matrix(fp);
		q = load_matrix(fp);
		print_matrix(p);
		print_matrix(q);
		MATRIX s;
		s = multiply(p, q);
		print_matrix(s);
	}
	return 0;
}
