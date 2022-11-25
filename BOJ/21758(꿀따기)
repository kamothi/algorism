#include<iostream>
#include<algorithm>
using namespace std;
int N;
long long sum[100001] = { 0, };
long long arr[100001] = { 0, };
long long temp = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		sum[i] = arr[i] + sum[i - 1];
	}
	for (int i = 2; i < N; i++) {
		temp = max(temp, sum[N] - arr[i] - arr[1]+sum[N]-sum[i]);
	}
	for (int i = 2; i < N; i++) {
		temp = max(temp, sum[i] - arr[1] + sum[N-1] -sum[i-1]);
	}
	for (int i = 2; i < N; i++) {
		temp = max(temp, sum[N - 1] - arr[i] + sum[i - 1]);
	}
	cout << temp;
}
