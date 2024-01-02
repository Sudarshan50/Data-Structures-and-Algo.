#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, k) for (int i = j; i < k; i++)
#define vi vector<int>
#define ff first
#define ss second
#define ll left
#define rr right
#define pi pair<int, int>
#define vvi vector<vector<int>>
#define vb vector<bool>
const int mod = 1e9 + 7;
const int N = 1e5 + 2;
#define int long long int
class grp
{
public:
    int sum;
    int pref;
    int suff;
    int ans;
    grp(int p, int q, int r, int s)
    {
        ans = p;
        pref = q;
        suff = r, ans = s;
    }
};
grp tree[4*N];
vi a(N);
void update(int node, int start, int end, int val, int idx)
{
    if (start == end)
    {
        if (a[start] < 0)
        {
            tree[node] = grp(0, 0, a[start], 0);
        }
        else
        {
            tree[node] = grp(a[start], a[start], a[start], a[start]);
        }
    }
    int mid = (start + end) / 2;
    if (idx <= mid)
    {
        update(2 * node, start, mid, val, idx);
    }
    else
    {
        update(2 * node + 1, mid + 1, end, val, idx);
    }
    int sum = tree[2 * node].sum + tree[2 * node + 1].sum;
    int pref = max(tree[2 * node].pref, (tree[2 * node].sum + tree[2 * node + 1].sum));
    int suff = max(tree[2 * node + 1].suff, (tree[2 * node].sum + tree[2 * node + 1].sum));
    int ans = max(tree[2 * node].ans, max(tree[2 * node + 1].ans, (tree[2 * node].suff + tree[2 * node + 1].pref)));
    tree[node] = grp(sum, pref, suff, ans);
}

void build(int node, int start, int end)
{
    if (start == end)
    {
        if (a[start] < 0)
        {
            tree[node] = grp(0, 0, a[start], 0);
        }
        else
        {
            tree[node] = grp(a[start], a[start], a[start], a[start]);
        }
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    int sum = tree[2 * node].sum + tree[2 * node + 1].sum;
    int pref = max(tree[2 * node].pref, (tree[2 * node].sum + tree[2 * node + 1].sum));
    int suff = max(tree[2 * node + 1].suff, (tree[2 * node].sum + tree[2 * node + 1].sum));
    int ans = max(tree[2 * node].ans, max(tree[2 * node + 1].ans, (tree[2 * node].suff + tree[2 * node + 1].pref)));
    tree[node] = grp(sum, pref, suff, ans);
}

signed main()
{
    int n, t;
    cin >>n>>t;
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    build(1, 0, n - 1);
    while (t--)
    {
        int idx, val;
        cin >> idx >> val;
        update(1, 0, n - 1, val, idx);
        cout << tree[1].ans << endl;
    }
}
