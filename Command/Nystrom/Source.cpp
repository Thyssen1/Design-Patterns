#include <iostream>

class Command {
public:
	virtual ~Command() {}
	virtual void execute() = 0;
	virtual void undo() = 0;
protected:
	Command() {}
};

class Unit {
public:
	Unit() {}
	void moveTo(int x, int y) { _x = x; _y = y; }

	int get_x() { return _x; }
	int get_y() { return _y; }

private:
	int _x = 0;
	int _y = 0;
};

class MoveUnitCommand : public Command {
public:
	MoveUnitCommand(Unit* unit, int x, int y) : 
		_unit(unit), _xBefore(0), _yBefore(0), _x(x), _y(y) {}

	virtual void execute() {
		_xBefore = _unit->get_x();
		_yBefore = _unit->get_y();

		_unit->moveTo(_x, _y);
	}

	virtual void undo() {
		_unit->moveTo(_xBefore, _yBefore);
	}

private:
	Unit* _unit;
	int _x;
	int _y;
	int _xBefore;
	int _yBefore;
};



int main() {


	return 0;
}