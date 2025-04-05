#include <restunts.h>


int ported_stuntsmain_(int argc, char* argv[]);

// call the implementation in seg010.asm
int stuntsmain(int argc, char* argv[]) {
	return ported_stuntsmain_(argc, argv);
}
