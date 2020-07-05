#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

int n;
int val[20];
int dp[18][1 << 18];

int go(int prev, int mask){
    if(__builtin_popcountll(mask) == n)
        return 0;
    int &ans = dp[prev][mask];
    if(~ans)
        return ans;
    ans = 0;
    FOR(next,0,n-1) if((mask >> next & 1) == 0){
        int gain = abs(val[prev] - val[next]);
        gain = gain + go(next, mask | (1 << next));
        ans = max(ans, gain);
    }
    return ans;
}

void trace(int prev, int mask){
    if(__builtin_popcountll(mask) == n)
        return ;

    int ans = go(prev, mask);   //real_max_answer

    for(int next = n - 1; next >= 0; --next) if((mask >> next & 1) == 0){
        int gain = abs(val[prev] - val[next]);
        gain = gain + go(next, mask | (1 << next));
        if(gain == ans){
            //ids.push_back(next);
            cout << next + 1 << ' ';
            return trace(next, mask | (1 << next));
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    memset(dp, -1, sizeof(dp));
    cin >> n;
    FOR(i,0,n-1){
        cin >> val[i];
    }
    int ans = -inf;
    FOR(start,0,n-1){
        int get = go(start, 1 << start);
        ans = max(ans, get);
    }
    cout << ans << '\n';

    for(int start = n - 1; start >= 0; --start){
        int get = go(start, 1 << start);
        if(get == ans){
            cout << start + 1 << ' ';
            //ids.push_back(start);
            trace(start, 1 << start);
            return 0;
            //break;
        }
    }

    // int fake = 0;

    // for(int i = 1; i < sz(ids); i++){
    //     fake += abs(val[ids[i - 1]] - val[ids[i]]);
    // }

    // assert(fake == ans);
    // cout << fake << " == " << ans << '\n';
}