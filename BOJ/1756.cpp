#include<iostream>
#include<algorithm>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // 깊이와 피자 개수
    int d, n;
    int pizza[300001];
    cin >> d >> n;

    int arr[300001];
    arr[0] = 2000000000;
    for(int i=1;i<=d;i++){
        cin >> arr[i];
        if(arr[i] > arr[i-1]){
            arr[i] = arr[i-1];
        }
    }
    for(int i=1;i<=n;i++) cin >> pizza[i];
    int pos = d+1;
    for(int i=1;i<=n;i++){
        if(!pos) break;
        if(pizza[i] <= pizza[i-1]){ 
            pos--; 
            continue; 
            }
        int left = 0, right = pos-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(pizza[i] <= arr[mid]) pos = mid, left = mid+1;
            else right = mid - 1;
        }
    }
    cout << pos <<'\n';

}
