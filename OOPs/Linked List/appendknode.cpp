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
//YOu may also use length wala approach it will more analytical...
void knode(node* &head, int k)
{
    int count = 1;
    node* ptr1 = head;
    node* ptr3 = head;
     while (count!=k)
     {
        if (count<k)
        {
            ptr3= ptr3->next;
        }
        
        ptr1 = ptr1->next;
        count++;
    }
    node* ptr2 = ptr1;
    while (ptr2->next !=NULL)
    {
        ptr2 = ptr2->next;
    }
    ptr2->next = head;
    head = ptr1->next;
    ptr3->next = NULL;


}
void display(node* head)
{
    node* temp = head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
signed main()
{
    node* head = NULL;
    insertAttail(head,1);
    insertAttail(head,2);
    insertAttail(head,3);
    insertAttail(head,4);
    insertAttail(head,5);
    insertAttail(head,6);
    
    knode(head,3);
    display(head);
}