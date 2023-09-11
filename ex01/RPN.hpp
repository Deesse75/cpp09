#pragma once

#include <iostream>
#include <stdint.h>
#include <stack>

class RPN
{
		std::string _rpn;
		std::stack<int> _st;

		bool makeOpe(size_t i);

	public:
		RPN(std::string rpn);
		~RPN(void);
		RPN(RPN const &copy);
		RPN &operator=(RPN const &aff);

		bool checkArg(void);
		void ret(void);

		std::string getRPN(void) const;
};