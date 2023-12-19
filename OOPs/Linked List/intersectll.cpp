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
void intresecter(node* &l1,node* &l2,int pos)
{
    node* temp = l1;
    pos--;
    while (pos--)
    {
        temp= temp->next;
    }
    node* temp2 = l2;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp;
}
int length(node* head)
{
    int l = 0;
    node* temp = head;
    while (temp->next != NULL)
    {
        temp=temp->next;
        l++;
    }
    return l;
}
int interdetec(node* &l1,node* &l2)
{
    int lo1 = length(l1);
    int lo2 = length(l2);
    int c = lo1-lo2;
    node* ptr1 = l1;
    node* ptr2 = l2;
    while (c!=0)
    {
        ptr1=ptr1->next;
        c--;
    }
    while (ptr2->next !=NULL)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }
        ptr2 = ptr2->next;
    }
    return false;
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
    node* l1 =NULL;
    insertAttail(l1,1);
    insertAttail(l1,2);
    insertAttail(l1,3);
    insertAttail(l1,4);
    insertAttail(l1,5);
    insertAttail(l1,6);
    node* l2 = NULL;
    insertAttail(l2,1);
    insertAttail(l2,2);
    insertAttail(l2,3);
    intresecter(l1,l2,5);
    display(l1);  
    cout<<interdetec(l1,l2)<<endl;

}