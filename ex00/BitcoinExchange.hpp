#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <string>
#include <map>
#include <iterator>

class BitcoinExchange
{
		int _year;
		std::map<int, double> _data;

		bool checkDate(int yy, int mm, int dd);
		bool checkValue(std::string value);
		void valBTC(int dt, double value);

	public:
		BitcoinExchange(void);
		~BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &copy);
		BitcoinExchange &operator=(BitcoinExchange const &aff);

		bool checkFile(std::string filename);
		bool convertCSV(void);
		void convertArg(std::string filename);

		int getYear(void) const;
};
