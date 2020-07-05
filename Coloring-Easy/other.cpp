#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18, mod = 1e9 + 7;
const int color = 3;

vector<string> layer1;
int n;


void go(string s){
    if(sz(s) == 5){
        bool chk = 1;
        for(int i = 1; i < 5; i++)
            chk &= s[i] != s[i - 1];
        assert(chk);
        layer1.push_back(s);
        return;
    }
    for(int i = 0; i < color; i++){
        if(sz(s) == 0){
            s.push_back(char('0' + i));
            go(s);
            s.pop_back();
        }else if(s.back() != (char)('0' + i)){
            s.push_back(char('0' + i));
            go(s);
            s.pop_back();
        }
    }
}

int dp[3][3][3][3][3][305];

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

    for(string &s : layer1){
        bool ok = 1;
        for(int i = 0; i < color; i++)
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
    coloring 5 x N grid, with colors [1,5] such that no two adj-cells have same color
    */

    for(int i = 0; i < color; i++){
        string s;
        s.push_back(char('0' + i));
        go(s);
    }

    cout << sz(layer1) << '\n' << '\n';
    for(string &s : layer1)
        cout << s << '\n';
    // cin >> n;

    // memset(dp, -1, sizeof(dp));
    // int ans = 0;
    // for(string &s : layer1){
    //     ans = (ans + go(2, s[0] - '0', s[1] - '0', s[2] - '0', s[3] - '0', s[4] - '0')) % mod;
    // }

    // cout << ans << '\n';
}
