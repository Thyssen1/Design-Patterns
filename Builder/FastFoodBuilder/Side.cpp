#include "Side.h"

char* Side::getSide() {
	return m_side;
}

Fries::Fries() {
	std::cout << "\n Fry and season potatoes.";
	strcpy_s(m_side, "fries");
}

Salad::Salad() {
	std::cout << "\n Toss greens and dressing together.";
	strcpy_s(m_side, "salad");
}