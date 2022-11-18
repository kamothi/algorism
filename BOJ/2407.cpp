#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n, m;

string dp[101][101];

string Add_string(string a, string b) {
	int sum=0;
	string num = "";
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int size = max(a.size(), b.size());
	for (int i = 0; i < size || sum; i++) {
		if (a.size() > i) {
			sum += (a[i] - '0');
		}
		if (b.size() > i) {
			sum += (b[i] - '0');
		}
		num.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(num.begin(), num.end());
	return num;
}

string combination(int n, int m) {
	if (m == 0) return dp[n][m] = "1";
	if (n == m) return dp[n][m] = "1";
	if (dp[n][m] != "") return dp[n][m];
	return dp[n][m] = Add_string(combination(n - 1, m) , combination(n - 1, m - 1));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string result;
	cin >> n >> m;

	if (m / 2 <= m) m = n - m;
	result = combination(n, m);
	cout << result;
}
