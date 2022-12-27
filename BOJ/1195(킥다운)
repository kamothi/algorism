#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
	int result = 0;
	vector<int> a, b;
	char temp;
	bool check = true;
	int M;
	while (1) {
		cin.get(temp);
		if (temp == '\n') break;
		a.push_back(temp - '0');
	}
	while (1) {
		cin.get(temp);
		if (temp == '\n') break;
		b.push_back(temp - '0');
	}
	if (a.size() > b.size()) {
		M = b.size();
		swap(a, b);
	}
	else M = a.size();
	result = a.size() + b.size();
	for (int i = 0; i < M; i++) {
		check = true;
		for (int j = 0; j <= i; j++) {
			if (a[j] == 2 && b[b.size() - 1 - i + j] == 2) {
				check = false;
				break;
			}
		}
		int t = a.size() + b.size() - 1 - i;
		if (check) result = min(result, t);
	}
	for (int i = 0; i < M; i++) {
		check = true;
		for (int j = 0; j <= i; j++) {
			if (a[a.size()-1-i+j] == 2 && b[j] == 2) {
				check = false;
				break;
			}
		}
		int t = a.size() + b.size() - 1 - i;
		if (check) result = min(result, t);
	}
	for (int i = 0; i < b.size() - a.size(); i++) {
		check = true;	
		for (int j = 0; j < M; j++) {
			if (a[j] == 2 && b[i+j] == 2) {
				check = false;
				break;
			}
		}
		int t = b.size();
		if (check) result = min(result, t);
	}
	cout << result;
}
