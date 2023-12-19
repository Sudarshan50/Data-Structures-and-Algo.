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
//Iterative way....
node* sortedll(node* &head1,node* &head2)
{
    node* dummy = new node(-1);
    node* temp = dummy;
    node* ptr1 = head1;
    node* ptr2 = head2;
    while ((ptr1 !=NULL) && (ptr2 != NULL) )
    {
        if (ptr1->data <ptr2->data)
        {
            temp->next = ptr1;
            ptr1= ptr1->next;
        }
        else
        {
            temp->next = ptr2;
            ptr2 = ptr2->next;
        }
        temp = temp->next;
    }
    while (ptr1!=NULL)
    {
        // insertAttail(dummy,ptr1->data);
        temp->next = ptr1;
        ptr1= ptr1->next;
        temp = temp->next;
    }
    while (ptr2!=NULL)
    {
        temp->next = ptr2;
        ptr2= ptr2->next;
        temp = temp->next;
    }

    return dummy->next;
}
//Recursive way..
node* merge2ll(node* &head1 ,node* &head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL )
    {
        return head1;
    }

    node* result;
    if (head1->data < head2->data)
    {
        result = head1;
        result->next = merge2ll(head1->next,head2);
    }
    else
    {
        result = head2;
        result->next= merge2ll(head1,head2->next);
    }
    return result;
    
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
    insertAttail(head1,2);
    insertAttail(head1,3);
    insertAttail(head1,4);
    insertAttail(head1,5);
    node* head2 = NULL;
    insertAttail(head2,10);
    insertAttail(head2,11);
    insertAttail(head2,12);
    insertAttail(head2,13);
    // display(sortedll(head2,head1));
    display(merge2ll(head1,head2));
}