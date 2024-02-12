#include "std.h"

void Multi::multi_input()
{
	float input = NULL;

	cout << "Inputs are requested until 'CTRL + Z' is entered." << endl;

	do	//To receive inputs.
	{
		cout << "Input: " << endl;

		try
		{
			cin >> input;

			if (input != (int)input)
			{
				throw("An input should be an integer.");
			}
			if (input == 0)
			{
				throw("'0' cannot be an input.");
			}
		}
		catch (const char* msg)
		{
			cout << msg << endl;
		}

		if (!cin.eof())	//Exception to the do-while loop. & EOF through a variable is not suitable.
		{
			LIST.push_back((int)input);
		}
	} while (!cin.eof());

	cin.clear();	//To clean the input buffer.

	copy(LIST.begin(), LIST.end(), inserter(save_LIST, save_LIST.begin()));
}

int Multi::multi_GCD()
{
	if (LIST.size() < 2)
	{
		return -1;
	}

	while (LIST.size() >= 2)	//Divide-and-conquer algorithm, tail recursion.
	{
		single sin;

		tmp_LIST.clear();	//Erasing all elements of the last recursion.

		iter = LIST.begin();	//The first iterator.

		int A = *iter;
		LIST.erase(iter++);
		int B = *iter;
		LIST.erase(iter++);

		sin.set_A(A);
		sin.set_B(B);

		tmp_LIST.push_back(sin.gcd_alg());

		if (LIST.size() == 1)
		{
			tmp_LIST.push_back(*iter);	//For an odd number of elements.
			LIST.erase(iter);
		}

		copy(tmp_LIST.begin(), tmp_LIST.end(), inserter(LIST, LIST.begin()));	//Note: 'copy' does not constuct spaces.
	}

	int value = tmp_LIST.front();

	tmp_LIST.clear();

	return value;
}

int Multi::multi_LCM()
{
	if (LIST.size() < 2)
	{
		return -1;
	}

	while (LIST.size() >= 2)	//Divide-and-conquer algorithm, tail recursion.
	{
		single sin;

		tmp_LIST.clear();	//Erasing all elements of the last recursion.

		iter = LIST.begin();	//The first iterator.

		int A = *iter;
		LIST.erase(iter++);
		int B = *iter;
		LIST.erase(iter++);

		sin.set_A(A);
		sin.set_B(B);

		tmp_LIST.push_back(sin.lcm_alg());

		if (LIST.size() == 1)
		{
			tmp_LIST.push_back(*iter);	//For an odd number of elements.
			LIST.erase(iter);
		}

		copy(tmp_LIST.begin(), tmp_LIST.end(), inserter(LIST, LIST.begin()));	//Note: 'copy' does not constuct spaces.
	}

	int value = tmp_LIST.front();

	tmp_LIST.clear();

	return value;
}

void Multi::GCD_print()
{
	system("cls");

	int value = multi_GCD();

	if (value == -1)
	{
		cout << "There were not enough inputs." << endl;

		return;
	}

	cout << "GCD(";
	for (save_iter = save_LIST.begin();save_iter != save_LIST.end();save_iter++)
	{
		if (save_iter != save_LIST.begin())
		{
			cout << ", ";
		}
		cout << *save_iter;
	}
	cout << ") = ";
	cout << value << endl;
}

void Multi::LCM_print()
{
	system("cls");

	int value = multi_LCM();

	if (value == -1)
	{
		cout << "There were not enough inputs." << endl;

		return;
	}

	cout << "LCM(";
	for (save_iter = save_LIST.begin();save_iter != save_LIST.end();save_iter++)
	{
		if (save_iter != save_LIST.begin())
		{
			cout << ", ";
		}
		cout << *save_iter;
	}
	cout << ") = ";
	cout << value << endl;
}