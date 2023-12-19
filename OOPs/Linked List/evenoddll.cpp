#include<iostream>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>


class node
{
    public:
        int data;
        node* next;
        node(int val)
        {
            data = val;
            next = NULL;
        }
};
void insertAttail(node* &head,int val)
{
    node* n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node* temp = head;
    while (temp->next != NULL)
    {
        temp= temp->next;
    }
    temp->next = n;
}
void evenodll(node* &head1)
{
    node* oddptr = head1;
    node* evenptr = head1->next;
    node* evenstart = evenptr;
    while ((oddptr->next !=NULL) && (evenptr->next !=NULL))
    {
        oddptr->next = evenptr->next;
        oddptr = oddptr->next;
        evenptr->next = oddptr->next;
        evenptr = evenptr->next;
    }   
    oddptr->next = evenstart;
    // evenptr->next = NULL;
    // if (oddptr->next != NULL)
    // {
    //     evenptr->next == NULL; 
    // }
}
void display(node* head)
{
    node* temp = head;
    while (temp !=NULL)
    {
        cout<<temp->data<<"->";
        temp= temp->next;
    }
    cout<<"NULL"<<endl;
}
signed main()
{
    node* head1 = NULL;
    insertAttail(head1,1);
    insertAttail(head1,2);
    insertAttail(head1,3);
    insertAttail(head1,4);
    insertAttail(head1,5);
    insertAttail(head1,6);
    insertAttail(head1,7);
    insertAttail(head1,8);
    insertAttail(head1,9);
    // display(evenodll(head1));
    evenodll(head1);
    display(head1);
}