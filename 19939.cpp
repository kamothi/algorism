#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	int sum = 0;
	cin >> n >> k;

	for (int i = 1; i <= k; i++) sum += i;
	n -= sum;
	if (n < 0) cout << -1;
	else {
		if (n%k == 0) cout << k - 1;
		else cout << k;
	}

}
