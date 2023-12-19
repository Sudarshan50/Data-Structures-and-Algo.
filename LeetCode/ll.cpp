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
node* summer(node* &l1,node* &l2)
{
    node* temp1 = l1;
    node* temp2 = l2;
    int val1,val2 = 0;
    int ctr1 = 0;
    int ctr2 = 0;
    while (temp1!= NULL )
    {
        val1 += (pow(10,ctr1))*(temp1->data);
        ctr1++;
        temp1=temp1->next;
    }
    while (temp2!= NULL )
    {
        val2 += (pow(10,ctr2))*(temp2->data);
        ctr2++;
        temp2=temp2->next;
    }
    node* ans;
    if (val1== 0 && val2 == 0)
    {
        ans = new node(0);
        return ans;
    }
    val1+=(val2-1);
    int check = 0;
    while (val1>0)
    {
        node* temp = ans;
        int c = val1%10;
        if (check == 0)
        {
            ans = new node(c);
        }
        else
        {
            node *n = new node(c);
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = n;
        }
        val1/=10;
        check++;
    }
    return ans;    
}
void display(node* head)
{
    node* temp = head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

signed main()
{
    
    node* l1 = NULL;
    node* l2 = NULL;
    int n1,n2;
    cin>>n1>>n2;
    rep(i,0,n1)
    {
        int c1;
        cin>>c1;
        insertAttail(l1,c1);
    }
    rep(i,0,n2)
    {
        int c2;
        cin>>c2;
        insertAttail(l2,c2);
    }
    display(summer(l1,l2));
     
}