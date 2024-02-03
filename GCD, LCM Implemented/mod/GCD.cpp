#include "std.h"

void GCD::set_A(int _A)
{
	A = _A;
}

void GCD::set_B(int _B)
{
	B = _B;
}

int GCD::get_A() const
{
	return A;
}

int GCD::get_B() const
{
	return B;
}

void GCD::GCD_input()
{
	int _A;
	int _B;

	cout << "Put A: ";
	cin >> _A;
	set_A(_A);

	cout << "Put B: ";
	cin >> _B;
	set_B(_B);
}

int GCD::GCD_alg()
{
	mod mod;

	A_prev = A;
	B_prev = B;

	int rem_tmp;	//Temporary remainder variable.
	int tmp;	//Swap variable.
	bool first_run = true;	//Determines the first run.

	try
	{
		if (A <= 0 || B <= 0)	//Exceptions.
		{
			throw("A and B must be positive.");
		}
		if (B >= A)	//Swap function.
		{
			tmp = B;
			B = A;
			A = tmp;
		}
		if (first_run == true)
		{
			mod.set_A(A);
			mod.set_B(B);

			rem_tmp = mod.mod_alg();

			if (rem_tmp == 0)	//The least one divides another.
			{
				return B;	//The least one.
			}
			first_run = false;	//Does not enter the loop again.
		}
		while (rem_tmp != 0)
		{
			A = B;
			B = rem_tmp;

			mod.set_A(A);
			mod.set_B(B);

			rem_tmp = mod.mod_alg();
		}
		return B;	//Due to the Euclidean algorithm.
	}
	catch (const char* msg)
	{
		cout << msg << endl;

		return -1;
	}
}

void GCD::GCD_print()
{
	int value = GCD_alg();

	if (value == -1)
	{
		return;
	}

	printf("GCD(%i, %i) = %i", A_prev, B_prev, value);
}