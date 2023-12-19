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
void insertAtTail(node* &head,int val)
{
    node* n = new node(val);
    node* temp = head;
    if (head == NULL)
    {
        head = n;
        return;
    }
    while (temp->next !=NULL)
    {
        temp = temp->next;
    }
    //Currently i am a the last node...
    temp->next = n;
}
void display(node* head)
{
    node* temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
node* reversell(node* &head)
{
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;
    while (currptr != NULL)
    {
        nextptr= currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr =nextptr;
    }
    return prevptr;
}


signed main()
{
    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    display(head);
    node* newhead = reversell(head);
    display(newhead);
}