#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 200 + 2, inf = 1e18;

int mat[N][N];
int info[N][N];
int n, m, canTakeElements;
int dp[N][N];

int go(int id, int rem){
    if(rem < 0)
        return -inf;
    if(id > n)
        return 0;
    int &ans = dp[id][rem];
    if(~ans)
        return ans;
    ans = -inf;
    FOR(take, 0, m){
        int get = info[id][take] + go(id + 1, rem - take);
        ans = max(ans, get);
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

    memset(dp, -1, sizeof(dp));
    //500, 500, 500 => constraints
    cin >> n >> m >> canTakeElements;
    FOR(i,1,n) FOR(j,1,m){
        cin >> mat[i][j];
        mat[i][j] += mat[i][j - 1];
    }

    FOR(i,1,n) FOR(j,1,m) info[i][j] = -inf;

    FOR(day,1,n){
        FOR(i,1,m) FOR(j,i,m){
            int sum = mat[day][j] - mat[day][i - 1];
            int howmany = j - i + 1;
            info[day][howmany] = max(info[day][howmany], sum);
        }
            info[day][0] = 0;
    }
    cout << go(1,canTakeElements);
}
