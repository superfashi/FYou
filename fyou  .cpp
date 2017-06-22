#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cctype>
#include <ctime>

long long line = 10000LL;
std::size_t counter;
std::ifstream cppfile;
std::string tmp;
std::vector<std::string> fil;

void fuckingVar()
{
	std::cout << "FYou++: fatal error: no input files" << std::endl
		      << "compilation terminated." << std::endl;
	std::exit(EXIT_FAILURE);
}

int main(int argc, char* argv[])
{
	std::ios::sync_with_stdio(false);
	std::srand(std::time(nullptr));
	if (argc <= 1)
		fuckingVar();
	for (int i = 1; i < argc - 1; ++i)
		if (std::strcmp(argv[i], "-d") == 0)
		{
			if (i + 1 == argc - 1)
				fuckingVar();
			line = atoll(argv[i + 1]);
			break;
		}
	cppfile.open(argv[argc - 1]);
	if (!cppfile.is_open())
	{
		std::cout << "FYou++: error: " << argv[argc - 1] << ": Unable to read such file" << std::endl;
		fuckingVar();
	}
	while (std::getline(cppfile, tmp))
		fil.push_back(tmp);
	counter = fil.size();
	while (line--)
	{
		int r1 = std::rand() % counter;
		while (std::all_of(fil[r1].begin(), fil[r1].end(), [](const char &c){return std::isspace(c) || std::ispunct(c);}))
			r1 = std::rand() % counter;
		int r2 = std::rand() % fil[r1].size();
		while (std::isspace(fil[r1][r2]))
			r2 = std::rand() % fil[r1].size();
		std::cout << argv[argc - 1] << ':' << r1 + 1 << ':' << r2 + 1
		     << ": error: I DON'T EVEN KNOW WHY, JUST GO AND FUCK YOURSELF." << std::endl;
		std::cout << "  " << fil[r1] << std::endl;
		std::cout << "  ";
		for (int i = 0; i < r2; ++i)
			std::cout << (std::isspace(fil[r1][i]) ? fil[r1][i] : ' ');
		std::cout << '^' << std::endl;
	}
	return EXIT_SUCCESS;
}
