//Heyward Hagenbuch
//COP3530 - Project 4
//Tree Hpp

#ifndef TREE_HPP_
#define TREE_HPP_
#include <string>
#include <sstream>
#include <iostream>
#include "node.hpp"
#include "book.hpp"

template <typename T>
class Tree
{
    private:
        Node<T>* root;
        bool showFullDetails;

    public:
        Tree();
        ~Tree();
        void Insert(Book* b1);
        void DeleteSubTree(Node<T>*);
        std::string Traverse();
        std::string Traverse(bool showFullDetails);
	    std::string RecursivePrintTree(Node<T>*);
        Node<T>* Search(std::string found);
};
#endif 