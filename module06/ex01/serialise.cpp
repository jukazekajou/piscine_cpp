#include <iostream>
#include <climits>
#include <string>

struct Data { std::string s1; int n; std::string s2; };

static char rand_alpha()
{
	char rand;

	rand = std::rand() % 3;
	if (rand == 0)
		return (std::rand() % (57 - 48) + 48);
	if (rand == 1)
		return (std::rand() % (90 - 65) + 65);
	if (rand == 2)
		return (std::rand() % (122 - 97) + 97);
	return ('a');
}

void *serialize(void)
{
	std::srand(std::time(nullptr));
	unsigned char *p;
	unsigned char rand = 0;
	int i = 0;

	p = new unsigned char[(8 + 8) * sizeof(char) + sizeof(int)];
	while (i < (8 + 8) * sizeof(char) + sizeof(int))
	{
		if (i > (8 * sizeof(char)) && i < (8 * sizeof(char) + sizeof(int)))
			rand = std::rand() % (255 - 0) + 0;
		else
			rand = rand_alpha();
		memset(&p[i], rand, 1);
		i++;
	}
	std::cout << p << std::endl;
	return (p);
}

Data *deserialize(void *raw)
{
	unsigned char *p;
	char s[9];

	p = (unsigned char*)raw;
	Data *data = new Data;
	
	memcpy(&s, p, 8 * sizeof(char));
	s[8] = 0;
	data->s1 = std::string(s);
	memcpy(&s, &p[8 * sizeof(char) + sizeof(int)], 8 * sizeof(char));
	s[8] = 0;
	data->s2 = std::string(s);
	memcpy(&data->n, &p[8 * sizeof(char)], sizeof(int));

	return (data);
}

int main()
{
	void *p = serialize();
		
	Data *data = deserialize(p);

	std::cout << data->s1 << " " << data->n << " " << data->s2 << std::endl;
	delete p;
}