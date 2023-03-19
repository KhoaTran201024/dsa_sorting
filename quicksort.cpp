#include<bits/stdc++.h>
using namespace std;

int n=1000000;
int arr[1000005];

clock_t st, en;
double duration;

void inp() {
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void solve(int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];

    /* partition */
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };

    /* recursion */
    if (left < j)
        solve(left, j);
    if (i < right)
        solve(i, right);

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("test2.txt", "r", stdin);

    inp();

    st = clock();
    solve(0, n-1);
    en = clock();
    duration = double(en - st)/CLOCKS_PER_SEC;
    cout << duration;

    return 0;
}