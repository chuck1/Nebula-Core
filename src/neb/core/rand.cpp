#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

#include <neb/core/rand.hpp>

int random_index = 0;
unsigned int* randoms = 0;

unsigned int myrand()
{
	std::string line;
	if(randoms == 0)
	{
		randoms = new unsigned int[10000];
		std::ifstream ifs;
		ifs.open("../../../../../media/random/0.txt");
		assert(ifs.is_open());
		for(unsigned int i = 0; i < 10000; i++)
		{
			getline(ifs, line);
			randoms[i] = atoi(line.c_str());
			std::cout << line << std::endl;
		}
	}

	return randoms[random_index++];
}

