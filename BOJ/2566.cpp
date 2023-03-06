#include<iostream>

using namespace std;

int main(){
    int Max = -1;
    int row,col;
    int temp;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin >> temp;
            if(temp > Max){
                row = i;
                col = j;
                Max = temp;
            }
        }
    }
    cout << Max <<"\n";
    cout << row+1 << " " << col+1;
}
