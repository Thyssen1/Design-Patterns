#pragma once

#include <iostream>

// Base Entree class
class Entree {
protected:
	char m_entree[10];
public:
	const char* getEntree();
};

// Derived Burger class
class Burger : public Entree {
public:
	Burger();
};

// Derived Hotdog class
class Hotdog : public Entree {
public:
	Hotdog();
};