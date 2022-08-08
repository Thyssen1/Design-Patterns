#include "Builder.h"

// Method for Base Builder
MealCombo* MealBuilder::getMeal() {
	return m_meal;
};

// Methods for concrete builder for Burger meal
BurgerBuilder::BurgerBuilder() {
	m_meal = new MealCombo("Burger");
}

void BurgerBuilder::cookEntree() {
	Burger* burger = new Burger;
	m_meal->setEntree(burger);
}

void BurgerBuilder::cookSide() {
	Fries* fries = new Fries;
	m_meal->setSide(fries);
}

void BurgerBuilder::fillDrink() {
	Drink* drink = new Drink;
	m_meal->setDrink(drink);
}

// Methods for concrete builder for Hotdog meal
HotdogBuilder::HotdogBuilder() {
	m_meal = new MealCombo("Hotdog");
}

void HotdogBuilder::cookEntree() {
	Hotdog* hotdog = new Hotdog;
	m_meal->setEntree(hotdog);
}

void HotdogBuilder::cookSide() {
	Salad* caesar = new Salad;
	m_meal->setSide(caesar);
}

void HotdogBuilder::fillDrink() {
	Drink* drink = new Drink;
	m_meal->setDrink(drink);
}
#pragma endregion Builders