#pragma once

#include "MealCombo.h"

#pragma region Builders
// Base Builder
class MealBuilder {
protected:
	MealCombo* m_meal;
public:
	virtual void cookEntree() {};
	virtual void cookSide() {};
	virtual void fillDrink() {};

	MealCombo* getMeal();
};

// Concrete builder for Burger meal
class BurgerBuilder : public MealBuilder {
public:
	BurgerBuilder();

	void cookEntree();
	void cookSide();
	void fillDrink();
};

// Concrete builder for Hotdog meal
class HotdogBuilder : public MealBuilder {
public:
	HotdogBuilder();

	void cookEntree();
	void cookSide();
	void fillDrink();
};
#pragma endregion Builders