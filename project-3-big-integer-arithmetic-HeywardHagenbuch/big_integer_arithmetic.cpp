#include "big_integer_arithmetic.hpp"
using namespace std;

BigIntegerArithmetic::BigIntegerArithmetic()
{
}

BigIntegerArithmetic::BigIntegerArithmetic(ArithmeticExpression* ae){
	this->ae = ae;
	carry = 0;
}

void BigIntegerArithmetic::SetUp()//getting the values from the operands and pushing them into 2 stacks
{
	this->s1 = ae->GetOneVal();
	this->s2 = ae->GetTwoVal();
	this->s3 = ae->GetData1();
	this->s4 = ae->GetData2();
	this->action = ae->GetAction();

	for(unsigned int i = 0; i < s1.size(); i++)
	{
		stack1.Push(s1.at(i));
		stack2.Push(s2.at(i));
	}
}

bool BigIntegerArithmetic::Op1IsBigger(string operand1, string operand2)//checks to see if the first operand is larger than the second operand
{
	bool answer = false;
	if((operand1.compare(operand2)) < 0)
	{
		answer = false;
	}
	else
	{
		answer = true;
	}
	return answer;
}


void BigIntegerArithmetic::Add()
{
	negativeNum = false;
	for(unsigned int i = 0; i <= s1.size(); i++)
	{
		int number = 0;
		int num1 = 0;
		int num2 = 0;
		
		if(i < s1.size())
		{
			num1 = stack1.Pop() - 48; //operands are stored as strings, this pops off one character from the stack
			num2 = stack2.Pop() - 48; //subtracting the base value 48 converts the chars ascii value to an integer 
		}

		if(action == '+')
		{
			if(num1 + num2 + carry < 10)//there is NO carry over
			{
				number = num1 + num2 + carry;
				carry = 0;
			}
			else{
				number = num1 + num2 + carry - 10; //there is a carry over
				carry = 1;
			}
		}
		else//handles negative numbers
		{
			if(Op1IsBigger(s1, s2))
			{
				number = num1 - num2 - carry;
			}
			else
			{
				number = num2 - num1 - carry;
				negativeNum = true;
			}
			if(number < 0)
			{
				number = number + 10;
				carry = 1;
			}
			else{
				carry = 0;
			}
		}

		if((!Op1IsBigger(s1, s2)) && (i == s1.size()) && (action == '-'))
		{
			negativeNum = true;
			break;
		}
		else if((Op1IsBigger(s1, s2)) && (i == s1.size()) && (action == '-'))
		{
			negativeNum = false;
			break;
		}
		else
		{
			result.Push(number);
		}
	}
}

void BigIntegerArithmetic::Subtract() //The Add() handles the subtraction
{
	Add();
}

string BigIntegerArithmetic::ShowResults() //Prints the results
{
	string answer, number, value = "";
	bool isNum = false;
	int numSize = 0;
	answer += "     ";
	
	if(static_cast<int>((ae->GetData2().length() - ae->GetData1().length())) > 0)
	{
		for(unsigned int i = 0; i < (ae->GetData2().length() - ae->GetData1().length()); i++)
		{
			answer += " ";
		}
	}

	answer += s3 + "\n    ";
	answer += action;
	
	if(static_cast<int>((ae->GetData1().length() - ae->GetData2().length())) > 0)
	{
		for(unsigned int i = 0; i < (ae->GetData1().length() - ae->GetData2().length()); i++)
		{
			answer += " ";
        }
    }

	answer += s4 + "\n    ";

    while(!result.IsEmpty())
	{
        number = to_string(result.Pop());
        if(number != "0") //handles the padded 0s
		{
           isNum = true;
        }
        if(!isNum)
		{
            number = " ";
        }
		else
		{
			numSize++;
		}
    	value += number;
    }

	if(!negativeNum && (numSize < ae->GetData1().length() || numSize < ae->GetData2().length()))
	{
		answer += " ";
	}
	
	if(negativeNum)
	{
		answer += "-";
	}

	answer += value;
	answer += "\n\n";
	return answer;
}

