#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m; // 사람, 풍선갯수
    cin >> n >> m;
    vector<int> v(n);
    long long result;
    for(int i=0;i<n;i++) cin >> v[i];

    long long left = 0,right = 1000000000000;
    while(left <= right){
        long long cnt = 0;
        long long mid = (left+right)/2;
        for(int i=0;i<n;i++){
            cnt += mid/v[i];
        }
        if(cnt >= m) {
            result = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
    cout << result;
}
