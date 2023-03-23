#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; //저울추의 개수
    long long sum = 1;
    int arr[1000];

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    sort(arr,arr+n);
    for (int i = 0; i < n; i++) {
        if (arr[i] > sum) {
            break;
        }
        sum += arr[i];
    }
    cout << sum;

}
