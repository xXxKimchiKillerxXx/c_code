#include "std.h"

void mod::set_A(int _A)
{
	A = _A;
}

void mod::set_B(int _B)
{
	B = _B;
}

int mod::get_A() const
{
	return A;
}

int mod::get_B() const
{
	return B;
}

void mod::mod_input()
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

int mod::mod_alg()
{
	A = get_A();
	B = get_B();
	int tmp = A;

	try
	{
		if (B <= 0)
		{
			throw "Divisor must be a positive integer.";
		}
		if (A >= B)
		{
			while (!(0 <= tmp && tmp < B))
			{
				tmp -= B;
			}
			return tmp;
		}
		else
		{
			while (!(0 <= tmp && tmp < B))
			{
				tmp += B;
			}
			return tmp;
		}
	}
	catch (const char* str)
	{
		cout << str << endl;

		return -1;
	}
}

void mod::mod_print()
{
	int value = mod_alg();

	if (value == -1)
	{
		return;
	}

	printf("mod(%i, %i) = %i", get_A(), get_B(), value);
}