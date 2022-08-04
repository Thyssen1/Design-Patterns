#include <iostream>

class Coffee {
protected:
	char _type[15];

public:
	Coffee() {}

	char* getType() {
		return _type;
	}
};

class Espresso : public Coffee {
public:
	Espresso() : Coffee() {
		strcpy_s(_type, "Espresso");
		std::cout << "\n" << "Making a cup of espresso\n";
		std::cout << "Grind and brew one scoop of espresso beans.\n";
	}
};

class Cappuccino : public Coffee {
public:
	Cappuccino() : Coffee() {
		strcpy_s(_type, "Cappuccino");
		std::cout << "\n" << "Making a cup of cappuccino\n";
		std::cout << "Grind and brew one scoop of espresso beans.\n";
		std::cout << "Heat foam and milk.\n";
	}
};

class CoffeeMakerFactory{
private:
	Coffee* _coffee;

public:
	Coffee* GetCoffee() {
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
};

int main() {
	// Invoke factory design pattern
	CoffeeMakerFactory coffeeMachine;
	Coffee* cup;
	cup = coffeeMachine.GetCoffee();

	// Double check that correct coffee type was created
	std::cout << "\n" << "You asked for a(n) " << cup->getType() << ".\n";

	return 0;
}