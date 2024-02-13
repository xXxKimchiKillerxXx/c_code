#pragma once

class single
{
	int A;
	int B;
	int A_tmp;
	int B_tmp;

public:
	void set_A(int _A);
	void set_B(int _B);

	void input();

	int gcd_alg();
	int lcm_alg();
};