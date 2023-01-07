#include<iostream>

using namespace std;

int main(){
    int n;
    int a;
    int temp[51] ={0,};
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        temp[a]++;
    }
    for(int i=n; i>=0;i--){
        if(temp[i] == i){
            cout << i;
            return 0;
        }
    }
    cout << -1;
}
