#include<iostream>

using namespace std;
int n, s;
int arr[20];
int cur = 0;
int cnt = 0;
void dfs(int a) {
	if (a == n) return;
	if (cur + arr[a] == s) cnt++;
	dfs(a + 1);

	cur += arr[a];
	dfs(a + 1);

	cur -= arr[a];
}

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> arr[i];
	dfs(0);
	cout << cnt;
}
