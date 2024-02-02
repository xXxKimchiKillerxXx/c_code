#include "std.h"

int LCM::LCM_alg()
{
	GCD GCD;

	GCD.GCD_input();

	A = GCD.get_A();
	B = GCD.get_B();

	int tmp = GCD.GCD_alg();

	int value = A * B / tmp;

	return value;
}

void LCM::LCM_print()
{
	int value = LCM_alg();

	printf("LCM(%i, %i) = %i", A, B, value);
}