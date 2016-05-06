#include <iostream>
#include <new>

class Node
{
    public:
        int data;
        Node *next;
};

int main()
{
    Node *p1, *p2;
    p1 = new( std::nothrow ) Node;
    p2 = new( std::nothrow ) Node;

    p1->data = 12;
    p2->data = 34;
    p1 = p2;
    p2->next = p1;

    std::cout << p1->data << " " << p2->data << std::endl;
    std::cout << p1->next->data << " " << p2->next->data << std::endl;

    return 0;
}
