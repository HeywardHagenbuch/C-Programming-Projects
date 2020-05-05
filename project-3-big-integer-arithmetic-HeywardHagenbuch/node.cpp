#include "node.hpp"
using namespace std;

Node::Node()
{   
}

Node::Node(int v, Node* n)
{
    this->next = n;
    this->value = v;
}

int Node::GetValue()
{
    return this->value;
}

Node* Node::GetNext()
{
    return this->next;
}