#include "CoffeeMakerFactory.h"

Coffee* CoffeeMakerFactory::GetCoffee() {
	int choice;

	std::cout << "Select type of coffee to make.\n";
	std::cout << "1. Espresso.\n";
	std::cout << "2. Cappuccino.\n";
	std::cout << "Selection: ";
	std::cin >> choice;

	switch (choice) {
	case 1:
		return new Espresso;

	case 2:
		return new Cappuccino;
	default:
		std::cout << "Invalid selection\n";
		return nullptr;
	}
}

std::unique_ptr<Coffee> CoffeeMakerFactory::GetCoffeeUnique() {
	int choice;

	std::cout << "Select type of coffee to make.\n";
	std::cout << "1. Espresso.\n";
	std::cout << "2. Cappuccino.\n";
	std::cout << "Selection: ";
	std::cin >> choice;

	switch (choice) {
	case 1:
		return std::unique_ptr<Espresso>(new Espresso);

	case 2:
		return std::unique_ptr<Cappuccino>(new Cappuccino);
	default:
		std::cout << "Invalid selection\n";
		return nullptr;
	}
}

CoffeeMakerFactory::CoffeeMakerFactory() {
	std::cout << "CoffeeMakerFactory created!\n";
}

CoffeeMakerFactory::~CoffeeMakerFactory() {
	std::cout << "CoffeeMakerFactory destroyed!\n";
}