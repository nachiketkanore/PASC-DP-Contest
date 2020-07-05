#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

string s;
int n;
string u;
set<string> f;
int dp[N];

int go(int id){
    if(id >= n)
        return 1;

    int &ans = dp[id];
    if(~ans)
        return ans;
    ans = 0;

    string one = s.substr(id,1);
    if(f.count(one))
        ans |= go(id + 1);
    if(id + 1 < n){
        one = s.substr(id,2);
        if(f.count(one))
            ans |= go(id + 2);
    }
    if(id + 2 < n){
        one = s.substr(id,3);
        if(f.count(one))
            ans |= go(id + 3);
    }
    return ans;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    /*
    add test cases
    */

    memset(dp, -1, sizeof(dp));
    cin >> s;
    n = sz(s);
    int k;
    cin >> k;
    FOR(i,1,k){
        cin >> u;   //contains strings of length : 1,2,3
        f.insert(u);
    }

    cout << (go(0) ? "YES" : "NO") << '\n';
}
