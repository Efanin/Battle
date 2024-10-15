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
void shop(Hero& hero)
{
	cout << "1.Stone sword| lvl: 2, hp: 7, money: 10" << endl;
	cout << "2.Iron sword| lvl: 4, hp: 15, money: 40" << endl;
	cout << "3.Diamond sword| lvl: 7, hp: 25, money: 100" << endl;
	cout << "4.Legendary sword| lvl: 99, hp: 999, money: 10 000" << endl;
	cout << "5.Leather armor| lvl: 2, hp: 10, money: 15" << endl;
	cout << "6.Iron armor| lvl: 5, hp: 20, money: 55" << endl;
	cout << "7.Diamond armor| lvl: 10, hp: 80, money: 250" << endl;
	cout << "8.Legendary armor| lvl: 99, hp: 999, money: 10 000" << endl;
	int x;
	cin >> x;
	switch (x)
	{
	case 1: 
		if (hero.money >= 10) {
			hero.sword.lvl = 2; hero.sword.hp = 7; hero.money -= 10;
		}break;
	case 2:
		if (hero.money >= 40) {
			hero.sword.lvl = 4; hero.sword.hp = 15; hero.money -= 40;
		}break;
	case 3:
		if (hero.money >= 100) {
			hero.sword.lvl = 7; hero.sword.hp = 25; hero.money -= 100;
		}break;
	case 4:
		if (hero.money >= 10000) {
			hero.sword.lvl = 99; hero.sword.hp = 999; hero.money -= 10000;
		}break;
	case 5:
		if (hero.money >= 15) {
			hero.armor.lvl = 2; hero.armor.hp = 7; hero.money -= 15;
		}break;
	case 6:
		if (hero.money >= 55) {
			hero.armor.lvl = 5; hero.armor.hp = 50; hero.money -= 55;
		}break;
	case 7:
		if (hero.money >= 250) {
			hero.armor.lvl = 10; hero.armor.hp = 80; hero.money -= 250;
		}break;
	case 8:
		if (hero.money >= 10000) {
			hero.armor.lvl = 99; hero.armor.hp = 999; hero.money -= 15;
		}break;
	default:
		break;
	}
	hero.info();
}

void Adventure(Hero& hero, vector<Hero>& monsters)
{
	int rnd = random(1000);
	if (rnd == 0)
	{
		hero.hp = -999;
		hero.info();
		return;
	}
	if (rnd == 1)
	{
		hero.sword.lvl = 99;
		hero.sword.hp = 999;
		hero.armor.lvl = 99;
		hero.armor.hp = 999;
		hero.info();
		return;
	}
	if (rnd < 10)
	{
		hero.money += 100;
		hero.info();
		return;
	}
	if (rnd < 20)
	{
		hero.hp += 100;
		hero.info();
		return;
	}
	if (rnd >= 20 && rnd<40)
	{
		battle(monsters[random(monsters.size())], monsters[random(monsters.size())]);
		return;
	}
	if (rnd >= 100 && rnd < 200)
	{
		battle(hero, monsters[random(monsters.size())]);
		return;
	}
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
		cout << "4.Shop" << endl;
		cout << "5.Adventure" << endl;
		cout << "0.Exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: battle(player, monsters[random(monsters.size())]); break;
		case 2: firstAID(player,true); firstAID(monsters[random(monsters.size())]); break;
		case 3: work(player); break;
		case 4: shop(player); break;
		case 5: Adventure(player, monsters);
		default:
			break;
		}
	}
}

