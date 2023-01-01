#include<iostream>
#include<vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int temp1, temp2;
	int arr[1000][2];
	vector<int> v;
	bool check =false;
	int MIN=1, MAX=1;
	int a, b;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i][0] >> arr[i][1];

	for (int i = 0; i < n; i++) {
		temp1 = arr[i][0];
		temp2 = arr[i][1];
		while (1) {
			int cnt = 2;
			while(1) {
				if (temp1 % cnt == 0 && temp2 % cnt == 0) {
					v.push_back(cnt);
					temp1 = temp1 / cnt;
					temp2 = temp2 / cnt;
					cnt = 2;
					continue;
				}
				if (cnt > temp1 || cnt > temp2) {
					check = true;
					break;
				}
				cnt++;
			}
			if (check) {
				for (int j = 0; j < v.size(); j++) {
					MIN = MIN * v[j];
					MAX = MAX * v[j];
				}
				MIN = MIN * temp1 * temp2;
				break;
			}
		}
		check = false;
		v.clear();
		cout << MIN << " " << MAX << "\n";
		MIN = 1;
		MAX = 1;
		
	}
}
