#include "std.h"

void control::mod_menu()
{
	cout << "mod(A, B) calculator" << endl;
}

void control::mod_run()
{
	mod mod;

	mod_menu();
	mod.mod_input();
	mod.mod_print();
}

void control::GCD_menu()
{
	cout << "GCD(A, B) calculator" << endl;
}

void control::GCD_run()
{
	GCD GCD;

	GCD_menu();
	GCD.GCD_print();
}

void control::LCM_menu()
{
	cout << "LCM(A, B) calculator" << endl;
}

void control::LCM_run()
{
	LCM LCM;

	LCM_menu();
	LCM.LCM_print();
}