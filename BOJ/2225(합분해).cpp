#include<iostream>

using namespace std;
typedef long long LL;
int main() {
	LL dp[201][201] = { 0, };
	int n, k;

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		dp[i][1] = 1;
	}
	for (int i = 1; i <= k; i++) {
		dp[1][i] = i;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= k; j++) {
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 1000000000;
		}
	}
	cout << dp[n][k];
}
