#include<iostream>
#include<algorithm>

using namespace std;

int n;
int arr[100000];
int l,r,mid;

int countComp(int cmp){ // 비교값
    l = cmp;
    int result = cmp;
    r = n-1;
    while(l<=r){
        mid = (l+r)/2;
        if(arr[mid] * 9 > arr[cmp] * 10){
            r = mid -1;
        }
        else{
            l = mid + 1;
            result = mid;
        }
    }
    return result;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    long long sum = 0;
    for(int i=0;i<n;i++) cin >> arr[i];
    sort(arr,arr+n);

    for(int i=0;i<n;i++){
        sum += (countComp(i) - i);
    }
    cout << sum;
}
