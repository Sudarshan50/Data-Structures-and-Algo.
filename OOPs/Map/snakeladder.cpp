#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = j;i<k;i++)
#define vi vector<int>
#define ll left 
#define rr right
#define vvi vector<vector<int>>
#define vb vector<bool>
const int mod = 1e9+7;
const int N = 1e5+2;
#define mk unordered_map<int,int>
vector<int> parent(N);
vb vis(N,false);

signed main()
{
   vi adj(101,0);
   int s,l;
   cin>>l;
   mk ladder;
   rep(i,0,l)
   {
    int u,v;cin>>u>>v;
    ladder[u] =v;
   }
   cin>>s;
   mk snake;
   rep(i,0,s)
   {
        int u,v;cin>>u>>v;
        snake[u] =v;
    }
    bool found = 0;
    queue<int>q;
    vis[1] = true;
    int move = 0;
    q.push(1);
    while (!q.empty() && !found)
    {
        int sz = q.size();
        while (sz--)
        {
            int t = q.front();
            q.pop();
            rep(die,1,7)
            {
                if (die+t == 100)
                {
                    found = true;
                }
                else if (t+die<=100 && ladder[t+die] && !vis[ladder[t+die]])
                {
                    vis[ladder[t+die]] = true;
                    if (ladder[t+die] == 100)
                    {
                        found = true;
                    }
                    q.push(ladder[t+die]);
                }
                else if (t+die<=100 && snake[t+die] && !vis[snake[t+die]])
                {
                    vis[snake[t+die]] = true;
                    if (snake[t+die] == 100)
                    {
                        found = true;
                    }
                    q.push(snake[t+die]);   
                }
                else if (die+t<=100 && !snake[t+die] && !ladder[t+die] && !vis[t+die])
                {
                    vis[t+die] = true;
                    q.push(t+die);
                }
            }
        }
        move++;
    }
    if (found)
    {
        cout<<move<<endl;
    }
    else    
        cout<<-1<<endl;
}