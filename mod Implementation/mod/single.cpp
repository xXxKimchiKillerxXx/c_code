#include "std.h"


void single::set_A(int _A)
{
	A = _A;
	A_tmp = _A;
}

void single::set_B(int _B)
{
	B = _B;
	B_tmp = _B;
}

void single::input()
{
	int A;
	int B;

	cout << "Put A: ";
	cin >> A;
	set_A(A);

	cout << "Put B: ";
	cin >> B;
	set_B(B);
}

int single::gcd_alg()
{
	Mod mod;

	A = abs(A);
	B = abs(B);

	int rem_tmp;	//Temporary remainder variable.
	int tmp;	//The swap variable.

	try
	{
		if (A == 0 || B == 0)	//Exceptions.
		{
			throw("A and B cannot be '0'.");
		}
		if (B >= A)	//The swap function.
		{
			tmp = B;
			B = A;
			A = tmp;
		}

		mod.set_A(A);
		mod.set_B(B);

		rem_tmp = mod.mod_alg();

		if (rem_tmp == 0)	//The least divides another.
		{
			return B;	//The least.
		}

		while (rem_tmp != 0)
		{
			A = B;
			B = rem_tmp;

			mod.set_A(A);
			mod.set_B(B);

			rem_tmp = mod.mod_alg();
		}
		return B;	//The Euclidean algorithm.
	}
	catch (const char* msg)
	{
		cout << msg << endl;

		return -1;
	}
}

int single::lcm_alg()
{
	int tmp = gcd_alg();

	int value = A_tmp * B_tmp / tmp;

	return value;
}