#pragma once

class Rational;

struct List 
{

	//explicit List(Rational rat, int expo) : rat(rat), expo(expo) {};

	Rational rat = 0;
	int expo = 0;

	List* next = NULL;
};