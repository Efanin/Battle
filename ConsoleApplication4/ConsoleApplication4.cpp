// ConsoleApplication4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Item
{
public:
	int lvl;
	int hp;
};

class Hero
{
public:
	string name;
	int damage;
	int hp;
	int money;
	Item armor;
	Item sword;
	Hero(string name, int damage, int hp,int money = 100)
	{
		this->name = name;
		this->damage = damage;
		this->hp = hp;
		this->money = money;
		armor.lvl = 1;
		armor.hp = 10;
		sword.lvl = 1;
		sword.hp = 10;
	}
	void info()
	{
		cout << "____________________________________\n";
		cout << "Name: " << name  << "| Money: " << money << endl;
		cout << "Damage: " << damage << "| Armor: "<<armor.lvl << " Sword: " << sword.lvl << endl;
		cout << "HP: " << hp << "| Armor: " << armor.hp << " Sword: " << sword.hp << endl;
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
		hero1.hp = hero1.hp + hero1.armor.lvl - (hero2.damage + hero2.sword.lvl);
		hero2.hp = hero2.hp + hero2.armor.lvl - (hero1.damage + hero1.sword.lvl);
		hero1.armor.hp--;
		hero2.armor.hp--;
		hero1.sword.hp--;
		hero2.sword.hp--;
		if (hero1.armor.hp <= 0)
			hero1.armor.lvl = 0;
		if (hero2.armor.hp <= 0)
			hero2.armor.lvl = 0;
		if (hero1.sword.hp <= 0)
			hero1.sword.lvl = 0;
		if (hero2.sword.hp <= 0)
			hero2.sword.lvl = 0;
	}
	if (hero1.hp > 0)
	{
		cout << "------------------" << hero1.name << " WIN-----------------\n";
		hero1.damage++;
		hero1.money += 10;
	}
	if (hero2.hp > 0)
	{
		cout << "------------------" << hero2.name << " WIN-----------------\n";
		hero2.damage++;
		hero2 .money += 10;
	}
	hero1.info();
	hero2.info();
}

void firstAID(Hero& hero, bool info = false)
{
	if (hero.money >= 10)
	{
		hero.hp += 10;
		hero.money -= 10;
	}
	else
		cout << "Money is over\n";
	if(info==true)
		hero.info();
}

void work(Hero& hero)
{
	cout << "------------------Guess the number------------------" << endl;
	int x = random(100); 
	int num = -1;
	while (num != x)
	{
		cin >> num;
		if (x < num)
			cout << "less\n";
		if (x > num)
			cout << "more\n";
	}
	cout << "------------------ +10 MONEY ------------------" << endl;
	hero.money += 10;
	hero.info();
}

int main()
{
	srand(time(NULL));
	Hero player("Igor", 10, 100, 50);
	vector<Hero> monsters;
	for (int i = 0; i < 10; i++)
		monsters.push_back(Hero(monsterName(), random(5, 15), random(50, 150)));
	int choice=1;
	while(choice !=0)
	{
		cout << "1.BATTLE" << endl;
		cout << "2.First AID" << endl;
		cout << "3.Work" << endl;
		cout << "0.Exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: battle(player, monsters[random(monsters.size())]); break;
		case 2: firstAID(player,true); firstAID(monsters[random(monsters.size())]); break;
		case 3: work(player); break;
		default:
			break;
		}
	}
}

