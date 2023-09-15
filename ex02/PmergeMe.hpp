#pragma once

#include <iostream>
#include <iomanip>
#include <ctime>
#include <sys/time.h>
#include <stdint.h>
#include <cstdlib>
#include <list>
#include <vector>

class PmergeMe
{
		int _vecTime;
		int _listTime;
		size_t _size;

		bool checkIsInt(std::string num) const;

		void mergeSortVec(std::vector<int>::iterator start, std::vector<int>::iterator end, size_t size);
		void insertSortVec(std::vector<int>::iterator start, std::vector<int>::iterator end);
		void swapValueVec(std::vector<int>::iterator a, std::vector<int>::iterator b);
		void mergeInsertVec(std::vector<int>::iterator start, std::vector<int>::iterator mid, std::vector<int>::iterator end);

		void mergeSortList(std::list<int>::iterator start, std::list<int>::iterator end, size_t size);
		void mergeInsertList(std::list<int>::iterator start, std::list<int>::iterator mid, std::list<int>::iterator end);
		void insertSortList(std::list<int>::iterator start, std::list<int>::iterator end);
		void swapValueList(std::list<int>::iterator a, std::list<int>::iterator b);

	public:
		PmergeMe(void);
		~PmergeMe(void);
		PmergeMe(PmergeMe const &copy);
		PmergeMe &operator=(PmergeMe const &aff);

		double getVecTime(void) const;
		double getListTime(void) const;
		size_t getSize(void) const;

		bool parseInVec(char **av);
		void afficheVec(std::vector<int> vec);

		bool parseInList(char **av);
		void afficheList(std::list<int> lst);
};