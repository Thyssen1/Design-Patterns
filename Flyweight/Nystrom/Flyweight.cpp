#include "Flyweight.h"

Flyweight::Flyweight() : Images() { }

Flyweight::~Flyweight() {
	std::cout << "----------\nDESTRUCTOR\n-----------\n";
	for (std::pair<std::string, Image*> p : Images) {
		delete p.second;
	}
	Images.clear();
}

void Flyweight::DeleteImage(const std::string& resourceName) {
	std::map<std::string, Image*>::iterator iter = Images.find(resourceName);

	if (iter != Images.end()) {
		delete iter->second;
		Images.erase(iter);
		std::cout << "DELETE - DELETED IMAGE\n";
	}
	else {
		std::cout << "DELETE - NO IMAGE FOUND\n";
	}
}

Image* Flyweight::getImage(const std::string& resourceName) {
	std::map<std::string, Image*>::iterator iter = Images.find(resourceName);

	if (iter != Images.end()) {
		std::cout << "GET - FOUND IMAGE\n";
		return iter->second;
	}

	std::cout << "GET - NO IMAGE FOUND\n";
	return nullptr;
}

