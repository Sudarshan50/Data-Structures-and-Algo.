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

void insertAtHead(node* &head,int val)
{
    node*n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    n->next = head;
    head =n;
}
bool search(node* head,int key)
{
    node* temp = head;
    while (temp->next != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
void deleteathead(node* &head)
{
    node* del = head;
    head =head->next;
    delete del;
}

void Delete(node* &head,int key)
{
    node* temp = head;
    while (temp->next->data!= key)
    {
        temp=temp->next;
    }
    node* delted = temp->next;
    temp->next = temp->next->next;
    delete delted;
}
void dipslay(node* head)
    {
        node* temp = head;
        while (temp != NULL)
        {
            cout<<temp->data<<"->";
            temp = temp->next;
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
    dipslay(head);
    insertAtHead(head,9);
    dipslay(head);
    // cout<<search(head,5)<<endl;
    Delete(head,3);
    dipslay(head);
    deleteathead(head);
    dipslay(head);

}