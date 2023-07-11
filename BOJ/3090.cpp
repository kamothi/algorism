#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,t;
    cin >> n >> t;
    vector<int> v;
    int result = 0;
    for(int i=0,a;i<n;i++) {
        cin >> a;
        v.push_back(a);
    }
    int left=0, right= 1000000000,mid;
    while(left<=right){
        vector<int> tmp = v;
        bool check = false;
        int cnt = 0;
        mid = (left+right)/2;
        for(int i=0;i<n-1;i++){
            if(cnt > t) break;
            if((tmp[i+1] - tmp[i]) > mid){
                cnt += tmp[i+1] - tmp[i] - mid;
                tmp[i+1] -= tmp[i+1] - tmp[i] - mid;
            }
        }
        for(int i=n-1;i>0;i--){
            if(cnt > t) break;
            if((tmp[i-1] - tmp[i]) > mid){
                cnt += tmp[i-1] - tmp[i] - mid;
                tmp[i-1] -= tmp[i-1] - tmp[i] - mid;
            }
        }
        if(cnt <= t) check = true;
        if(check) {
            result = mid;
            right = mid -1;
        }
        else left = mid +1;
    }
    for(int i=0;i<n-1;i++){
        if((v[i+1] - v[i]) > result){
            v[i+1] -= v[i+1] - v[i] - result;
        }
    }
    for(int i=n-1;i>0;i--){
        if((v[i-1] - v[i]) > result){
            v[i-1] -= v[i-1] - v[i] - result;
        }
    }
    for(int i=0;i<n;i++) cout << v[i] << " ";
}
