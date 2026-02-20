#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(x...)
#endif
using namespace std;

#define ll long long
#define ld long double
#define int long long
const int M = 1e9 + 7;
const int N = 1e6 + 5;
const ll infinity = LLONG_MAX;
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1}; //Right, Down, Left, Up, Diagonals
int dy[] = {0, -1, 0, 1, 1, -1, 1, -1};
inline ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }

#define rall(v) v.rbegin(), v.rend()
#define all(v) v.begin(), v.end()
#define print(x) cout << x << '\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

void solve() 
{
    int n,now=0,ans=0;cin>>n;
    vector<int> v(n),vv(n,0);

    for(auto &x : v) cin>>x;
    for(int i=0;i<n/2;i++)
    {
        //debug(v[i],v[n-i-1]);
        if(v[i]<v[n-i-1]) vv[i]=v[n-i-1]-v[i];
        else if(v[i]>v[n-i-1]) vv[n-i-1]=-v[n-i-1]+v[i];
    }

    debug(vv);

    for(int i=0;i<n;i++)
    {
        if(vv[i]>=now )
        {
            ans+=(vv[i]-now);
            now=vv[i];
        }
        else 
        {
            now=vv[i];
        }
        //else if(vv[i]==0) now=0;
        
    }

    print(ans)
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}