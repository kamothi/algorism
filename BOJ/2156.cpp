#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int input[10001] = { 0, };
	int arr[10001] = { 0, };

	for (int i = 1; i <= n; i++) cin >> input[i];

	arr[1] = input[1];
	arr[2] = arr[1] + input[2];
	for (int i = 3; i <= n; i++) {
		arr[i] = max({ arr[i - 3] + input[i - 1] + input[i],arr[i - 1],arr[i - 2] + input[i] });
	}
	cout << arr[n];
}
