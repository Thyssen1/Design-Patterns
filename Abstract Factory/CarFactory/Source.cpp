#include <iostream>
#include <memory>

// Abstract product A
class Door {
public:
	Door() { std::cout << "Created Door!\n"; }
	virtual ~Door() { std::cout << "Destroyed Door!\n"; }

	virtual void Open() = 0;
};

// Concrete product A1
class GasCarDoor : public Door {
public:
	GasCarDoor() { std::cout << "Created GasCarDoor!\n"; }
	~GasCarDoor() { std::cout << "Destroyed GasCarDoor!\n"; }

	void Open() { std::cout << "Open GasCarDoor!\n"; }
};

// Concrete product A2
class ElectricCarDoor : public Door {
public:
	ElectricCarDoor() { std::cout << "Created ElectricCarDoor!\n"; }
	~ElectricCarDoor() { std::cout << "Destroyed ElectricCarDoor!\n"; }

	void Open() { std::cout << "Open ElectricCarDoor!\n"; }
};

// Abstract product B
class Engine {
protected:
	char _sound[30] = "";
public:
	Engine() { std::cout << "Created Engine!\n"; }
	virtual ~Engine() { std::cout << "Destroyed Engine!\n"; }

	virtual void Run() = 0;
};

// Concrete product B1
class GasEngine : public Engine {
public:
	GasEngine() { 
		strcpy_s(_sound, "GasEngine sound!"); 
		std::cout << "Created GasEngine!\n"; 
	}
	~GasEngine() { std::cout << "Destroyed GasEngine!\n"; }

	void Run() { std::cout << _sound << "\n"; }
};

// Concrete product B2
class ElectricEngine : public Engine {
public:
	ElectricEngine() { 
		strcpy_s(_sound, "ElectricEngine sound!"); 
		std::cout << "Created ElectricEngine!\n"; 
	}
	~ElectricEngine() { std::cout << "Destroyed GasEngine!\n"; }

	void Run() { std::cout << _sound << "\n"; }

};

// Abstract factory
class CarFactory {
public:
	CarFactory() { std::cout << "Created CarFactory!\n"; }
	virtual ~CarFactory() { std::cout << "Destroyed CarFactory!\n"; }

	virtual Door* BuildDoor() = 0;
	virtual Engine* BuildEngine() = 0;
};

// Concrete factory 1
class GasCarFactory : public CarFactory {
public:
	GasCarFactory() { std::cout << "Created GasCarFactory!\n"; }
	~GasCarFactory() { std::cout << "Destroyed GasCarFactory!\n"; }

	Door* BuildDoor() { return new GasCarDoor(); }
	Engine* BuildEngine() { return new GasEngine(); }
};

// Concrete factory 2
class ElectricCarFactory : public CarFactory {
public:
	ElectricCarFactory() { std::cout << "Created GasCarFactory!\n"; }
	~ElectricCarFactory() { std::cout << "Destroyed GasCarFactory!\n"; }

	Door* BuildDoor() { return new ElectricCarDoor(); }
	Engine* BuildEngine() { return new ElectricEngine(); }
};


int main() {

	// Prompt user
	CarFactory* CarPlant = nullptr;
	int choice;

	std::cout << "Select a car type: \n";
	std::cout << "1. Gasoline\n";
	std::cout << "2. Electric\n";
	std::cout << "Selection: ";
	std::cin >> choice;
	std::cout << std::endl;

	switch (choice) {
	case 1: 
		
		CarPlant = new GasCarFactory();
		break;
	case 2:
		CarPlant = new ElectricCarFactory();
		break;
	default:
		std::cout << "I do not understand that option.\n";
		break;
	}

	if (CarPlant != nullptr) {
		Door* myDoor = CarPlant->BuildDoor();
		Engine* myEngine = CarPlant->BuildEngine();

		myDoor->Open();
		myEngine->Run();
	}

	return 0;
}




