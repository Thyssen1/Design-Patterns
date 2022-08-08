#pragma once

#include "Entree.h"
#include "Side.h"
#include "Drink.h"

class MealCombo {
private:
	Entree* entree;
	Side* side;
	Drink* drink;
	char m_bag[100];

public:
	explicit MealCombo(const char* type);

	void setEntree(Entree* e);
	void setSide(Side* s);
	void setDrink(Drink* d);

	const char* openMealBag();
};