#include <iostream>
#include <memory>

class Animal {
	// No way to get properties outside of the class
protected:
	char m_hairColor[10];
	int m_hairLength, m_tailLength, m_weight, m_height, m_age;
	int m_intelligence, m_stubbornness, m_aggressiveness;

public:
	Animal() {
		std::cout << "Created animal!\n";
	}

	virtual ~Animal() {
		std::cout << "Created animal!\n";
	}

	virtual std::unique_ptr<Animal> clone() = 0;

	void setHairLength(int length) { m_hairLength = length; }
	void setHairColor(const char* color) { strcpy_s(m_hairColor, color); }
	void setTail(int length) { m_tailLength = length; }
	void setWeight(int weight) { m_weight = weight; }
	void setHeight(int m) { m_height = m; }
	void setAge(int age) { m_age = age; }
};

class Sheep : public Animal {
public:
	Sheep() {
		m_hairLength = 5;
		m_stubbornness = 3;
		m_aggressiveness = 2;
		m_intelligence = 7;

		std::cout << "Created sheep!\n";
	}

	~Sheep() {
		std::cout << "Destroyed sheep!\n";
	}

	std::unique_ptr<Animal> clone() { return std::make_unique<Sheep>(*this); }

	void shearing() {
		if (m_hairLength >= 2) { m_hairLength -= 2; }
	}
};

class Cow : public Animal {
public:
	Cow() {
		m_stubbornness = 6;
		m_aggressiveness = 5;
		m_intelligence = 0;

		std::cout << "Created cow!\n";
	}

	~Cow() {
		std::cout << "Destroyed sheep!\n";
	}

	std::unique_ptr<Animal> clone() { return std::make_unique<Cow>(*this); }
};



int main() {
	// Create initial instance of a sheep
	std::unique_ptr<Sheep> sheep0 = std::make_unique<Sheep>();
	//Sheep* sheep0 = new Sheep;
	sheep0->setHairColor("White");
	sheep0->setTail(5);
	sheep0->setWeight(90);
	sheep0->setHeight(1);
	sheep0->setAge(5);

	// Create initial instance of a cow
	std::unique_ptr<Cow> cow0 = std::make_unique<Cow>();
	//Cow* cow0 = new Cow;
	cow0->setHairColor("Brown");
	cow0->setTail(20);
	cow0->setWeight(790);
	cow0->setHeight(2);
	cow0->setAge(8);

	// Use cloning to populate the farm
	std::unique_ptr<Animal> farm[3];
	farm[0] = sheep0->clone();
	farm[1] = cow0->clone();

	// Change cow property
	farm[1]->setWeight(1000);

	// Shear sheep and clone it
	sheep0->shearing();
	farm[2] = sheep0->clone();

	return 0;
}