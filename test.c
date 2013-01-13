#include <stdio.h>
#include "mfload.h"
#include "mmethod.h"
#include "mstruct.h"


int main(int argc, char *argv[])
{
	if (argc > 1){
		FILE * fp = fopen(argv[1],"r+");
		MATRIX * p = unity(3,3);
		MATRIX q;
		q = load_matrix(fp);
		cat(p, &q);
		print_matrix(*p);
	}
	return 0;
}
