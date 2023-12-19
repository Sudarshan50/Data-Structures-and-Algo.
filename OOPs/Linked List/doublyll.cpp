#include<iostream>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>

class node
{
    public:
        int data;
        node* next;
        node* prev;
        node(int val)
        {
            data = val;
            next = NULL;
            prev = NULL;
        }
};
void insertAthead(node* &head,int val)
{
    node* n = new node(val);
    n->next = head;
    if (head!= NULL)
    {
        head->prev = n;
    }
    head = n;
}
void insertAtTail(node* &head,int val)
{
    if (head == NULL)
    {
        insertAthead(head,val);
        return;
    }
    node* n = new node(val);
    node* temp = head;
    while (temp->next != NULL)
    {
        temp=temp->next;
    }
    temp->next = n;
    n->prev = temp;
}
void deleteathead(node* &head)
{
    node* todelete = head;
    if (head!= NULL)
    {
        head = head->next;
    }
    head->prev = NULL;
}

void deletion(node* &head,int pos)
{
    if (head == NULL)
    {
        deleteathead(head);
        return;
    }
    
    node* temp = head;
    int count = 0;
    while (temp !=NULL && count!=pos)
    {
        count++;
        temp=temp->next;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    delete temp;
}
void display(node* head)
{
    node* temp = head;
    cout<<"NULL<->";
    while (temp!= NULL)
    {
        cout<<temp->data<<"<->";
        temp = temp->next;
    }
    cout<<"<->NULL"<<endl;
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
    // display(head);
    insertAthead(head,11);
    insertAthead(head,12);
    display(head);
    deletion(head,4);
    display(head);
}