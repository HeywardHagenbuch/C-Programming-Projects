#ifndef ARITHMETIC_EXPRESSION_HPP
#define ARITHMETIC_EXPRESSION_HPP
#include "operand.hpp"
#include <string>
#include <iostream>
class ArithmeticExpression
{
    private:
		Operand one;
		Operand two;
        char action;
        std::string oneVal;
        std::string twoVal;
		std::string data1;
		std::string data2;
		    
    public:
        ArithmeticExpression();
        ArithmeticExpression(std::string s1, std::string s2, char action);
		std::string GetOneVal();
		std::string GetTwoVal();
		std::string GetData1();
		std::string GetData2();
        Operand* GetOp1();
		Operand* GetOp2();
		char GetAction();
		friend std::ostream& operator<<(std::ostream& os, const ArithmeticExpression& ae);
};
#endif
