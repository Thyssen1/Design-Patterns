#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>

// Abstract class
class Bullet {
protected:
	std::string m_bulletName;
	float m_speed;
	float m_firePower;
	float m_damagePower;
	float m_direction;

public:
	Bullet() 
		: m_bulletName(""), m_speed(0), m_firePower(0), m_damagePower(0), 
		m_direction(0) {}
	Bullet(std::string name, float speed, float fire, float dmg)
		: m_bulletName(name), m_speed(speed), m_firePower(fire), m_damagePower(dmg), 
		m_direction(0) {}

	virtual ~Bullet() {}

	virtual std::unique_ptr<Bullet> clone() = 0;
	
	void fire(float direction) {
		m_direction = direction;

		std::cout << "Name        :" << m_bulletName << "\n";
		std::cout << "Speed       :" << m_speed << "\n";
		std::cout << "FirePower   :" << m_firePower << "\n";
		std::cout << "DamagePower :" << m_damagePower << "\n";
		std::cout << "Direction   :" << m_direction << "\n";
	}

};

// Derived implementation class Concrete Prototype
class SimpleBullet : public Bullet {
public:
	SimpleBullet(std::string name, float speed, float fp, float dmg) 
		: Bullet(name, speed, fp, dmg) {}

	std::unique_ptr<Bullet> clone() override {
		return std::make_unique<SimpleBullet>(*this);
	}
};

class GoodBullet : public Bullet {
public:
	GoodBullet(std::string name, float speed, float fp, float dmg) 
		: Bullet(name, speed, fp, dmg) {}

	std::unique_ptr<Bullet> clone() override {
		return std::make_unique<GoodBullet>(*this);
	}
};

enum BulletType {
	SIMPLE,
	GOOD
};

class BulletFactory {
private:
	std::unordered_map<BulletType, std::unique_ptr<Bullet>, std::hash<int> > m_Bullets;

public:
	BulletFactory() {
		m_Bullets[BulletType::SIMPLE] = std::make_unique<SimpleBullet>("Simple Bullet", 50, 75, 75);
		m_Bullets[BulletType::GOOD] = std::make_unique<GoodBullet>("Good Bullet", 75, 100, 100);
	}

	std::unique_ptr<Bullet> createBullet(BulletType type) {
		return m_Bullets[type]->clone();
	}
};

int main() {
	BulletFactory bulletFactory;

	auto Bullet = bulletFactory.createBullet(SIMPLE);
	Bullet->fire(90);

	Bullet = bulletFactory.createBullet(GOOD);
	Bullet->fire(100);

	return 0;
}



