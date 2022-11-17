#include<iostream>
#include<algorithm>
#include <queue>
#include<vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, N;
	long long input;
	priority_queue<long long, vector<long long>, greater<long long>> arr;
	long long div = 1000000007;
	long long sum = 1;
	long long min1;
	long long min2;
	long long mulmin;
	long long result;

	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> input;
			arr.push(input);
		}
		if (N == 1) {
			cout << 1 << '\n';
			arr.pop();
			continue;
		}
		for (int i = 0; i < N - 1; i++) {
			min1 = arr.top();
			arr.pop();
			min2 = arr.top();
			arr.pop();
			mulmin = min1 * min2;
			sum = (sum * (((min1%div)*(min2%div))%div))%div;
			arr.push(mulmin);
		}
		arr.pop();
		cout << sum%div<< '\n';
		sum = 1;
	}
}
