#include<iostream>
#include<string>

using namespace std;
string L;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int cnt = 0;
	int sum = 0;
	cin >> L;
	for (int i = 0; i < (int)L.size(); i++) {
		if (L[i] == '(') cnt++;
		if (L[i] == ')' && L[i - 1] == '(') {
			cnt--;
			sum += cnt;
		}
		else if (L[i] == ')' && L[i - 1] == ')') {
			cnt--;
			sum += 1;
		}
	}
	cout << sum;
}
