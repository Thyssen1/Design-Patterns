#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <ctime>
#include <cstdlib>

struct Character {
	int _x = 0;
	int _y = 0;
	std::string _name;

	Character(std::string name) : _name(name) {}

	void move(int x, int y) { _x = x; _y = y; }
};

class Command {
public:
	virtual ~Command() { std::cout << "Destroyed Command!\n"; }
	virtual void execute(Character& c) = 0;
	virtual void undo(Character& c) = 0;
	virtual void print(Character& c) = 0;
protected:
	Command() { std::cout << "Created Command!\n"; }
};


class Move : public Command {
public:
	Move() { std::cout << "Created Move!\n"; }
	~Move() { std::cout << "Destroyed Move!\n"; }

	void execute(Character& c) { 
		int randomx = rand() % 4;
		int randomy = rand() % 4;
		c.move(randomx, randomy);
		x = randomx;
		y = randomy;
		std::cout << c._name << " moved to (" << x << "," << y << ")\n";
	}
	void undo(Character& c) { 
		c.move(-x, -y);
		std::cout << c._name << " undo " << -x << "," << -y << "\n";
	}
	void print(Character& c) {
		std::cout << c._name << "(x,y)=(" << c._x << "," << c._y << ")\n";
	}

private:
	int x = 0;
	int y = 0;
};


int main() { 
	srand(0);

	Character mike("mike");
	std::vector<std::unique_ptr<Command>> command_queue;

	// Use unique pointer to deallocate memory when program ends
	std::unique_ptr<Command> m1 = std::make_unique<Move>();
	std::unique_ptr<Command> m2 = std::make_unique<Move>();
	std::unique_ptr<Command> m3 = std::make_unique<Move>();
	std::unique_ptr<Command> m4 = std::make_unique<Move>();

	// Not using move results in an error since the push_back invokes the vector
	// constructor which takes an initializer_list argument.
	// The initializer list only allows const access to its elements so the 
	// vector must copy the elements and this of course fails to compile
	command_queue.push_back(std::move(m1));
	command_queue.push_back(std::move(m2));
	command_queue.push_back(std::move(m3));
	command_queue.push_back(std::move(m4));

	for (auto iter = command_queue.begin(); iter != command_queue.end(); iter++) {
		iter->get()->execute(mike);
	}

	for (auto iter = command_queue.begin(); iter != command_queue.end(); iter++) {
		iter->get()->undo(mike);
		iter->get()->print(mike);
	}

	return 0;
}