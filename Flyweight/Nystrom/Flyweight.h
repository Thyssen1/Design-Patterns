#pragma once

#include <string>
#include <map>
#include <iostream>
#include "Image.h"


class Flyweight {
public:
	Flyweight();
	~Flyweight();

	template <typename T>
	void AddImage(const std::string& resourceName);
	void DeleteImage(const std::string& resourceName);

	Image* getImage(const std::string& resourceName);

private:
	std::map<std::string, Image*> Images;
};

template <typename T>
void Flyweight::AddImage(const std::string& resourceName) {
	std::map<std::string, Image*>::iterator iter = Images.find(resourceName);

	if (iter == Images.end()) {
		Images[resourceName] = new T();
		std::cout << "ADD - ADDED NEW IMAGE\n";
	}
	else {
		delete iter->second;
		iter->second = new T();
		std::cout << "ADD - REPLACED IMAGE\n";
	}
}

