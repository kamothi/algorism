#include<iostream>
#include<algorithm>

using namespace std;


// 가로등의 길이를 이분 탐색으로
// nlogn
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 굴다리의 길이 및 가로등 개수
    int n,m;
    cin >> n >> m;
    int arr[100000];
    for(int i=0;i<m;i++){
        cin >> arr[i];
    }

    sort(arr,arr+m,less<>());


    int left = 0, right = 100000;
    while(left<=right){
        int mid = (left+right)/2;
        int flag = 0;

        // 가장 끝에
        if(arr[0] > mid) flag = 1;
        // 가운데
        for(int i = 0; i < m - 1; i++){
            if(arr[i+1] - arr[i] > mid * 2) { flag = 1; break; }
        }
        // 가장 오른쪽
        if(n - arr[m-1] > mid) flag = 1;

        if(!flag) right = mid -1;
        else left = mid + 1;
    }

    cout << left;

}
