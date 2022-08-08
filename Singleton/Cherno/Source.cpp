#include <iostream>

class Random {
public:
	Random(const Random&) = delete;

	static Random& Get() {
		static Random s_Instance;
		return s_Instance;
	}

	static float Float() { return Get().IFloat(); }

private:
	// Private constructor
	Random() {}

	// Internal float function
	float IFloat() { return m_RandomGenerator; }

	float m_RandomGenerator = 0.5f;
};

int main() {
	float number = Random::Float();

	std::cout << number << "\n";

	return 0;
}