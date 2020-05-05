#ifndef NODE_HPP
#define NODE_HPP

class Node
{
    private:
        int value;
        Node* next = nullptr; //This is the creation of the pointer to the node, named "next" and set to null

    public:
        Node();
        Node(int v, Node* next = nullptr);
        int GetValue();
        Node* GetNext();

};
#endif