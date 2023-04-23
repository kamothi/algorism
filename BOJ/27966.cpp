#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	long long cnt;
	cnt = pow((n-1),2);
	cout << cnt << "\n";
	for (int i = 2; i <= n; i++) {
		cout << 1 << " " << i << "\n";
	}
}
