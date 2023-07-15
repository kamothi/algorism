#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    long long cnt = 0;
    long long num=0;
    long long result = 0;
    for(int i=0;i<n;i++) {
        cin >> v[i];
        num += v[i];
    }
    num = num/n;
    for(int i=0;i<n;i++){
        cnt += num - v[i];
        result += abs(cnt);
    }

    cout << result;

}
