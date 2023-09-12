#pragma once

#include <iostream>
#include <iomanip>
#include <ctime>
#include <stdint.h>
#include <cstdlib>
#include <list>
#include <vector>

class PmergeMe
{
		std::string _arg;

		bool checkIsInt(std::string num) const;
		void mergeInsertVec(std::vector<int>::iterator start, std::vector<int>::iterator end);
		void insertVec(std::vector<int>::iterator start, std::vector<int>::iterator mid, std::vector<int>::iterator end);

		void affiche(std::vector<int>::iterator start, std::vector<int>::iterator end);
	public:
		PmergeMe(void);
		~PmergeMe(void);
		PmergeMe(PmergeMe const &copy);
		PmergeMe &operator=(PmergeMe const &aff);

		std::string getArg(void) const;

		bool parseInVector(char **av);
		// bool parseInList(char **av);
};