#include<iostream>
#include<vector>
using namespace std;

vector<int> v1;
int SIZE(0);

void Push(int d) {
	v1.push_back(d);
	SIZE++;
}

int Front() {
	if (SIZE == 0) return -1;
	else return v1[v1.size() - SIZE];
}

int Back() {
	if (SIZE == 0) return -1;
	else return v1[v1.size() - 1];
}

int Size() {
	return SIZE;
}

int Empty() {
	if (SIZE == 0) return 1;
	else return 0;
}

int Pop() {
	int f;
	if (SIZE == 0) return -1;
	else {
		f = v1[v1.size()-SIZE];
		SIZE--;
		return f;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<int> v2;
	string b;
	int c, d;

	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> b;
		if (b == "push") {
			cin >> d;
			Push(d);
		}
		else if (b == "front") {
			v2.push_back(Front());
		}
		else if (b == "back") {
			v2.push_back(Back());
		}
		else if (b == "size") {
			v2.push_back(Size());
		}
		else if (b == "pop") {
			v2.push_back(Pop());
		}
		else if (b == "empty") {
			v2.push_back(Empty());
		}
	}
	for (int i = 0; i < v2.size(); i++) cout << v2[i] << endl;
}
