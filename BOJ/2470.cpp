#include<iostream>
#include<algorithm>

using namespace std;

// 0에 가장 가까운 두 용액 찾기
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int arr[100000];
    int result = 2000000001;
    int result1,result2;
    cin >> n;

    for(int i=0;i<n;i++) cin >> arr[i];

    sort(arr, arr+n);
    int left = 0;
    int right = n-1;
    while(left<right){
        int sum = arr[left] + arr[right];
        if(abs(sum) < abs(result)) {
            result = sum;
            result1 = arr[left];
            result2 = arr[right];
            if(result == 0) break;
        }
        if(sum < 0) left++;
        else right--;
    }
    cout << result1 << " " << result2;

}
