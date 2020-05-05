#ifndef OPERAND_HPP
#define OPERAND_HPP
#include <string>
class Operand
{
    private:
		std::string value;
    
    public:
		Operand();
		Operand(std::string value);
		bool IsNegative();
		std::string GetValue();
        void SetValue(std::string);
		int GetLengthOfString();
		void Pad(int padNum);		
};
#endif
