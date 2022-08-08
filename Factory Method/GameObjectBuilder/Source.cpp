#include <string>
#include <iostream>
#include <memory>

class IGameObject {
public:
	IGameObject() {
		std::cout << "Created game object!\n";
	}

	virtual ~IGameObject() {
		std::cout << "Destroyed game object!\n";
	}
	virtual void Update() = 0;
	virtual void Render() = 0;
};

class Plane : public IGameObject {
public:
	Plane() {
		std::cout << "Created plane object!\n";
	}

	virtual ~Plane() {
		std::cout << "Destroyed plane object!\n";
	}

	void Update() {}
	void Render() {}
};

class Boat : public IGameObject {
public:
	Boat() {
		std::cout << "Created boat object!\n";
	}

	virtual ~Boat() {
		std::cout << "Destroyed boat object!\n";
	}

	void Update() {}
	void Render() {}
};

enum class ObjectType {
	PLANE, 
	BOAT
};

std::unique_ptr<IGameObject> MakeGameObjectFactory(ObjectType type) {
	if (type == ObjectType::PLANE) {
		return std::make_unique<Plane>();
	}
	else if (type == ObjectType::BOAT) {
		return std::make_unique<Boat>();
	}
	return nullptr;
}

int main() {
	// Implemented with unique pointer to make memory allocation
	// and deallocation automatic!
	ObjectType planeType = ObjectType::PLANE;
	std::unique_ptr<IGameObject> myObject = MakeGameObjectFactory(planeType);

	return 0;
}