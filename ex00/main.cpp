#include "BitcoinExchange.hpp"


int main(int ac, char **av)
{
	if (ac != 2){
		std::cerr << "Error\nArgument missing\nUsage : <./btc> <filename>" << std::endl;
		return 0;
	}
	BitcoinExchange btc;
	if (btc.checkFile("data.csv") == false || btc.checkFile(av[1]) == false)
		return 0;
	if (btc.convertCSV() == false)
		return 0;
	btc.convertArg(av[1]);
	return 0;
}