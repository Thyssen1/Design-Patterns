#include "Entree.h"

const char* Entree::getEntree() {
	return m_entree;
}

Burger::Burger() {
	std::cout << "\n Grill burger patty, add tomatoes and place them in a bun.";
	strcpy_s(m_entree, "hamburger");
}

Hotdog::Hotdog() {
	std::cout << "\n Cook sausage and place it in a bun.";
	strcpy_s(m_entree, "hotdog");
}