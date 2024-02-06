#include<iostream>
#include<algorithm>

using namespace std;

// 11054

int n;
int arr[1000];
int Ldp[1000];
int Rdp[1000];
int result = 0; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        Ldp[i] = 1;
        Rdp[i] = 1;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j] < arr[i]) Ldp[i] = max(Ldp[i],Ldp[j]+1);
        }
    }

    for(int i=n-2;i>=0;i--){
        for(int j=n-1;i<j;j--){
            if(arr[j] < arr[i]) Rdp[i] = max(Rdp[i],Rdp[j]+1);
        }
    }

    for(int i=0;i<n;i++){
        result = max(result,Rdp[i]+Ldp[i]-1);
    }

    cout << result;


}
