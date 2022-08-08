#include <cmath>

float M_PI = 3.14;

enum class PointType {
	Cartesian,
	Polar
};

//struct Point {
//protected:
//	Point(const float x, const float y) : m_x{x}, m_y{y} {}
//public:
//	static Point NewCartesian(const float x, const float y) {
//		return { x,y };
//	}
//
//	static Point NewPolar(const float r, const float theta) {
//		return { r * cos(theta), r * sin(theta) };
//	}
//
//private:
//	float m_x;
//	float m_y;
//};

struct Point {
	float _x;
	float _y;

	friend class PointFactory;

private:
	Point(float x, float y) : _x(x), _y(y) {}
};

struct PointFactory {
	static Point NewCartesian(float x, float y) {
		return Point{ x,y };
	}

	static Point NewPolar(float r, float theta) {
		return Point{ r * cos(theta), r * sin(theta) };
	}
};

int main() {

	//auto p1 = Point::NewPolar(5, M_PI);
	//auto p2 = Point::NewCartesian(5, 2);

	auto my_point = PointFactory::NewCartesian(3, 4);








	return 0;
}