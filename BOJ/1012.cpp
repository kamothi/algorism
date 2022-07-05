#include<iostream>
#include<stack>
#include<string>
using namespace std;

int f[52][52];
bool isvisit[52][52];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int check = 0;
	int T; cin >> T;
	pair<int, int> p;
	while (T--) {
		stack<pair<int, int>> s;
		int M, N, K; cin >> M >> N >> K;
		for (int i = 0; i < M+2; i++) {
			for (int j = 0; j < N+2; j++) {
				f[i][j] = 0;
				isvisit[i][j] = false;
			}
		}
		int X, Y;
		while (K--) {
			cin >> X >> Y;
			f[X + 1][Y + 1] = 1;
		}
		for (int a = 1; a < M+1; a++) {
			for (int b = 1; b < N+1; b++) {
				if (isvisit[a][b] == true || f[a][b] == 0) continue;
				check++;
				s.push({ a,b });
				while (!s.empty()) {
					p = s.top();
					isvisit[p.first][p.second] = true;
					if (f[p.first][p.second-1] == 1 && isvisit[p.first][p.second-1] == false) {
						p.second -= 1;
						s.push(p);
						continue;
					}
					else if (f[p.first-1][p.second] == 1 && isvisit[p.first-1][p.second] == false) {
						p.first -= 1;
						s.push(p);
						continue;
					}
					else if (f[p.first][p.second+1] == 1 && isvisit[p.first][p.second+1] == false) {
						p.second += 1;
						s.push(p);
						continue;
					}
					else if (f[p.first + 1][p.second] == 1 && isvisit[p.first + 1][p.second] == false) {
						p.first += 1;
						s.push(p);
						continue;
					}
					else {
						cout << p.first << p.second << endl;
						s.pop();
					}
				}
			}
		}
		cout << check << endl;
		check = 0;
	}
}
