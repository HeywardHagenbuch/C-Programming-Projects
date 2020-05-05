#ifndef EXPRESSION_READER_HPP
#define EXPRESSION_READER_HPP
#include "arithmetic_expression.hpp"
#include "big_integer_arithmetic.hpp"

#include <string>
#include <vector>
#include <sstream>
#include <fstream>

class ExpressionReader
{
    private:
		std::string fileInput;
		std::vector<ArithmeticExpression*> expressions;

    public:
		ExpressionReader();
		void ReadExpressions(std::string fileInput);
		std::string ToString();
		std::string PrintAll();
};
#endif
