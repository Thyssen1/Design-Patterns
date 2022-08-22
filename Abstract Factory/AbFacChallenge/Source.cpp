#include <iostream>
#include <memory>
#include <windows.h>

// Abstract product A
class Background {
protected:
	char m_theme[10] = "";
public:
	Background() { std::cout << "Created Background!\n"; }
	virtual ~Background() { std::cout << "Destroyed Background!\n"; }

	virtual void getTheme() = 0;
};

// Concrete product A1
class LightBkgd : public Background {
public:
	LightBkgd(HANDLE hConsole) { 
		SetConsoleTextAttribute(hConsole, 240);
		strcpy_s(m_theme, "Light");
		std::cout << "Created Light Background instance!\n"; 
	}
	~LightBkgd() { std::cout << "Destroyed Light Background instance!\n"; }

	void getTheme() { std::cout << "This is part of the light theme!\n"; }
};

// Concrete product A2
class BlackBkgd : public Background {
public:
	BlackBkgd(HANDLE hConsole) { 
		SetConsoleTextAttribute(hConsole, 15);
		strcpy_s(m_theme, "Dark");
		std::cout << "Created Black Background instance!\n"; }
	~BlackBkgd() { std::cout << "Destroyed Black Background instance!\n"; 
	}

	void getTheme() { std::cout << "This is part of the dark theme!\n"; }
};

// Abstract product B
class Text {
protected:
	char m_theme[10] = "";
public:
	Text() { std::cout << "Created Text!\n"; }
	virtual ~Text() { std::cout << "Destroyed Text!\n"; }

	virtual void message(HANDLE hConsole) = 0;
};

// Concrete product B1
class WhiteText : public Text {
public:
	WhiteText(HANDLE hConsole) {
		SetConsoleTextAttribute(hConsole, 15);
		strcpy_s(m_theme, "Dark");
		std::cout << "Created White Text!\n";
	}
	~WhiteText() { std::cout << "Destroyed White Text!\n"; }

	void message(HANDLE hConsole) {
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << "This is the default font for the dark theme\n";
	}
};

// Concrete product B2
class BlackText : public Text {
public:
	BlackText(HANDLE hConsole) {
		SetConsoleTextAttribute(hConsole, 240);
		strcpy_s(m_theme, "Light");
		std::cout << "Created Black Text!\n";
	}

	~BlackText() { std::cout << "Destroyed Black Text!\n"; }

	void message(HANDLE hConsole) { 
		SetConsoleTextAttribute(hConsole, 240);
		std::cout << "This is the default font from the light theme\n";
	}

};

// Derived Dark Green Text class
class DarkGreenText : public Text {
public:
	DarkGreenText(HANDLE hConsole) {
		SetConsoleTextAttribute(hConsole, 242);
		strcpy_s(m_theme, "Light");
		std::cout << "Created Dark Green Text!\n";
	}

	~DarkGreenText() { std::cout << "Destroyed Dark Green Text!\n"; }

	void message(HANDLE hConsole) {
		SetConsoleTextAttribute(hConsole, 242);
		std::cout << "This is the default font from the dark green theme\n";
	}

};

// Derived Light Green Text class
class LightGreenText : public Text {
public:
	LightGreenText(HANDLE hConsole) {
		SetConsoleTextAttribute(hConsole, 10);
		strcpy_s(m_theme, "Light");
		std::cout << "Created Light Green Text!\n";
	}

	~LightGreenText() { std::cout << "Destroyed Light Green Text!\n"; }

	void message(HANDLE hConsole) {
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << "This is the default font from the light green theme\n";
	}

};

// Abstract factory
class ThemeFactory {
public:
	ThemeFactory() { std::cout << "Created Theme Factory!\n"; }
	virtual ~ThemeFactory() { std::cout << "Destroyed Theme Factory!\n"; }

	virtual Background* setBackground(HANDLE hConsole) = 0;
	virtual Text* getDefaultText(HANDLE hConsole) = 0;
	virtual Text* getGreenText(HANDLE hConsole) = 0;
};

// Concrete factory 1
class LightFactory : public ThemeFactory {
public:
	LightFactory() { std::cout << "Created LightFactory!\n"; }
	~LightFactory() { std::cout << "Destroyed LightFactory!\n"; }

	Background* setBackground(HANDLE hConsole) { return new LightBkgd(hConsole); }
	Text* getDefaultText(HANDLE hConsole) { return new BlackText(hConsole); }
	Text* getGreenText(HANDLE hConsole) { return new DarkGreenText(hConsole); }
};

// Concrete factory 2
class BlackFactory : public ThemeFactory {
public:
	BlackFactory() { std::cout << "Created Black Factory!\n"; }
	~BlackFactory() { std::cout << "Destroyed Black Factory!\n"; }

	Background* setBackground(HANDLE hConsole) { return new BlackBkgd(hConsole); }
	Text* getDefaultText(HANDLE hConsole) { return new WhiteText(hConsole); }
	Text* getGreenText(HANDLE hConsole) { return new LightGreenText(hConsole); }
};


int main() {

	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 30);

	ThemeFactory* app;
	int choice = 0;

	std::cout << "Seelect a them: \n";
	std::cout << "1: Light\n";
	std::cout << "2. Dark\n";
	std::cout << "Selection: ";
	std::cin >> choice;
	std::cout << std::endl;

	switch (choice) {
	case 1:
		app = new LightFactory;
		break;
	case 2:
		app = new BlackFactory;
		break;
	default:
		std::cout << "Invalid selection!\n";
		app = nullptr;
		break;
	}

	if (app != nullptr) {
		Background* appBkgd = app->setBackground(hConsole);
		Text* appDefaultText = app->getDefaultText(hConsole);
		Text* appGreenText = app->getGreenText(hConsole);

		appDefaultText->message(hConsole);
		appGreenText->message(hConsole);
	}

	std::cout << "\n";

	return 0;
}
