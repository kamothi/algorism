#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;
	int u = 1;
	int first = 0;
	while (m--) {
		int t, r;
		cin >> t >> r;
		first += r;
		if (first > k) {
			cout << u << " " << 1;
			return 0;
		}
	u++;
	}
	cout << -1;
}
