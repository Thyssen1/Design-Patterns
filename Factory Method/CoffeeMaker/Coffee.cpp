#include "Coffee.h"


Coffee::Coffee() {
	std::cout << "Coffee created!\n";
}

Coffee::~Coffee() {
	std::cout << "Coffee destroyed!\n";
}

char* Coffee::getType() {
	return _type;
}

Espresso::Espresso() : Coffee() {
	strcpy_s(_type, "Espresso");
	std::cout << "Espresso created!\n";
}

Espresso::~Espresso() {
	std::cout << "Espresso destroyed!\n";
}


Cappuccino::Cappuccino() : Coffee() {
	strcpy_s(_type, "Cappuccino");
	std::cout << "Cappuccino created!\n";
}

Cappuccino::~Cappuccino() {
	std::cout << "Cappuccino destroyed!\n";
}