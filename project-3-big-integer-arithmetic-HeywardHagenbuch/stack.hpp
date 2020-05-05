#ifndef STACK_HPP
#define STACK_HPP
#include "node.hpp"

class Stack
{
    private:   
        Node* head = nullptr; 

    public:
        Stack();
        void Push(int value); 
        int Pop(); 
        bool IsEmpty();
};
#endif