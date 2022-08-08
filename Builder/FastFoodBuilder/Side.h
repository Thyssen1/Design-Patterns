#pragma once

#include <iostream>

// Base Side class
class Side {
protected:
	char m_side[10];
public:
	char* getSide();
};

// Derived Fries class
class Fries : public Side {
public:
	Fries();
};

// Derived Salad class
class Salad : public Side {
public:
	Salad();
};