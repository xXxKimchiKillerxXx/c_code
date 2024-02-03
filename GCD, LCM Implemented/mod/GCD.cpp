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
	int tmp;

	try
	{
		if (A <= 0 || B <= 0)
		{
			throw("A and B must be positive.");
		}
		if (B >= A)
		{
			tmp = B;
			B = A;
			A = tmp;
		}
		do
		{
			mod mod;

			mod.set_A(A);
			mod.set_B(B);

			tmp_1 = mod.mod_alg();
			if (tmp_1 == 0)
			{
				if (A >= B)
				{
					return B;
				}
				else
				{
					return A;
				}
			}

			mod.set_A(B);
			mod.set_B(tmp_1);

			tmp_2 = mod.mod_alg();
		} while (tmp_2 != 0);

		return tmp_1;
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

	printf("GCD(%i, %i) = %i", A, B, value);
}