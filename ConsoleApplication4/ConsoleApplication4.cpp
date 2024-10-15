// ConsoleApplication4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Hero
{
public:
	string name;
	int damage;
	int hp;
	Hero(string name, int damage, int hp)
	{
		this->name = name;
		this->damage = damage;
		this->hp = hp;
	}
	void info()
	{
		cout << "____________________________________\n";
		cout << "Name: " << name << endl;
		cout << "Damage: " << damage << endl;
		cout << "HP: " << hp << endl;
		cout << "____________________________________\n";
	}
};


string monsterName()
{
	vector<string> name = { "Zombie","Orc","Goblin","Troll","Vapire","Wolfman" };
	return name[rand() % name.size()];
}
int random(int min, int max)
{
	return min + rand() % (max - min);
}
int random(int max)
{
	return rand() % max;
}

void battle(Hero &hero1, Hero &hero2)
{
	hero1.info();
	hero2.info();
	cout << "------------------BATLLE-----------------\n";
	while (hero1.hp > 0 && hero2.hp > 0)
	{
		hero1.hp -= hero2.damage;
		hero2.hp -= hero1.damage;
	}
	if (hero1.hp > 0)
	{
		cout << "------------------" << hero1.name << " WIN-----------------\n";
		hero1.damage++;
	}
	if (hero2.hp > 0)
	{
		cout << "------------------" << hero2.name << " WIN-----------------\n";
		hero2.damage++;
	}
	hero1.info();
	hero2.info();
}

int main()
{
	srand(time(NULL));
	Hero player("Igor", 10, 100);
	vector<Hero> monsters;
	for (int i = 0; i < 10; i++)
		monsters.push_back(Hero(monsterName(), random(5, 15), random(50, 150)));
	int choice;
	cout << "1.BATTLE" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1: battle(player, monsters[random(monsters.size())]); break;
	default:
		break;
	}

}

