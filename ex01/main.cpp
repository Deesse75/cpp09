#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2){
		std::cerr << "Error\nArgument invalid or missing\nUsage <./RPN> <\"..Inverted Polish mathematical expression..\">" << std::endl;
		return 0;
	}
	RPN rpn(av[1]);
	if (rpn.checkArg() == false)
		return 0;
	else
		rpn.ret();
	return 0;
}