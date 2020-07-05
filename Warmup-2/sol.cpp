#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e6 + 2, mod = 1e9 + 7;

int n, dp[20][N];

int go(int power, int rem){
    if(power >= 20)
        return 0;
    if(rem <= 0)
        return rem == 0;
    int &ans = dp[power][rem];
    if(~ans)
        return ans;
    ans = go(power + 1, rem) % mod;
    ans = (ans + go(power, rem - (1 << power))) % mod;
    return ans;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << go(0,n) << '\n';
}
