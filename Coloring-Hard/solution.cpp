#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18, mod = 1e9 + 7;

vector<string> all = {
    "010101" ,"010102" ,"010121" ,"010201" ,"010202" ,"012101" ,
    "012120" ,"012121" ,"012201" ,"020101" ,"020102" ,"020201" ,
    "020202" ,"020212" ,"021102" ,"021202" ,"021210" ,"021212" ,
    "101010" ,"101012" ,"101020" ,"101210" ,"101212" ,"102010" ,
    "102020" ,"102021" ,"102210" ,"120012" ,"120201" ,"120202" ,
    "120212" ,"121010" ,"121012" ,"121202" ,"121210" ,"121212" ,
    "201010" ,"201012" ,"201020" ,"201120" ,"202010" ,"202020" ,
    "202021" ,"202120" ,"202121" ,"210021" ,"210101" ,"210102" ,
    "210121" ,"212020" ,"212021" ,"212101" ,"212120" ,"212121"
};

int n;
int dp[3][3][3][3][3][3][1000];

int go(int id, int x00, int x01, int x02, int x10, int x11, int x12){
    if(id > n)
        return 1;
    int &ans = dp[x00][x01][x02][x10][x11][x12][id];
    if(~ans)
        return ans;
    ans = 0;

    string prev;
    prev.push_back((char)('0' + x00));
    prev.push_back((char)('0' + x01));
    prev.push_back((char)('0' + x02));
    prev.push_back((char)('0' + x10));
    prev.push_back((char)('0' + x11));
    prev.push_back((char)('0' + x12));

    for(string &s : all){
        bool ok = true;
        for(int i = 0; i < 6; i++) if(s[i] == prev[i]){
            ok = 0;
            break;
        }
        if(!ok) continue;
        ans = (ans + go(id + 1, s[0] - '0', s[1] - '0', s[2] - '0', s[3] - '0', s[4] - '0', s[5] - '0')) % mod;
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

    // w = 2, l = 3, h = given (n)

    memset(dp, -1, sizeof(dp));
    cin >> n;
    int ans = 0;
    for(string &s : all){
        ans = (ans + go(2, s[0] - '0', s[1] - '0', s[2] - '0', s[3] - '0', s[4] - '0', s[5] - '0')) % mod;
    }

    cout << ans;
}
