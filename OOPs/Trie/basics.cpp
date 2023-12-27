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


class Trie
{
    public:
        class node
        {
        public:
            bool end;
            node* next[26];
            node()
            {
                end = false;
                rep(i,0,26)
                {
                    next[i] = NULL;
                }
            }
        };
        node* trie;
        Trie()
        {
            trie = new node();
        }
void insert(string word)
{
    int i(0);
    node* it = trie;
    while (i<word.size())
    {
        if ((it->next[word[i] - 'a']) == NULL)
        {
            it->next[word[i]-'a'] = new node();
        }
        it = it->next[word[i]-'a'];
        i++;   
    }
    it->end=  true;
}
bool search(string word)
{
    int i(0);
    node* it = trie;
    while(i<word.size())
    {
        if((it->next[word[i]-'a']) == NULL)
        {
            return false;
        }
        it = it->next[word[i]-'a'];
        i++;
    }
    return it->end;
}
};

signed main()
{

    Trie* myTrie = new Trie();
    vector<string> words = {"ayush","dassi"};
    for(auto w:words)
    {
        myTrie->insert(w);
    }
    cout<<myTrie->search("dassi")<<endl;
    cout<<myTrie->search("yuji")<<endl;
}

