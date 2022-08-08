#pragma once

#include <iostream>

class Drink {
protected:
	char m_drink[10];
public:
	Drink();

	char* getDrink();
};