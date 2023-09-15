#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void): _vecTime(0), _listTime(0), _size(0) { }
PmergeMe::~PmergeMe(void) { }
PmergeMe::PmergeMe(PmergeMe const &copy): _vecTime(copy.getVecTime()), _listTime(copy.getListTime()), _size(copy.getSize()) { }
PmergeMe &PmergeMe::operator=(PmergeMe const &aff)
{
	if (this != &aff){
		_vecTime = aff.getVecTime();
		_listTime = aff.getListTime();
		_size = aff.getSize();
	}
	return *this;
}

double PmergeMe::getVecTime(void) const { return _vecTime; }
double PmergeMe::getListTime(void) const { return _listTime; }
size_t PmergeMe::getSize(void) const { return _size; }

bool PmergeMe::parseInVec(char **av)
{
	std::vector<int> vec;
	int i = -1;
	clock_t start = clock();
	while (av[++i]){
		if (checkIsInt(av[i]) == false)
			return false;
		vec.push_back(atoi(av[i]));
	}
	_size = vec.size();
	mergeSortVec(vec.begin(), vec.end() - 1, vec.size());
	clock_t end = clock();
	_vecTime = ((double)(end - start)) * 1000000.0 / CLOCKS_PER_SEC;
	afficheVec(vec);
	return true;
}

bool PmergeMe::parseInList(char **av)
{
	std::list<int> lst;
	int i = -1;
	clock_t start = clock();
	while (av[++i]){
		if (checkIsInt(av[i]) == false)
			return false;
		lst.push_back(atoi(av[i]));
	}
	std::list<int>::iterator it = lst.end();
	it--;
	mergeSortList(lst.begin(), it, lst.size());
	clock_t end = clock();
	_listTime = ((double)(end - start)) * 1000000.0 / CLOCKS_PER_SEC;
	return true;
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

void PmergeMe::mergeSortVec(std::vector<int>::iterator start, std::vector<int>::iterator end, size_t size)
{
	size_t mid = size / 2;
	
	if (size > 7){
		mergeSortVec(start, start + mid - 1, mid);
		mergeSortVec(start + mid, end, mid);
		mergeInsertVec(start, start + mid, end + 1);
	}
	else
		insertSortVec(start, end);
}

void PmergeMe::mergeSortList(std::list<int>::iterator start, std::list<int>::iterator end, size_t size)
{
	size_t midSize = size / 2;
	std::list<int>::iterator mid = start;
	if (size > 5){
		for (size_t i = 0; i < midSize; i++)
			mid++;
		mergeSortList(start, --mid, midSize);
		mergeSortList(++mid, end, midSize);
		mergeInsertList(start, mid, end++);
	}
	else
		insertSortList(start, end);
}

void PmergeMe::insertSortVec(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	std::vector<int>::iterator it = start + 1;
	while (it != end + 1){
		if (*it >= *(it - 1))
			it++;
		else {
			swapValueVec(it, it - 1);
			it = start + 1;
		}
	}
}

void PmergeMe::insertSortList(std::list<int>::iterator start, std::list<int>::iterator end)
{
	std::list<int>::iterator cur = start;
	std::list<int>::iterator prev = cur;
	cur++;
	end++;
	while (cur != end){
		if (*cur >= *prev){
			cur++;
			prev++;
		}
		else {
			swapValueList(cur, prev);
			cur = start;
			cur++;
			prev = start;
		}
	}
}

void PmergeMe::swapValueVec(std::vector<int>::iterator a, std::vector<int>::iterator b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void PmergeMe::swapValueList(std::list<int>::iterator a, std::list<int>::iterator b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void PmergeMe::mergeInsertVec(std::vector<int>::iterator start, std::vector<int>::iterator mid, std::vector<int>::iterator end)
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

void PmergeMe::mergeInsertList(std::list<int>::iterator start, std::list<int>::iterator mid, std::list<int>::iterator end)
{
	std::list<int> l;
	std::list<int>::iterator it1 = start;
	std::list<int>::iterator it2 = mid;
	while (it1 != mid && it2 != end){
		if (*it1 > *it2){
			l.push_back(*it2);
			it2++;
		}
		else{
			l.push_back(*it1);
			it1++;
		}
	}
	if (it1 == mid && it2 != end){
		while (it2 != end){
			l.push_back(*it2);
			it2++;
		}
	}
	else if (it1 != mid && it2 == end){
		while (it1 != mid){
			l.push_back(*it1);
			it1++;
		}
	}
	it1 = start;
	it2 = l.begin();
	while (it2 != l.end()){
		*it1 = *it2;
		it1++;
		it2++;
	}
}

void PmergeMe::afficheVec(std::vector<int> vec)
{
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++){
		if (it == vec.begin() + 10 && it + 1 != vec.end()){
			std::cout << "[...] ";
			break;
		}
		else
			std::cout << *it << " ";

	}
}

void PmergeMe::afficheList(std::list<int> lst)
{
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << "[" << *it << "] ";
}
