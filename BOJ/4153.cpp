#include<iostream>
#include<cmath>

using namespace std;

int main() {
	int a, b, c;
	int aa, bb, cc;
	while (1) {
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) break;
		aa = pow(a, 2);
		bb = pow(b, 2);
		cc = pow(c, 2);
		if (aa + bb == cc) {
			cout << "right" << "\n";
			continue;
		}
		if (aa + cc == bb) {
			cout << "right" << "\n";
			continue;
		}
		if (cc + bb == aa) {
			cout << "right" << "\n";
			continue;
		}
		cout << "wrong" << "\n";
	}
}
