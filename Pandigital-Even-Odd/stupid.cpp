#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int L, R, even, odd;
    cin >> L >> R >> even >> odd;
    int ans = 0;
    FOR(i,L,R){
        int f[10] = {0};
        int n = i;
        while(n) f[n%10]++, n/=10;
        int o = 0, e = 0;
        for(int dig = 0; dig < 10; dig++)
            o += f[dig] % 2 == 1,
            e += f[dig] % 2 == 0;
        ans += o == odd && e == even;
    }

    cout << ans;
}


