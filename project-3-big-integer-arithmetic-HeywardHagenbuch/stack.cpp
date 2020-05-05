#include "stack.hpp"
using namespace std; 

Stack::Stack()
{
    this->head = nullptr;
}

void Stack::Push(int value) //inserts an item on the top of the stack
{
    Node* newNode = new Node(value, this->head);
    this->head = newNode;
} 

int Stack::Pop() //removes the item from the top of the stack and returns the value of that item
{
    int popVal = 0;
    if (!IsEmpty())
    {
        popVal = this->head->GetValue();
        Node* temp = this->head;
        this->head = temp->GetNext();
        delete temp;
        temp = this->head;
    }
    return popVal;    
}

bool Stack::IsEmpty() //checks if the stack is empty
{
    if (this->head != nullptr)
    {
        return false;
    }
    else
    {
        return true;
    }
}