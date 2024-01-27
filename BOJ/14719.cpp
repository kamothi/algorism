#include<iostream>
#include<algorithm>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int h,w;
    cin >> h >> w;

    int arr[501];
    int result = 0;
    for(int i=0;i<w;i++){
        cin >> arr[i];
    }

    for(int i=1;i<w-1;i++){
        int left = 0, right = 0;
        for(int j=0;j<i;j++){
            left = max(left,arr[j]);
        }
        for(int j=i+1;j<w;j++){
            right = max(right,arr[j]);
        }
        int tmp = min(left,right);
        if(arr[i] > tmp) continue;
        result += (tmp - arr[i]);
    }

    cout << result;

}
