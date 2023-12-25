int longestsubs(vi &a,int n)
{
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    dp[n]= 1;
    rep(i,0,n)
    {
        if (a[n]>a[i])
        {
            dp[n] = max(dp[n],1+longestsubs(a,i));
        }
    }
    return dp[n];
}