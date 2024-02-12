#pragma once

class Multi
{
	list<int>LIST;	//To save the inputs.
	list<int>save_LIST;	//For the final output.
	list<int>tmp_LIST;	//For the tail recursion.
	list<int>::iterator iter;
	list<int>::iterator save_iter;

public:
	void multi_input();

	int multi_GCD();
	int multi_LCM();

	void GCD_print();
	void LCM_print();
};