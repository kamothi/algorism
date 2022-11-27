#include<iostream>
#include<algorithm>
using namespace std;

int day = 0;
int mchoco = 0;
int N;
int K;
int arr[2001];

int main() {
	int temp = 0;
	int cnt = 0;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	for (int i = K + 1; i <= N; i++) {
		while (1) {
			if (arr[i] != arr[i - K]) {
				day++;
				mchoco += (arr[i] - arr[i - K]);
				arr[i] = arr[i - K];
				sort(arr + 1, arr + N + 1);
			}
			else break;
		}
	}
	cout << mchoco << " " << day;
}
