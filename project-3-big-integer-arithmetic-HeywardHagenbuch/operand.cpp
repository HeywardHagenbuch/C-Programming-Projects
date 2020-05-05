#include "operand.hpp"
using namespace std;

Operand::Operand()
{
	value = "";
}

Operand::Operand(string value)
{
	this->value = value;
}

bool Operand::IsNegative()
{
	if(stoi(value) < 0)
    {
		return true;
	}
	else
    {
		return false;
	}
}

string Operand::GetValue()
{
	return this->value;
}

void Operand::SetValue(string value)
{
	this->value = value;
}

int Operand::GetLengthOfString()
{
	int size = 0;
	while(value[size] != '\0')
    {
		size++;
	}
	return size;
}

void Operand::Pad(int pad) //Pads the operand with 0s so that they are equal in size
{
	string temp = "";
	for(int i = 0; i < pad; i++)
    {
		temp += "0";
	}

	temp += value;
	value = temp;
}


