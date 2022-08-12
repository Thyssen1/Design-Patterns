#include <vector>
#include <iostream>

class Car {
	int position;
	std::vector<class Observer*> observerList;

public:
	int getPosition() { return position; }

	void setPosition(int newPosition) { position = newPosition; notify(); }

	void attach(Observer* obs) { observerList.push_back(obs); }
	void detach(Observer* obs) {
		observerList.erase(std::remove(observerList.begin(), observerList.end(), obs), observerList.end());
	}

	void notify();
};

class Observer {
private:
	Car* _car;

public:
	Observer(Car* car) {

	}
};
