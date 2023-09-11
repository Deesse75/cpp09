#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	std::time_t t = std::time(0);
	std::tm *now = std::localtime(&t);
	_year = now->tm_year + 1900;
}

BitcoinExchange::~BitcoinExchange(void) { }

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy) : _year(copy.getYear()), _data(copy._data) { }

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &aff)
{
	if (this != &aff){
		_year = aff.getYear();
		_data.clear();
		_data = aff._data;
	}
	return *this;
}

int BitcoinExchange::getYear(void) const
{
	return _year;
}

bool BitcoinExchange::checkFile(std::string filename)
{
	std::string header;
	std::string line;
	std::ifstream file;
	file.open(filename.c_str());
	if (!file.is_open()){
		std::cerr << "Error\nCannot open : " << filename << std::endl;
		return false;
	}
	if (filename.compare("data.csv") == 0)
		header = "date,exchange_rate";
	else
		header = "date | value";
	std::getline(file, line);
	if (line.compare(header))
	{
		file.close();
		std::cerr << "Error\n" << filename << " is not conform" << std::endl;
		return false;
	}
	file.close();
	return true;
}

void BitcoinExchange::convertArg(std::string filename)
{
	std::string line;
	std::ifstream file;
	file.open(filename.c_str());
	char dash1, dash2, pipe;
	int yy, mm, dd;
	double val;
	char *end;
	std::string value;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::istringstream ss(line);
		ss >> yy >> dash1 >> mm >> dash2 >> dd >> pipe >> value;
		val = std::strtod(value.c_str(), &end);
		if (!ss || dash1 != '-' || dash2 != '-' || pipe != '|' || checkDate(yy, mm, dd) == false || checkValue(value) == false)
			std::cerr << "Error: bad input => " << line << std::endl;
		else if (val > 1000.0)
			std::cerr << "Error: too large a number." << std::endl;
		else if (val < 0)
			std::cerr << "Error: not a positive number." << std::endl;
		else{
			std::cout << line.substr(0, 10) << " => " << value << " = ";
			valBTC((((yy * 100) + mm) * 100) + dd, val);
		}
	}
}

bool BitcoinExchange::convertCSV(void)
{
	std::string line;
	std::ifstream file;
	file.open("data.csv");
	char dash1, dash2, comma;
	int yy, mm, dd;
	double val;
	char *end;
	std::string value;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::istringstream ss(line);
		ss >> yy >> dash1 >> mm >> dash2 >> dd >> comma >> value;
		if (!ss || dash1 != '-' || dash2 != '-' || comma != ','){
			std::cerr << "Error\nInvalid format found in \"data.csv\"" << std::endl;
			file.close();
			return false;
		}
		if (checkDate(yy, mm, dd) == false){
			std::cerr << "Error\nInvalid date found in \"data.csv\"" << std::endl;
			file.close();
			return false;
		}
		if (checkValue(value) == false){
			std::cerr << "Error\nInvalid value found in \"data.csv\"" << std::endl;
			file.close();
			return false;
		}
		val = std::strtod(value.c_str(), &end);
		if (val < 0){
			std::cerr << "Error\nNegative  value found in \"data.csv\"" << std::endl;
			file.close();
			return false;
		}
		_data.insert(std::make_pair((((yy * 100) + mm) * 100) + dd, val));
	}
	file.close();
	if (_data.size() == 0){
		std::cerr << "Error\nNo data in \"data.csv\"" << std::endl;
		return false;
	}
	return true;
}

bool BitcoinExchange::checkDate(int yy, int mm, int dd)
{
	if (yy < 2009 || yy > _year || mm < 1 || mm > 12 || dd < 1 || dd > 31)
		return false;
	switch (mm)
	{
		case 4: case 6: case 9: case 11:
			if (dd > 30)
				return false;
			break;
		case 2:
			if (((yy % 4) == 0 && dd > 29) || ((yy % 4) != 0 && dd > 28))
				return false;
		default:
			break;
	}
	return true;
}

bool BitcoinExchange::checkValue(std::string value)
{
	int dot = 0;
	for(size_t i = 0; i < value.size(); i++){
		if (i == 0 && (value[i] == '+' || value[i] == '-')){
			continue;
		}
		if (value[i] == '.'){
			dot++;
			if (dot > 1)
				return false;
			continue;
		}
		if (!isdigit(value[i]))
			return false;
	}
	return true;
}

void BitcoinExchange::valBTC(int dt, double value)
{
	std::map<int, double>::iterator it = _data.begin();
	if (dt <20090102)
		std::cout << "0" << std::endl;
	else{
		while (it->first < dt)
			it++;
		if (it == _data.end() || it->first > dt)
			it--;
		std::cout << it->second * value << std::endl;
	}
}

