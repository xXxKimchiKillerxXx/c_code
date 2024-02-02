#pragma once

class GCD
{
	int A;
	int B;
	int tmp_1;
	int tmp_2;
	
public:
	void set_A(int _A);
	void set_B(int _B);

	int get_A() const;
	int get_B() const;

	void GCD_input();
	int GCD_alg();
	void GCD_print();
};