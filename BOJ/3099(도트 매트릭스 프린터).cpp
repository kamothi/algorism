#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	string str;
	int MIN = 20001;
	int dp[10000] = { 0, };
	cin >> str;
	dp[0] = 2;

	for (int i = 1; i < str.size(); i++) {
		MIN = 20001;
		for (int j = i-1; j >= 0; j--) {
			if (str[i] == str[j]) {
				MIN = min(MIN, (dp[j] + (i - j-1) * 2 + 1));
				dp[i] = MIN;
			}
			else {
				MIN = min(MIN, (dp[j] + (i - j-1) * 2 + 2));
				dp[i] = MIN;
			}

		}
	}

	cout << dp[str.size() - 1];
}
