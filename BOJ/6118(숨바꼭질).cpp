#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int number, dist, same;
int N, M;
bool check[20001] = { false };
int Count[20001] = { 0, };
vector<int> store[20001];
queue<int> q;
void bfs() {
	q.push(1);
	check[1] = true;
	while (!q.empty()) {
		for (int i = 0; i < store[q.front()].size(); i++) {
			if (!check[store[q.front()][i]]) {
				q.push(store[q.front()][i]);
				check[store[q.front()][i]] = true;
				Count[store[q.front()][i]] = Count[q.front()] + 1;
			}
		}
		q.pop();
	}
}

void check_number() {
	number = 1;
	dist = Count[1];
	same = 1;
	int temp=0;
	for (int i = 1; i < N; i++) {
		if (temp < Count[i + 1]) {
			same = 1;
			dist = Count[i + 1];
			number = i + 1;
		}
		else if (temp == Count[i + 1]) {
			same++;
		}
		temp = dist;
	}
}
int main() {
	int a, b;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		store[a].push_back(b);
		store[b].push_back(a);
	}
	bfs();
	check_number();

	cout << number << " " << dist << " " << same;
}
