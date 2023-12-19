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
void circular(node* &head1)
{
    node* temp = head1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head1;
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
void insnodeinccll(node* head1,int val)
{
    node* temp1 = head1;
    node* n = new node(val);
    while (temp1->next != head1)
    {
        temp1 = temp1->next;
    }
    temp1->next = n;
    n->next = head1;
}
void deleteAtTail(node* &head1)
{
    node* temp1 = head1;
    while (temp1->next->next != head1)
    {
        temp1 = temp1->next;
    }
    node* todelete = temp1->next;
    delete todelete;
    temp1->next = head1;
}
void deleteathead(node* &head1)
{
    node* todelete = head1;
    node* temp1 = head1;
    while (temp1->next != head1)
    {
        temp1 = temp1->next;
    }
    head1 = head1->next;
    temp1->next = head1;
    delete todelete;
}


signed main()
{
    node* head1 = NULL;
    insertAttail(head1,2);
    insertAttail(head1,3);
    insertAttail(head1,4);
    insertAttail(head1,5);
    circular(head1);
    insnodeinccll(head1,6);
    deleteathead(head1);
    display(head1);
}