#include<iostream>
#include<vector>
using namespace std;
vector<int> a;
void Push(int d) {
	a.push_back(d);
}

int Top() {
	if (a.size() == 0) return -1;
	else return a[a.size()-1];
}

int Size() {
	return a.size();
}

int Empty() {
	if (a.size() == 0) return 1;
	else return 0;
}

int Pop() {
	int f;
	if (a.size() == 0) return -1;
	else {
		f = a.back();
		a.pop_back();
		return f;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<int> e;
	string b;
	int c,d;

	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> b ;
		if (b == "push") {
			cin >> d;
			Push(d);
		}
		else if (b == "top") {
			e.push_back(Top());
		}
		else if (b == "size") {
			e.push_back(Size());
		}
		else if (b == "pop") {
			e.push_back(Pop());
		}
		else if (b == "empty") {
			e.push_back(Empty());
		}
	}
	for (int i = 0; i < e.size(); i++) cout << e[i] << endl;
}
