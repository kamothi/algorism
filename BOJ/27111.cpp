#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    bool list[200001][2] = {false};
    // 0이면 나온거
    int n, a, b, MIN=0;
    int check =0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        if(b==1){
            if(list[a][0] == 0 && list[a][b] == 1) {
                MIN++;
            }
            else{
                check++;
                list[a][0] = 0;
            }
            list[a][b] = 1;
        }
        else{
            if(list[a][1] == 0) {
                MIN++;
            }
            else{
                check--;
                list[a][1] = 0;
            }
            list[a][b] = 1;
        }
    }
    cout << MIN + check;


}
