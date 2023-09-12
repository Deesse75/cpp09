#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac == 1){
		std::cerr << "Error\nArguments missing" << std::endl;
		return 0;
	}
	PmergeMe pm;
	pm.parseInVector(&av[1]);
}