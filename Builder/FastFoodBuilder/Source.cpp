#include <iostream>
#include "Entree.h"
#include "Side.h"
#include "Drink.h"
#include "MealCombo.h"
#include "Builder.h"


int main() {
	MealBuilder* cook = new MealBuilder;
	MealCombo* meal;
	int choice;

	// Prompt user for their meal choice
	std::cout << "Select a meal: \n";
	std::cout << "1. Hamburger Meal. \n";
	std::cout << "2. Hotdog Meal. \n";
	std::cout << "Selection: ";
	std::cin >> choice;

	// Instantiate the appropriate builder based on user input
	switch (choice) {
	case 1:
		cook = new BurgerBuilder;
		break;
	case 2:
		cook = new HotdogBuilder;
	default:
		std::cout << "I do not understand that option!\n";
		break;
	}
	
	std::cout << "Making the selected meal";

	// Build complex object
	cook->cookEntree();
	cook->cookSide();
	cook->fillDrink();
	
	meal = cook->getMeal();
	
	std::cout << meal->openMealBag() << "\n";

	return 0;
}