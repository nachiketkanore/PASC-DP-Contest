#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18, mod = 1e9 + 7;

int k;

int cnt = 0;

set<vector<vector<int>>> all;

void chk(std::vector<int> one, std::vector<int> two){
    assert(sz(one) == k && sz(two) == k);
    bool self1 = true, self2 = true, adj1 = true;
    for(int i = 0; i < k; i++){
        if(i){
            self1 &= one[i] != one[i - 1];
            self2 &= two[i] != two[i - 1];
        }
        adj1 &= one[i] != two[i];
    }
    if(adj1 && self1 && self2){
        all.insert({one, two});
    }
}

void go(vector<int> one, vector<int> two){
    if(sz(one) == k && sz(two) == k){
        chk(one, two);
        return;
    }

    if(sz(one) != k){
        for(int i = 0; i < k; i++){
            if(sz(one) && (one.back() == i)) continue;
            one.push_back(i);
            go(one, two);
            one.pop_back();
        }
    }
    else if(sz(two) != k){
        for(int i = 0; i < k; i++){
            if(sz(two) && (two.back() == i)) continue;
            two.push_back(i);
            go(one, two);
            two.pop_back();
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

    k = 3;
    vector<int> one, two;
    go(one, two);

    cout << sz(all) << '\n';
    for(auto it : all){
        cout << ++cnt << ")\n";
        for(auto x : it){
            for(auto y : x)
                cout << y;
            cout << '\n';
        }
            cout << '\n';
    }
}
