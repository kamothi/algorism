#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	char str[100][100];
	int R, C;
	int rg, rp, cg, cp;
	int cnt=0;
	cin >> R >> C >> rg >> cg >> rp >> cp;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> str[i][j];
			if (str[i][j] == 'P') cnt++;
		}
	}
	if ((rp * cp) == cnt) cout << 0;
	else cout << 1;
}
