#include <chrono>

void processInput() {}
void update(std::chrono::system_clock::duration time) {}
void render() {}

int main() {
	auto lastTime = std::chrono::system_clock::now();
	

	while (true) {
		auto current = std::chrono::system_clock::now();
		auto elapsed = current - lastTime;
		processInput();
		update(elapsed);
		render();
		lastTime = current;
	}
}