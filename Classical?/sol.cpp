#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

int n, m;
int mat[2005][2005];
int dp[2005][2005];
vector<string> paths;
string s;

int go(int i, int j){
    if(i == 1)
        return mat[i][j];
    int c1 = -inf, c2 = -inf, c3 = -inf;
    int &ans = dp[i][j];
    if(~ans)
        return ans;
    if(i - 1 >= 1)
        c1 = mat[i][j] + go(i - 1, j);
    if(i - 1 >= 1 && j - 1 >= 1)
        c2 = mat[i][j] + go(i - 1, j - 1);
    if(i - 1 >= 1 && j + 1 <= m)
        c3 = mat[i][j] + go(i - 1, j + 1);
    return ans = max({c1, c2, c3});
}

void trace(int i, int j){
    if(i == 1)
        return ;
    int c1 = -inf, c2 = -inf, c3 = -inf;
    int ans = go(i,j);

    
    if(i - 1 >= 1 && j - 1 >= 1){ //left
        c2 = mat[i][j] + go(i - 1, j - 1);
        if(c2 == ans){
            s.push_back('L');
            return trace(i - 1, j - 1);
        }
    }
    if(i - 1 >= 1 && j + 1 <= m){   //right
        c3 = mat[i][j] + go(i - 1, j + 1);
        if(c3 == ans){
            s.push_back('R');
            return trace(i - 1, j + 1);
        }
    }
    if(i - 1 >= 1){ //up
        c1 = mat[i][j] + go(i - 1, j);
        if(c1 == ans){
            s.push_back('U');
            return trace(i - 1, j);
        }
    }
}


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    FOR(i,1,n) FOR(j,1,m){
        cin >> mat[i][j];
    }
    int ans = -inf;
    FOR(col,1,m){
        int get = go(n,col);
        ans = max(ans, get);
    }
    cout << ans << '\n';
    
    FOR(col,1,m){
        if(go(n,col) == ans){
            s.clear();
            trace(n,col);
            cout << "col = " << col << " : ";
            cout << s <<  '\n';
            paths.push_back(s);
        }
    }

    sort(paths.begin(), paths.end());
    cout << "Lexicographically min = " << paths[0] << '\n';
}
