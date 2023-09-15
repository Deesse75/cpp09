#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac == 1){
		std::cerr << "Error\nArguments missing" << std::endl;
		return 0;
	}
	std::cout << "Before:\t";
	for (int i = 1; i < ac; i++){
		if (i == 10 && ac > 10){
			std::cout << "[...] ";
			break;
		}
		std::cout << av[i] << " ";
	}
	std::cout << "\nAfter:\t";
	PmergeMe pm;
	pm.parseInVec(&av[1]);
	std::cout << "\n";
	pm.parseInList(&av[1]);
	std::cout << "Time to process a range of\t" << pm.getSize() << " elements with std::vector : " << pm.getVecTime() << " us" << std::endl;
	std::cout << "Time to process a range of\t" << pm.getSize() << " elements with std::list : " << pm.getListTime() << " us" << std::endl;
	return 0;
}