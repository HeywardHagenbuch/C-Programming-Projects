#ifndef BIG_INTEGER_ARITHMETIC_HPP
#define BIG_INTEGER_ARITHMETIC_HPP
#include "arithmetic_expression.hpp"
#include "stack.hpp"
class BigIntegerArithmetic
{
    private:
		ArithmeticExpression* ae;
		Stack stack1;
		Stack stack2;
		Stack result;
		std::string s1;
        std::string s2;
		std::string s3;
		std::string s4;
		char action;
		bool negativeNum;
		int carry;
    
    public:
		BigIntegerArithmetic();
		BigIntegerArithmetic(ArithmeticExpression*);
		void SetUp();
		void Add();
        void Subtract();
		std::string ShowResults();
		bool Op1IsBigger(std::string, std::string);
};
#endif
