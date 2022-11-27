#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

string arr1;
string arr2;
int dist[1001][1001] = { 0, };
int cnt = 0;
void LCS() {
	for (int i = 1; i <= arr1.length(); i++) {
		for (int j = 1; j <= arr2.length(); j++) {
			if (arr1[i - 1] == arr2[j - 1]) {
				dist[i][j] = dist[i - 1][j - 1] + 1;
				cnt = max(cnt, dist[i][j]);
			}
			else {
				dist[i][j] = max({ dist[i - 1][j],dist[i][j - 1],dist[i - 1][j - 1] });
				cnt = max(cnt, dist[i][j]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> arr1;
	cin >> arr2;
	LCS();
	cout << cnt;
}
