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
node* reversek(node* &head,int k)
{
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;
    int count = 0;
    while (currptr != NULL && count<k)
    {
        nextptr= currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr =nextptr;
        count++;
    }
    if (nextptr !=NULL)
    {
        head->next = reversek(nextptr,k);
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
    insertAtTail(head,5);
    insertAtTail(head,6);
    insertAtTail(head,7);
    insertAtTail(head,8);
    insertAtTail(head,9);
    insertAtTail(head,10);
    node* newhead = reversek(head,2);
    display(newhead);
}