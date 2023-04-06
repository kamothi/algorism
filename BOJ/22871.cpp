#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	ll  arr[5000] = { 0, };
	ll dp[5000] = { 0, };
	ll temp;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 1; i < n; i++) dp[i] = 2e9;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			temp = max((i - j) * (1 + abs(arr[j] - arr[i])), dp[j]);
			dp[i] = min(dp[i], temp);
		}
	}
	cout << dp[n - 1];
}
