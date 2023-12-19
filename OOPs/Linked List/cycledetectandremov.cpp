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
void makecycle(node* &head,int pos)
{
    node* temp = head;
    node* startnode;
    int count = 1;
    while (temp->next!=NULL)
    {
        if (count == pos)
        {
            startnode = temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next = startnode;
}
bool detetctcycle(node* head)
{
    node* hare = head;
    node* tortoise= head;
    while(hare!= NULL && hare->next != NULL)
    {
        hare = hare->next->next;
        tortoise = tortoise->next;
        if (hare == tortoise)
        {
            return true;
        }
    }
    return false;
}
void removecycle(node* head)
{
    node* fast = head;
    node* slow = head;
    while (fast!= NULL && fast->next != NULL)
    {
        fast= fast->next->next;
        slow= slow->next;
        if (fast == slow)
        {
            break;
        }
    }
    fast = head;
    while (fast->next != slow->next)
    {
        fast = fast->next;
        slow = slow->next; 
    }
    slow->next = NULL;
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
    makecycle(head,5);
    // display(head);
    cout<<detetctcycle(head)<<endl;
    removecycle(head);
    cout<<detetctcycle(head)<<endl;
    display(head);

}