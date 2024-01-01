#include<bits/stdc++.h>
using namespace std;


class Node
{
    public:
    Node* next;
    int data;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void evenodll(Node* &head1)
{
    Node* oddptr = head1;
    Node* evenptr = head1->next;
    Node* evenstart = evenptr;
    while ((oddptr->next !=NULL) && (evenptr->next !=NULL))
    {
        oddptr->next = evenptr->next;
        oddptr = oddptr->next;
        evenptr->next = oddptr->next;
        evenptr = evenptr->next;
    }   
    oddptr->next = evenstart;
}
void printNode(Node* root)
{
    Node* it = root;
    while(it)
    {
        cout<<it->data<<"->";
        it =it->next;
    }
    
}
//17 -> 15 -> 8 -> 9 -> 2 -> 4 -> 6 -> NULL
signed main()
{
    Node* root = new Node(17);
    root->next = new Node(15);
    root->next->next = new Node(8);
    root->next->next->next = new Node(9);
    root->next->next->next->next = new Node(2);
    root->next->next->next->next->next = new Node(4);
    root->next->next->next->next->next->next = new Node(6);
    evenodll(root);
    printNode(root);


}