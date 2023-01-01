#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b, r;
	int n;
	int MAX;
	int arr[1000][2];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i][0] >> arr[i][1];
	for (int i = 0; i < n; i++) {
		a = arr[i][0];
		b = arr[i][1];
		while (a % b != 0) {
			r = a % b;
			a = b;
			b = r;
		}
		cout << arr[i][0] * arr[i][1]/b << " " << b << "\n";
	}
}
