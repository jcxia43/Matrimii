#include <stdio.h>
#include "mfload.h"
#include "mmethod.h"
#include "mstruct.h"


int main(int argc, char *argv[])
{
	if (argc > 1){
		FILE * fp = fopen(argv[1],"r+");
		MATRIX p, q, m;
		p = load_matrix(fp);
		q = inverse(p);
		m = multiply(p, q);
		print_matrix(p);
		print_matrix(q);
		print_matrix(m);
		char c;
		c = getchar();
	}
	return 0;
}
