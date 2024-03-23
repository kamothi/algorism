#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

int T;
int n,m;

ll arrA[1001];
ll arrB[1001];

vector<ll> sumA;
vector<ll> sumB;

ll result = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arrA[i];
    }

    cin >> m;
    for(int i=0;i<m;i++){
        cin >> arrB[i];
    }

    for (int i = 0; i < n; i++) {
        int sum = arrA[i];
        sumA.push_back(sum);
        for (int j = i + 1; j <  n; j++) {
            sum += arrA[j];
            sumA.push_back(sum);
        }
    }

    for (int i = 0; i < m; i++) {
        int sum = arrB[i];
        sumB.push_back(sum);
        for (int j = i + 1; j < m; j++) {
            sum += arrB[j];
            sumB.push_back(sum);
        }
    }

    sort(sumA.begin(),sumA.end());
    for (int i = 0; i < sumB.size(); i++) {
        int low = lower_bound(sumA.begin(), sumA.end(), T - sumB[i])-(sumA.begin());
        int high = upper_bound(sumA.begin(), sumA.end(), T - sumB[i]) - (sumA.begin());

        result += (high - low);
    }
    cout << result;

}
