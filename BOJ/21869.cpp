#include<iostream>

using namespace std;

int N;
int cnt = 0;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	if (N > 1) cnt = N * 2 - 2;
	else cnt = 1;
	cout << cnt << '\n';
	for (int i = 1; i <= N; i++) cout << 1 << " " << i << '\n';
	for (int i = 2; i < N; i++) cout << N << " " << i << '\n';
}
