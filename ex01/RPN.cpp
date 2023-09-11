#include "RPN.hpp"

RPN::RPN(std::string rpn) : _rpn(rpn) { }
RPN::~RPN(void) { }
RPN::RPN(RPN const &copy) : _rpn(copy.getRPN()), _st(copy._st) { }
RPN &RPN::operator=(RPN const &aff)
{
	if (this != &aff){
		_rpn = aff.getRPN();
		_st = aff._st;
	}
	return *this;
}

std::string RPN::getRPN(void) const { return _rpn; }

bool RPN::checkArg(void)
{
	int ope = 0;
	int nb = 0;
	if (_rpn.size() == 0){
		std::cerr << "Error\nRPN is empty" << std::endl;
		return false;
	}
	for (size_t i = 0; i < _rpn.size(); i++){
		if (_rpn[i] == 32)
			continue;
		if (isdigit(_rpn[i]))
			nb++;
		if (_rpn[i] == '+' || _rpn[i] == '-' || _rpn[i] == '*' || _rpn[i] == '/'){
			ope++;
			if (nb < 2){
				std::cerr << "Error\nRPN not conform" << std::endl;
				return false;
			}
			nb--;
		}
		if (_rpn[i + 1] != 32 && i + 1 < _rpn.size()){
			std::cerr << "Error\nMissing space between characters" << std::endl;
			return false;
		}
		if (!isdigit(_rpn[i]) && _rpn[i] != '+' && _rpn[i] != '-' && _rpn[i] != '*' && _rpn[i] != '/'){
			std::cerr << "Error\nInvalid character" << std::endl;
			return false;
		}
	}
	if (ope == 0 || nb != 1){
		std::cerr << "Error\nRPN no conform" << std::endl;
		return false;
	}
	return true;
}

void RPN::ret(void)
{
	size_t i = -1;
	while (++i < _rpn.size()){
		if (_rpn[i] == 32)
			continue;
		if (isdigit(_rpn[i]))
			_st.push(_rpn[i] - 48);
		else if (_rpn[i] == '+' || _rpn[i] == '-' || _rpn[i] == '*' || _rpn[i] == '/'){
			if (makeOpe(i) == false)
				return;
		}
	}
	std::cout << _st.top() << std::endl;
}

bool RPN::makeOpe(size_t i)
{
	int b = _st.top();
	_st.pop();
	int a = _st.top();
	_st.pop();
	long int ret;
	if (_rpn[i] == '+')
		ret = a + b;
	else if (_rpn[i] == '-')
		ret = a - b;
	else if (_rpn[i] == '*')
		ret = a * b;
	else if (_rpn[i] == '/'){
		if (b == 0){
			std::cerr << "Error\nDivision by 0" << std::endl;
			return false;
		}
		ret = a / b;
	}
	if (ret > INT32_MAX || ret < INT32_MIN){
		std::cerr << "Error\nINT overflow" << std::endl;
		return false;
	}
	_st.push(ret);
	return true;
}