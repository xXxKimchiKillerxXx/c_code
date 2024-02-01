#include <iostream>
using namespace std;

int mod(int A, int B)
{
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

int main()
{
	cout << "Welcome. The code calculates the value for mod(A, B)." << endl;

	int A;
	int B;

	cout << "Put A: ";	cin >> A;
	cout << "Put B: ";	cin >> B;

	int value = mod(A, B);

	if (value == -1)
	{
		return 0;
	}

	printf("mod(%i, %i) = %i", A, B, value);

	return 0;
}