//Heyward Hagenbuch
//COP3530 - Project 4
//Node Hpp

#ifndef NODE_HPP_
#define NODE_HPP_
#include "book.hpp"

template <typename T>
class Node
{
    private:
        T* value;     
        Node<T>* left;
        Node<T>* right;

	public:
        Node (T* value);
        T* GetValue();
        void SetLeft(Node<T>* newLeft);
        Node<T>* GetLeft();
        void SetRight(Node<T>* newRight);
        Node<T>* GetRight();
};
#endif