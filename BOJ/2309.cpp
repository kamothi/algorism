#include<algorithm>
#include<iostream>

using namespace std;

int arr[9],sum=0;
bool check[9];


void show_number(){
    for(int i=0;i<9;i++){
        if(check[i] == false) cout << arr[i] << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    fill_n(check,9,false);
    for(int i=0;i<9;i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr,arr+9);
    for(int i=0;i<8;i++){
        for(int j=i+1;j<9;j++){
            if((sum - arr[i] - arr[j]) == 100){
                check[i] = true;
                check[j] = true;
                show_number();
                return 0;
            }
        }
    }
}
