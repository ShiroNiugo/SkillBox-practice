#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <sstream>

struct character
{
	std::string name;
	float HP, armor, damage;
	int positionX, positionY;
	bool live = true;
};

void showMap(std::vector<std::vector<char>> &field, character &person, character *enemy, int j = 5, int iEnemy = 0)
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
			std::cout << field[i][j] << " ";
		if (i == 0)
			printf("Status hero:");
		else if (i == 1)
			printf("Name: %s, Position x: %i, y: %i", person.name.c_str(), person.positionX, person.positionY);
		else if (i == 2)
			printf("HP: %f, Armor: %f, Damage: %f", person.HP, person.armor, person.damage);
		else if (i == 4)
			printf("Status enemy:");
		else if (i == j && iEnemy < 5)
		{
			if (enemy[iEnemy].live)
				printf("%s Position x: %i, y: %i", enemy[iEnemy].name.c_str(), enemy[iEnemy].positionX, enemy[iEnemy].positionY);
			else
				printf("%s dead", enemy[iEnemy].name.c_str());
		}
		else if (i == (j + 1) && iEnemy < 5 && enemy[iEnemy].live)
			printf("HP: %f, Armor: %f, Damage: %f", enemy[iEnemy].HP, enemy[iEnemy].armor, enemy[iEnemy].damage);
		std::cout << std::endl;
		if (i >= 6 && i % 2 == 0)
		{
			j += 2;
			iEnemy++;
		}
	}
}

void createHero(character &person, std::vector<std::vector<char>> &field)
{
	std::cout << "Name character: ";
	getline(std::cin, person.name);
	printf("HP: ");
	std::cin >> person.HP;
	printf("Armor: ");
	std::cin >> person.armor;
	printf("Damage: ");
	std::cin >> person.damage;
	do
	{
		person.positionX = rand() % 20;
		person.positionY = rand() % 20;
	} while (field[person.positionX][person.positionY] != '.' && field[person.positionX][person.positionY] != 'E');
	field[person.positionX][person.positionY] = 'P';
};

void createEnemy(character *enemy, std::vector<std::vector<char>> &field)
{
	for (int i = 0; i < 5; i++)
	{
		enemy[i].name = "Enemy #" + std::to_string(i + 1);
		enemy[i].HP = 50 + rand() % 101;
		enemy[i].armor = rand() % 51;
		enemy[i].damage = 15 + rand() % 16;
		do
		{
			enemy[i].positionX = rand() % 20;
			enemy[i].positionY = rand() % 20;
		} while (field[enemy[i].positionX][enemy[i].positionY] != '.');
		field[enemy[i].positionX][enemy[i].positionY] = 'E';
	}
}

void personStep(character &person, character *enemy, std::vector<std::vector<char>> &field, std::string wasd)
{
	int positionX = person.positionX, positionY = person.positionY;
	positionX += ((wasd == "w" && person.positionX - 1 >= 0) ? -1 : ((wasd == "s" && person.positionX + 1 < 20) ? 1 : 0));
	positionY += ((wasd == "a" && person.positionY - 1 >= 0) ? -1 : ((wasd == "d" && person.positionY + 1 < 20) ? 1 : 0));
	if (field[positionX][positionY] != 'E')
	{
		std::swap(field[person.positionX][person.positionY], field[positionX][positionY]);
		person.positionX = positionX;
		person.positionY = positionY;
	}
	else
	{
		for (int i = 0; i < 5; i++)
		{
			if (positionX == enemy[i].positionX && positionY == enemy[i].positionY)
			{
				enemy[i].HP -= person.damage - (person.damage / enemy[i].armor);
				if (enemy[i].HP <= 0)
				{
					enemy[i].live = false;
					field[enemy[i].positionX][enemy[i].positionY] = '.';
				}
			}
		}
	}
}

void enemyStep(character *enemy, character &person, std::vector<std::vector<char>> &field)
{
	for (int i = 0; i < 5; i++)
	{
		if (enemy[i].live && 0 < enemy[i].HP)
		{
			int positionX = enemy[i].positionX, positionY = enemy[i].positionY;
			do
			{
				positionX += (-1 + rand() % 3);
				positionY += (positionX == 0) ? (-1 + rand() % 3) : 0;
			} while (positionX < 0 || positionX > 19 || positionY < 0 || positionY > 19 || (field[positionX][positionY] != '.' && field[positionX][positionY] != 'P'));
			if (field[positionX][positionY] != 'E' && field[positionX][positionY] != 'P')
			{
				std::swap(field[enemy[i].positionX][enemy[i].positionY], field[positionX][positionY]);
				enemy[i].positionX = positionX;
				enemy[i].positionY = positionY;
			}
			else if (field[positionX][positionY] == 'P')
			{
				person.HP -= enemy[i].damage - (enemy[i].damage / person.armor);
				if (person.HP <= 0)
				{
					person.live = false;
					person.HP = 0;
					field[person.positionX][person.positionY] = 'D';
				}
			}
		}
	}
}

