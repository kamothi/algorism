#include<iostream>

using namespace std;

long long mul(int a, int b, int c) {
	if (b == 0) return 1;
	else if (b == 1) return a;
	else if (b % 2 == 0) {
		long long n = mul(a, b / 2, c);
		return ((n % c) * (n % c))%c;
	}
	else {
		long long n = mul(a, b / 2, c);
		return (((n * n ) % c) * a) % c;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B, C;
	cin >> A >> B >> C;
	long long result = mul(A%C, B, C);
	cout << result;
}
