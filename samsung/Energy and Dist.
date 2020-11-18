#include <bits/stdc++.h>
using namespace std;
const int INF = 2E9;

int dp[4040][1010][5];
inline int fun(int i, int j, int k, vector<int> &a, vector<int> &b) {
    if (i < 0) return INF;
    if (j == 0) return 0;
    if (k < 0) return INF;
    if (dp[i][j][k] != -1) return dp[i][j][k];
    return dp[i][j][k] = min(fun(i, j, k - 1, a, b), b[k] + fun(i - a[k], j - 1, k, a, b));
}

int getMinTime(vector<int> &cost, vector<int> &time, int H, int D) {
    memset(dp, -1, sizeof dp);
    return fun(H, D, 4, cost, time);
}

int main() {
    int t (14);
    vector<int> cost {4, 5, 2, 3, 6};
    vector<int> time {200, 210, 230, 235, 215};
    cout << getMinTime(cost, time, t, 4);
    return 0;
}
