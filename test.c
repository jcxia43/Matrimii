#include <stdio.h>
#include "mfload.h"

int main(int argc, char *argv[])
{
	if (argc > 1){
		load_matrix(argv[1]);
	}
	return 0;
}
