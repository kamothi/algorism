#include<iostream>

using namespace std;

int n;
int arr[500000];
int s[500000];
long long result;

void f(int l, int r){
    int mid = (l+r)/2;
    if(l >= r) return;

    f(l,mid); f(mid+1,r);
    int i = l, j = mid+1, idx = l;

    while(i <= mid && j <= r){
        if (arr[i] <= arr[j]) s[idx++] = arr[i++];
        else {
            s[idx++] = arr[j++];
            result += mid - i + 1;
        }
    }

    while(i <= mid) s[idx++] = arr[i++];
    while(j <= r) s[idx++] = arr[j++];
    for(int i = l; i <= r; i++) arr[i] = s[i];


}


int main(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    f(0,n-1);
    cout << result;
}
