#include "std.h"

void control::general_menu()
{
	cout << "1. modulo" << endl;
	cout << "2. GCD" << endl;
	cout << "3. LCM" << endl;
	cout << "4. termination" << endl << endl;
}

void control::general_run()
{
	int choice;

	while (true)
	{
		system("cls");

		general_menu();

		cout << "Choice: " << endl;

		choice = _getch();

		system("cls");

		switch (choice)
		{
		case '1':
			cout << "mod(A, B) calculator" << endl;

			mod_run();

			break;
		case '2':
			cout << "GCD(A, B) calculator" << endl;

			GCD_run();

			break;
		case '3':
			cout << "LCM(A, B) calculator" << endl;

			LCM_run();

			break;
		case '4':
			cout << "The program has terminated." << endl;

			return;
		}
		cout << endl;

		system("pause");
	}
}

void control::mod_run()
{
	mod mod;

	mod.mod_input();
	mod.mod_print();
}

void control::GCD_run()
{
	GCD GCD;

	GCD.GCD_input();
	GCD.GCD_print();
}

void control::LCM_run()
{
	LCM LCM;

	LCM.LCM_print();
}