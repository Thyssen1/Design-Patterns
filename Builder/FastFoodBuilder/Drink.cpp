#include "Drink.h"

Drink::Drink() {
	std::cout << "\n Fill cup with soda\n";
	strcpy_s(m_drink, "drink");
}

char* Drink::getDrink() {
	return m_drink;
}