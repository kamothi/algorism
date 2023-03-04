#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	double sum = 0;
	int cnt = 0;
	int n, l, temp;
	vector<int> a;

	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		a.push_back(temp);
	}

	for (int i = 0; i < n; i++) {
		sum +=  a[i];
		if (i > l - 1) sum -= a[i - l];
		if (sum >= 129 && sum <= 138) cnt++;
	}
	cout << cnt;
}
