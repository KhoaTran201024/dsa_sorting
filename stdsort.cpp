#include<bits/stdc++.h>
using namespace std;

int n=1000000;
double arr[1000005];

clock_t st, en;
double duration;

void inp() {
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
}

void solve() {
    sort(arr + 1, arr + 1 + n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("test10.txt", "r", stdin);

    inp();

    st = clock();
    solve();
    en = clock();
    duration = double(en - st)/CLOCKS_PER_SEC;
    cout << duration;
    
    return 0;
}