#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) { }
PmergeMe::~PmergeMe(void) { }
PmergeMe::PmergeMe(PmergeMe const &copy) : _arg(copy.getArg()) { }
PmergeMe &PmergeMe::operator=(PmergeMe const &aff)
{
	if (this != &aff)
		_arg = aff.getArg();
	return *this;
}

std::string PmergeMe::getArg(void) const { return _arg; }

bool PmergeMe::parseInVector(char **av)
{
	std::vector<int> vec;
	clock_t start = clock();
	int i = -1;
	while (av[++i]){
		if (checkIsInt(av[i]) == false)
			return false;
		vec.push_back(atoi(av[i]));
	}
	mergeInsertVec(vec.begin(), vec.end() - 1);
	clock_t end = clock();
	std::cout << ((double)(end - start)) * 1000000.0 / CLOCKS_PER_SEC << "us" << std::endl;
	affiche(vec.begin(), vec.end());
	return true;
}

void PmergeMe::mergeInsertVec(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	int mid = 1;
	int tmp;
	for (std::vector<int>::iterator it = start; it != end; it++)
		mid++;
	if (mid > 2){
		mid /= 2;
		mergeInsertVec(start, start + mid - 1);
		mergeInsertVec(start + mid, end);
		insertVec(start, start + mid, end + 1);
	}
	else if (mid > 1) {
		if (*start > *end){
			tmp = *start;
			*start = *end;
			*end = tmp;
		}
	}
}

void PmergeMe::insertVec(std::vector<int>::iterator start, std::vector<int>::iterator mid, std::vector<int>::iterator end)
{
	std::vector<int> v;
	std::vector<int>::iterator it1 = start;
	std::vector<int>::iterator it2 = mid;
	while (it1 != mid && it2 != end){
		if (*it1 > *it2){
			v.push_back(*it2);
			it2++;
		}
		else{
			v.push_back(*it1);
			it1++;
		}
	}
	if (it1 == mid && it2 != end){
		while (it2 != end){
			v.push_back(*it2);
			it2++;
		}
	}
	else if (it1 != mid && it2 == end){
		while (it1 != mid){
			v.push_back(*it1);
			it1++;
		}
	}
	it1 = start;
	it2 = v.begin();
	while (it2 != v.end()){
		*it1 = *it2;
		it1++;
		it2++;
	}
}

bool PmergeMe::checkIsInt(std::string num) const
{
	long val = 0;
	for (size_t i = 0; i < num.size(); i++){
		if (!isdigit(num[i])){
			std::cout << "Error\nInvalid character" << std::endl;
			return false;
		}
		val = (val * 10) + ( num[i] - 48);
		if (val > INT32_MAX){
			std::cout << "Error\nInt overflow" << std::endl;
			return false;
		}
	}
	return true;
}

void PmergeMe::affiche(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	while (start != end){
		std::cout << "{" << *start << "}";
		start++;
	}
	std::cout << "\n";
}