#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,j=1;
    int arr[1000],b[1000];
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];

    b[0] = arr[0];
    for(int i=1;i<n;i++){
        int left,right,mid;
        left = 0;
        right = j;
        if(b[j-1] < arr[i]) {
            b[j] = arr[i];
            j++;
        }
        else{
            while(left < right){
                mid = (left + right)/2;
                if(b[mid] >= arr[i]){
                    right = mid;
                }
                else{
                    left = mid + 1;
                }
            }
            b[right] = arr[i];
        }
    }
    cout << j;
}
