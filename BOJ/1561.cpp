#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n >> m;
    vector<int> v(m);
    for(int i=0;i,i<m;i++) cin >>v[i];

    if(n <= m){
        cout << n;
        return 0;
    }

    // 모두가 탑승하는 시간을 찾고 그때의 놀이기구를 확인하자
    ll left = 0; ll right = 6e10; ll sum = n-m;ll point;

    while(left <= right){
        ll mid = (left+right)/2;
        ll tmp = 0;
        for (int i = 0; i < m; i++) {
            tmp += mid / v[i];
            if (tmp >= sum) break;
        }
        if (tmp >= sum) {
            point = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    // 여기서 point가 모두가 타게되는 지점
    for(int i=0;i<m;i++){
        sum -= (point-1) / v[i];
    }
    for(int i=0;i<m;i++){
        if(point%v[i] == 0) sum -= 1;
        if(sum == 0) {
            cout << i+1;
            return 0;
        }
    }

}
