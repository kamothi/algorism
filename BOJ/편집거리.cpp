#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

string arr1;
string arr2;
int dist[1001][1001];

int dist() {
	for (int i = 1; i <= arr1.length(); i++) {
		dist[i][0] = i;
	}
	for (int i = 1; i <= arr2.length(); i++) {
		dist[0][i] = i;
	}

	for (int i = 1; i <= arr1.length(); i++) {
		for (int j = 1; j <= arr2.length(); j++) {
			if (arr1[i - 1] == arr2[j - 1]) dist[i][j] = dist[i - 1][j - 1];
			else dist[i][j] = min({ dist[i - 1][j] + 1, dist[i][j - 1] + 1 , dist[i - 1][j - 1] + 1 });
		}
	}
	return dist[arr1.length()][arr2.length()];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> arr1;
	cin >> arr2;
	int result = LCS();
	cout << result;
}
