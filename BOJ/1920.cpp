#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M, num;
	vector<int> a,b;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		a.emplace_back(num);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> num;
		b.emplace_back(num);
	}

	sort(a.begin(), a.end());
	for (int i = 0; i < M; i++) {
		if (binary_search(a.begin(), a.end(), b[i])) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
}
