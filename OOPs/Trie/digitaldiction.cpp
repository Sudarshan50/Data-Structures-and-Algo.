#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>
#define ll left 
#define rr right
#define vvi vector<vector<int>>
#define vb vector<bool>
const int mod = 100000007;
const int N = 1e5+2;
#define mk unordered_map<int,int>

class node
{
public:
    node* next[26];
    bool end;
    node()
    {
        rep(i,0,26)
        {
            next[i] = NULL;
        }
        end = false;
    }
};
class Trie
{
    node* root;
    public:
        Trie()
        {
            root = new node();
        }
    void insert(string &s)
    {
        node* it = root;
        for(auto i:s)
        {
            if(!it->next[i-'a'])
            {
                it->next[i-'a'] = new node();
            }
            it =it->next[i-'a'];
        }
        it->end = true;
    }
    void search(string &s)
    {
        node* it = root;
        for(auto i:s)
        {
            if (!it->next[i-'a'])
            {
                cout<<"Not present"<<endl;
                insert(s);
                return;
            }
            it = it->next[i-'a'];
        }
        vector<string> sh;
        fillstring(it,s,sh,"");
        for(auto i:sh)
        {
            cout<<s<<i<<endl;
        }
    }
    void fillstring(node* it,string &s,vector<string> &sh,string cur)
    {
        if(!it)
        {
            return;
        }
        if(it->end)
        {
            sh.push_back(cur);
        }
        rep(i,0,26)
        {
            if (it->next[i])
            {
                fillstring(it->next[i],s,sh,cur+char('a'+i));
            }
        }
    }
};
signed main()
{
    Trie test;
    int n;cin>>n;
    vector<string>sh(n);
    rep(i,0,n)
    {
        cin>>sh[i];
        test.insert(sh[i]);
    }
    int t;cin>>t;
    while (t--)
    {
        string qry;
        cin>>qry;
        test.search(qry);
    }
}

