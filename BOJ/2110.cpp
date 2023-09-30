#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,c;
    cin >> n >> c;
    int result =0;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(),v.end());

    int left=0,right=1000000000;
    while(left<=right){
        int cnt = 1;
        int now = 0;
        int mid = (left+right)/2;
        for(int i=1;i<n;i++){
            if(v[i]-v[now] >= mid) {
                cnt++;
                now = i;
            }
        }
        if(cnt >= c){
            left = mid + 1;
            result = max(result,mid);
        }
        else{
            right = mid -1;
        }
    }

    cout << result;
}
