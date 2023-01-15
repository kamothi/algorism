#include<iostream>

using namespace std;

int main(){
    int n;
    int temp1,temp2=0;
    int sum=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> temp1;
        if((temp1 - temp2) > 1) {
            sum += temp1;
        }
        temp2 = temp1;
    }
    cout << sum;
}
