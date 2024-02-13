#include "std.h"

void Control::menu()
{
	cout << "1. modulo" << endl;
	cout << "2. GCD" << endl;
	cout << "3. LCM" << endl;
	cout << "4. Termination" << endl;
}

void Control::run()
{
	while(true)
	{
		int choice;

		system("cls");

		menu();

		cout << "Choice: " << endl;

		choice = _getch();

		system("cls");

		switch (choice)
		{
		case '1':
			cout << "mod(A, B) calculator" << endl;

			mod_run();

			system("pause");

			break;
		case '2':
			cout << "GCD(A, B, ...) calculator" << endl;

			gcd_run();

			system("pause");

			break;
		case '3':
			cout << "LCM(A, B, ...) calculator" << endl;

			lcm_run();

			system("pause");

			break;
		case '4':
			return;
		}
	}
}

void Control::mod_run()
{
	Mod mod;

	mod.mod_input();
	mod.mod_print();
}

void Control::gcd_run()
{
	Multi mul;

	mul.multi_input();
	mul.GCD_print();
}

void Control::lcm_run()
{
	Multi mul;
	
	mul.multi_input();
	mul.LCM_print();
}