void save(character &person, character *enemy)
{
	std::ofstream file("save.bin", std::ios::binary);
	int len;
	for (int i = 0; i < 5; i++)
	{
		len = enemy[i].name.length();
		file.write((char *)&len, sizeof(len));
		file.write(enemy[i].name.c_str(), len);
		file.write((char *)&enemy[i].HP, sizeof(enemy[i].HP));
		file.write((char *)&enemy[i].armor, sizeof(enemy[i].armor));
		file.write((char *)&enemy[i].damage, sizeof(enemy[i].damage));
		file.write((char *)&enemy[i].live, sizeof(enemy[i].live));
		file.write((char *)&enemy[i].positionX, sizeof(enemy[i].positionX));
		file.write((char *)&enemy[i].positionY, sizeof(enemy[i].positionY));
	}
	len = person.name.length();
	file.write((char *)&len, sizeof(len));
	file.write(person.name.c_str(), len);
	file.write((char *)&(person.HP), sizeof(person.HP));
	file.write((char *)&(person.armor), sizeof(person.armor));
	file.write((char *)&(person.damage), sizeof(person.damage));
	file.write((char *)&(person.live), sizeof(person.live));
	file.write((char *)&(person.positionX), sizeof(person.positionX));
	file.write((char *)&(person.positionY), sizeof(person.positionY));
	file.close();
}

void load(character &person, character *enemy, std::vector<std::vector<char>> &field)
{
	std::ifstream file("save.bin", std::ios::binary);
	if (file.is_open())
	{
		for (int i = 0; i < 20; i++)
			for (int j = 0; j < 20; j++)
				field[i][j] = '.';

		int len;

		for (int i = 0; i < 5; i++)
		{
			file.read((char *)&len, sizeof(len));
			enemy[i].name.resize(len);
			file.read((char *)enemy[i].name.c_str(), len);
			file.read((char *)&enemy[i].HP, sizeof(enemy[i].HP));
			file.read((char *)&enemy[i].armor, sizeof(enemy[i].armor));
			file.read((char *)&enemy[i].damage, sizeof(enemy[i].damage));
			file.read((char *)&enemy[i].live, sizeof(enemy[i].live));
			file.read((char *)&enemy[i].positionX, sizeof(enemy[i].positionX));
			file.read((char *)&enemy[i].positionY, sizeof(enemy[i].positionY));
			if (enemy[i].live)
				field[enemy[i].positionX][enemy[i].positionY] = 'E';
		}
		file.read((char *)&len, sizeof(len));
		person.name.resize(len);
		file.read((char *)person.name.c_str(), len);
		file.read((char *)&(person.HP), sizeof(person.HP));
		file.read((char *)&(person.armor), sizeof(person.armor));
		file.read((char *)&(person.damage), sizeof(person.damage));
		file.read((char *)&(person.live), sizeof(person.live));
		file.read((char *)&(person.positionX), sizeof(person.positionX));
		file.read((char *)&(person.positionY), sizeof(person.positionY));
		field[person.positionX][person.positionY] = 'P';
		file.close();
	}
	else
		std::cout << "File not found" << std::endl;
}

int main()
{
	character person, enemy[5];
	int enemyLive;
	std::vector<std::vector<char>> field;

	std::srand(std::time(nullptr));

	for (int i = 0; i < 20; i++)
	{
		field.resize(field.size() + 1);
		for (int j = 0; j < 20; j++)
			field[i].push_back('.');
	}

	createEnemy(enemy, field);
	createHero(person, field);

	do
	{
		showMap(field, person, enemy);
		std::string wasd;
		std::cout << "Step (w,a,s,d,save,load): ";
		std::cin >> wasd;
		(wasd == "save") ? save(person, enemy) : ((wasd == "load") ? load(person, enemy, field) : (personStep(person, enemy, field, wasd), enemyStep(enemy, person, field)));
		enemyLive = 0;
		for (auto e : enemy)
			if (e.live)
				enemyLive++;
	} while (person.live && enemyLive != 0);
	showMap(field, person, enemy);
	printf("%s\n", (person.live) ? "Hero win!" : "Game over!");
	return 0;
}