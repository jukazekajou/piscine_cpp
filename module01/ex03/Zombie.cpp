#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	_name = name;
	_type = randomize();
}

Zombie::~Zombie()
{
}

std::string randomize()
{
	int size(std::rand() % (10 - 1) + 1);
	int i(0);
	char c;
	std::string s;

	while (i < size)
	{
		c = char(std::rand() % (122 - 97) + 97);
		s.push_back(c);
		i++;
	}
	return (s);
}

void Zombie::advert()
{
	std::cout << "<" + _name + " " + "(" + _type + ")> Brrrrrrraaaaaaaaiiiiinnssss\n";
}

void Zombie::do_type(std::string type)
{
	_type = type;
}

void Zombie::announce()
{
	std::cout << "I am " + _name + " of type " + _type + "\n";
}

ZombieEvent::ZombieEvent()
{
}

void ZombieEvent::setZombieType(Zombie *zombie, std::string type)
{
	if (type == "")
		std::getline(std::cin, type);
	zombie->do_type(type);
}

Zombie *ZombieEvent::newZombie(std::string name)
{
	Zombie *new_zombie = new Zombie(name);
	return (new_zombie);
}

void ZombieEvent::randomChum()
{
	std::srand(std::time(nullptr));
	Zombie random;
	random.announce();
}

ZombieHorde::ZombieHorde(int n)
{
	_n = n;

	std::srand(std::time(nullptr));
	_lst = new Zombie[n];
}

ZombieHorde::~ZombieHorde()
{
	delete[]_lst;
}

void ZombieHorde::announce()
{
	int i(0);

	while (i < _n)
	{
		_lst[i].announce();
		i++;
	}
}
