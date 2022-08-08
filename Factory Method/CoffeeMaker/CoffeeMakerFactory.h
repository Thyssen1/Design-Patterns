#pragma once

#include "Coffee.h"
#include <Memory>

class CoffeeMakerFactory {
private:
	Coffee* _coffee;

public:	
	CoffeeMakerFactory();
	~CoffeeMakerFactory();

	Coffee* GetCoffee();
	std::unique_ptr<Coffee> GetCoffeeUnique();
};