//Heyward Hagenbuch
//COP3530 - Project 4
//Node Cpp
#include "node.hpp"

template <typename T>
Node<T>::Node (T* value)
{
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
}

template <typename T>
T* Node<T>::GetValue()
{
    return this-> value;
}

template <typename T>
void  Node<T>::SetLeft(Node<T>* newLeft)
{
    this->left = newLeft;
}

template <typename T>
Node<T>*  Node<T>::GetLeft()
{
    return this->left;
}

template <typename T>
void  Node<T>::SetRight(Node<T>* newRight)
{
    this->right = newRight;
}

template <typename T>
Node<T>*  Node<T>::GetRight()
{
    return this->right;
}

template class Node<Book>;