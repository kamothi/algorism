#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,a,b; // 선물갯수, 예산, 반 값 갯수
    int arr[100000];
    int cnt = 0;
    long long sum[100000];
    cin >> n >> b >> a;

    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        if(i==0){
            sum[i] = arr[i];
            continue;
        }
        sum[i] = arr[i] + sum[i-1];
    }

    for(int i=0;i<n;i++){
        if(i < a){
            if(sum[i]/2 > b) {
                cout << cnt;
                return 0;
            }
            else cnt++;
        }
        else{
            int tmp;
            tmp = (sum[i] - sum[i-a])/2 + sum[i-a];
            if(tmp > b) {
                cout << cnt;
                return 0;
            }
            else cnt++;
        }
    }
    cout << cnt;

}
