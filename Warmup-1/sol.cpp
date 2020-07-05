#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18, mod = 1e9 + 7;

string s;
int n;
bool yes[N];
int dp[3][N];

int go(int id, int which){
    if(which == 3)
        return 1;
    
    if(id >= n)
        return 0;
    int &ans = dp[which][id];
    if(~ans)
        return ans;

    ans = go(id + 1, which) % mod;

    if(which == 0){
        if(s[id] == 'P')
            ans = (ans + go(id + 1, which + 1)) % mod;
    }else if(which == 1){
        if(yes[id])
            ans = (ans + go(id + 1, which + 1)) % mod;
    }else if(which == 2){
        if(s[id] == 'T')
            ans = (ans + go(id + 1, which + 1)) % mod;
    }
    return ans;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    /*
    number of subsequences "PICT" where "IC" come together in original string
    */

    memset(dp, -1, sizeof(dp));
    cin >> s;
    n = sz(s);
    for(int i = 1; i < n; i++)
        if(s[i - 1] == 'I' && s[i] == 'C')
            yes[i] = 1;

    int ans = go(0,0);
    cout << ans << '\n';
}
