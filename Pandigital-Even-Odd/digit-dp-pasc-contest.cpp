#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 155, mod = 1e9 + 7, inf = 1e18;

string A, B;
int n, dp[N][2][2][2][1 << 10];
int even, odd;

int go(int pos, bool bigA, bool smallB, int freq_mask, int nonZeroTaken){
    if(pos >= n){
        int oddCnt = __builtin_popcountll(freq_mask);
        int evenCnt = 10 - oddCnt;
        return oddCnt == odd && evenCnt == even;
    }

    int &ans = dp[pos][bigA][smallB][nonZeroTaken][freq_mask];
    if(~ans)
        return ans;
    ans = 0;

    for(int i = 0; i < 10; i++){
        if(!bigA && i < A[pos] - '0')   continue;
        if(!smallB && i > B[pos] - '0') continue;

        int next_freq_mask = freq_mask;
        if(nonZeroTaken || (i != 0)){
            next_freq_mask ^= (1 << i);
        }

        ans = (ans + go(pos + 1, bigA || (i > A[pos] - '0'), smallB || (i < B[pos] - '0'), next_freq_mask, nonZeroTaken || (i != 0))) % mod;
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
        count number of integers in the range [A,B] such that:
            ** Contains N = no. of digits which occur odd no. of times in it, 
                ans M = (10 - N) no. of digits which occur even no. of times in it.

                range L to R : 1 to (10 ^ 150)
    */

    memset(dp, -1, sizeof(dp));
    cin >> A >> B;
    cin >> even >> odd;
    reverse(A.begin(), A.end());
    while(sz(A) < sz(B))
        A.push_back('0');
    reverse(A.begin(), A.end());
    n = sz(B);
    int ans = 0;

    for(int i = 0; i < 10; i++){
        if(i < A[0] - '0')  continue;
        if(i > B[0] - '0')  continue;

        int freq_mask = 0;
        if(i != 0)
            freq_mask ^= (1 << i);

        ans = (ans + go(1, i > A[0] - '0', i < B[0] - '0', freq_mask, i != 0)) % mod;
    }
    cout << ans << '\n';
}