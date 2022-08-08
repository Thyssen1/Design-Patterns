#pragma once

#include <iostream>

class Coffee {
protected:
	char _type[15];

public:
	Coffee();
	virtual ~Coffee();

	char* getType();
};

class Espresso : public Coffee {
public:
	Espresso();
	~Espresso();
};

class Cappuccino : public Coffee {
public:
	// Call superclass (Coffee) constructor in initializer list
	Cappuccino();
	~Cappuccino();
};