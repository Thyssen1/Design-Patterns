#include <iostream>
#include <memory>
#include "Coffee.h"
#include "CoffeeMakerFactory.h"

int main() {
	// Invoke factory design pattern and use unique pointer methods
	std::unique_ptr<CoffeeMakerFactory> coffeeMachine(new CoffeeMakerFactory);
	std::unique_ptr<Coffee> cup = coffeeMachine->GetCoffeeUnique();

	// Double check that correct coffee type was created
	std::cout << "\n" << "You asked for a(n) " << cup->getType() << ".\n";

	return 0;
}