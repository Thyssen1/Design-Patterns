#include <iostream>


// Abstract product A
class Door {
public:
	Door() {
		std::cout << "Created Door!\n";
	}

	virtual void Open() = 0;
};

// Concrete product A1
class GasCarDoor : public Door {
public:
	GasCarDoor() {
		std::cout << "Created GasCarDoor!\n";
	}

	void Open() {
		std::cout << "Open GasCarDoor!\n";
	}
};

// Concrete product A2
class ElectricCarDoor : public Door {
public:
	ElectricCarDoor() {
		std::cout << "Created ElectricCarDoor!\n";
	}

	void Open() {
		std::cout << "Open ElectricCarDoor!\n";
	}
};

// Abstract product B
class Engine {
protected:
	char _sound[15];
public:
	Engine() {
		std::cout << "Created Engine!\n";
	}

	virtual void Run() = 0;
};

// Concrete product B1
class GasEngine : public Engine {
public:
	GasEngine() {
		std::cout << "Created GasEngine!\n";
	}

	void Run() {
		std::cout << _sound << "\n";
	}
};

// Concrete product B2
class ElectricEngine : public Engine {
public:
	ElectricEngine() {
		std::cout << "Created ElectricEngine!\n";
	}

	void Run() {
		std::cout << _sound << "\n";
	}

};

// Abstract factory
class CarFactory {
public:
	CarFactory() {
		std::cout << "Created CarFactory!\n";
	}

	~CarFactory() {
		std::cout << "Destroyed CarFactory!\n";
	}

	virtual Door* BuildDoor() = 0;
	virtual Engine* BuildEngine() = 0;
};

// Concrete factory 1
class GasCarFactory : public CarFactory {
public:
	GasCarFactory() {
		std::cout << "Created GasCarFactory!\n";
	}

	~GasCarFactory() {
		std::cout << "Destroyed GasCarFactory!\n";
	}

	Door* BuildDoor() {
		return new GasCarDoor();
	}

	Engine* BuildEngine() {
		return new GasEngine();
	}
};

// Concrete factory 2
class ElectricCarFactory : public CarFactory {
public:
	ElectricCarFactory() {
		std::cout << "Created GasCarFactory!\n";
	}

	~ElectricCarFactory() {
		std::cout << "Destroyed GasCarFactory!\n";
	}

	Door* BuildDoor() {
		return new ElectricCarDoor();
	}

	Engine* BuildEngine() {
		return new ElectricEngine();
	}
};





