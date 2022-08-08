#include "MealCombo.h"

MealCombo::MealCombo(const char* type) {
	sprintf_s(m_bag, "\n %s meal combo:", type);
}

void MealCombo::setEntree(Entree* e) {
	entree = e;
}

void MealCombo::setSide(Side* s) {
	side = s;
}

void MealCombo::setDrink(Drink* d) {
	drink = d;
}

const char* MealCombo::openMealBag() {
	sprintf_s(m_bag, "%s %s, %s, %s", m_bag, entree->getEntree(), side->getSide(), drink->getDrink());
	return m_bag;
}