#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

typedef long long LL;

bool check_primeNumber(string n) {
	LL temp = stoll(n);
	for (LL i = 2; i*i <= temp; i++) {
		if (temp % i == 0) return true;
	}
	return false;
}

int main() {
	string temp;
	string Reverse;
	cin >> temp;
	if (temp == "1") {
		cout << "no";
		return 0;
	}
	if (check_primeNumber(temp)) {
		cout << "no";
		return 0;
	}
	Reverse = temp;
	for (LL i = 0; i < temp.size(); i++) {
		if (temp[i] == '3' || temp[i] == '4' || temp[i] == '7') {
			cout << "no";
			return 0;
		}
		else if (temp[i] == '6') Reverse[i] = '9';
		else if (temp[i] == '9') Reverse[i] = '6';
		else Reverse[i] = temp[i];
	}
	reverse(Reverse.begin(), Reverse.end());
	if (check_primeNumber(Reverse)) {
		cout << "no";
		return 0;
	}
	cout << "yes";
	return 0;

}
