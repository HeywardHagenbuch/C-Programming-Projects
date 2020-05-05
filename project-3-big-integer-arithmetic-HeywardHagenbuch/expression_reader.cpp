#include "expression_reader.hpp"
using namespace std;

ExpressionReader::ExpressionReader()
{
}

void ExpressionReader::ReadExpressions(string fileInput) //reads arithmetic expressions from a file
{
	this->fileInput = fileInput;
	ifstream file;
	string next, one, two = "";
	char action = ' ';
	int i = 0;

	file.open(fileInput.c_str());
	while(getline(file, next))
    {
		istringstream erStream(next);
		string temp;
		while(getline(erStream, temp, ' '))
        {
			if(next != "\n")
            {
				if(i == 0)
                {
					one = temp;
				}
				else if(i == 1)
                {
					action = temp[0];
				}
				else if(i == 2)
                {
					two = temp;
					i = -1;
				}
				i++;
			}
		}

		ArithmeticExpression* newAE = new ArithmeticExpression(one, two, action);
		expressions.push_back(newAE);
    }
	file.close();	
}


string ExpressionReader::ToString()
{
	string result = "";
	ifstream file(fileInput);
	stringstream ss;
	ss << file.rdbuf();
	file.close();
	return ss.str();	
}

string ExpressionReader::PrintAll()
{
	string result = "";
	for(unsigned int i = 0; i < expressions.size(); i++)
    {
		BigIntegerArithmetic bia(expressions.at(i));
		bia.SetUp();
		bia.Add();
		result = result + bia.ShowResults();
	}
	return result;
}
