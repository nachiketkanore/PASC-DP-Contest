#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18, mod = 1e9 + 7;
const int color = 3;

int dp[3][3][3][3][3][4005];
int n;

vector<string> layer = {
    "01010", "01012", "01020", "01021", "01201",
    "01202", "01210", "01212", "02010", "02012",
    "02020", "02021", "02101", "02102", "02120", 
    "02121", "10101", "10102", "10120", "10121", 
    "10201", "10202", "10210", "10212", "12010", 
    "12012", "12020", "12021", "12101", "12102", 
    "12120", "12121", "20101", "20102", "20120", 
    "20121", "20201", "20202", "20210", "20212", 
    "21010", "21012", "21020", "21021", "21201", 
    "21202", "21210", "21212"
};  //total = 48

int go(int id, int x0, int x1, int x2, int x3, int x4){
    if(id > n)
        return 1;

    int &ans = dp[x0][x1][x2][x3][x4][id];
    if(~ans)
        return ans;
    ans = 0;

    string prev;
    prev.push_back((char)('0' + x0));
    prev.push_back((char)('0' + x1));
    prev.push_back((char)('0' + x2));
    prev.push_back((char)('0' + x3));
    prev.push_back((char)('0' + x4));

    for(string &s : layer){
        bool ok = 1;
        for(int i = 0; i < 5; i++)
            if(prev[i] == s[i]){
                ok = 0;
                break;
            }
            if(!ok) continue;
        ans = (ans + go(id + 1, s[0] - '0', s[1] - '0', s[2] - '0', s[3] - '0', s[4] - '0')) % mod;
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
    coloring 5 x N grid, with colors [1,3] such that no two adj-cells have same color
    */
    cin >> n;

    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for(string &s : layer){
        ans = (ans + go(2, s[0] - '0', s[1] - '0', s[2] - '0', s[3] - '0', s[4] - '0')) % mod;
    }

    cout << ans << '\n';
}
