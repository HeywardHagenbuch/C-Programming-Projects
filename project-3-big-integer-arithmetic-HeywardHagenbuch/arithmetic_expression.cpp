#include "arithmetic_expression.hpp"
using namespace std;

ArithmeticExpression::ArithmeticExpression()
{
}

ArithmeticExpression::ArithmeticExpression(string firstOp, string secondOp, char action)
{
	one.SetValue(firstOp);
	two.SetValue(secondOp);

    one.Pad(secondOp.length() - firstOp.length()); //Padding the operand so that both operand are equal in length
	two.Pad(firstOp.length() - secondOp.length());
	
    data1 = firstOp;
	data2 = secondOp;
	this->action = action;	
	oneVal = one.GetValue();
	twoVal = two.GetValue();  
}

string ArithmeticExpression::GetOneVal()
{
	return oneVal;
}

string ArithmeticExpression::GetTwoVal()
{
	return twoVal;
}

char ArithmeticExpression::GetAction()
{
	return action;
}

string ArithmeticExpression::GetData1()
{
	return data1;
}

string ArithmeticExpression::GetData2()
{
	return data2;
}

Operand* ArithmeticExpression::GetOp1()
{
	return &one;
}

Operand* ArithmeticExpression::GetOp2()
{
	return &two;
}

ostream& operator << (ostream& os, const ArithmeticExpression& ae)
{
	os << ae.oneVal << " " << ae.twoVal << " " << ae.action;
	return os;
}
