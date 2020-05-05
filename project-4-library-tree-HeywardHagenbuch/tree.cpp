//Heyward Hagenbuch
//COP3530 - Project 4
//Tree Cpp

#include "tree.hpp"
using namespace std;

template <typename T>
Tree<T>::Tree()
{
    this->root = nullptr;
    this->showFullDetails = false;
}

//Inserting into the binary tree Book*
template <typename T>
void Tree<T>::Insert(Book* b1)
{
    Node<T>* newNode = new Node<T>(b1);
    if (this->root == nullptr)
    {
        this->root = newNode;
        return;
    }
    Node<T>* currentNode = this->root;
    while (currentNode != nullptr)
    {
        if (currentNode->GetValue()->GetTitle() > newNode->GetValue()->GetTitle())
        {
            if (currentNode->GetLeft() == nullptr) // about to fall off of the tree
            {
                currentNode->SetLeft(newNode);
                break;
            }
            currentNode = currentNode->GetLeft();
        }
        else
        {
            if (currentNode->GetRight() == nullptr) // about to fall off of the tree
            {
                currentNode->SetRight(newNode);
                break;
            }
            currentNode = currentNode->GetRight();
        }  
    }
}

template <typename T>
string Tree<T>::Traverse()
{
    this->showFullDetails = true;
    return this->RecursivePrintTree(this->root);
}

template <typename T>
string Tree<T>::Traverse(bool showFullDetails) 
{
	this->showFullDetails = showFullDetails;
	return this->RecursivePrintTree(this->root);
}

template<typename T>
string Tree<T>::RecursivePrintTree(Node<T>* subtreeRoot)
{
	if (subtreeRoot == nullptr)
    {
		return "";
	}
	ostringstream printedTree;

	printedTree << this->RecursivePrintTree(subtreeRoot->GetLeft());
	
    if (showFullDetails == true) 
    {
		printedTree << subtreeRoot->GetValue()->GetTitle() << ",";
		printedTree << " by " << subtreeRoot->GetValue()->GetAuthor() << "\n";
		printedTree << "\tSubject: " << subtreeRoot->GetValue()->GetSubject() << "\n";
		printedTree << "\tPublisher: " << subtreeRoot->GetValue()->GetPublisher() << "\n";
		printedTree << "\t" << subtreeRoot->GetValue()->GetNumAvailable();
		printedTree << " " << subtreeRoot->GetValue()->GetFormat() << " copies available\n";
	}

	else 
    {
		printedTree << subtreeRoot->GetValue()->GetTitle() << "\n";
	}

	printedTree << this->RecursivePrintTree(subtreeRoot->GetRight());
	return printedTree.str();
}

//Search algorithm for Binary Search Tree
template <typename T>
Node<T>* Tree<T>::Search(string found)
{
	Node<T>* currentNode = this->root;
	while (currentNode != nullptr) 
    {
		if (currentNode->GetValue()->GetTitle() == found) 
        {
			return currentNode;
		}
		else if (currentNode->GetValue()->GetTitle() < found) 
        {
			if (currentNode->GetRight() == nullptr) 
            {
				return nullptr;
			}
			else 
            {
				currentNode = currentNode->GetRight();
			}
		}
		else 
        {
			if (currentNode->GetLeft() == nullptr) 
            {
				return nullptr;
			}
			else 
            {
				currentNode = currentNode->GetLeft();
			}
		}
	}
	return currentNode;
}

//Destructor
template <typename T>
Tree<T>::~Tree() 
{
	this->DeleteSubTree(this->root);
}

template <typename T>
void Tree<T>::DeleteSubTree(Node<T>* subtreeRoot) 
{
	if (subtreeRoot == nullptr) 
    {
		return;
	}
	this->DeleteSubTree(subtreeRoot->GetRight());
	this->DeleteSubTree(subtreeRoot->GetLeft());
	delete subtreeRoot;
}


template class Tree<Book>;