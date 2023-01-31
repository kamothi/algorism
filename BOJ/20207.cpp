#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    int MIN = 366,MAX = -1;
    int check[367] = {0,};
    int result = 0;
    int h=0,w=0;

    cin >> n;
    for(int i=0;i<n;i++){
        int temp1,temp2;
        cin >> temp1 >> temp2;
        MIN = min(temp1,MIN);
        MAX = max(temp2,MAX);
        for(int j=temp1;j<=temp2;j++) check[j]++;
    }

    for(int i=MIN;i<=MAX+1;i++){
        if(check[i] == 0){
            result += (w*h);
            w=0;
            h=0;
        }
        else{
            w++;
            h = max(check[i],h);
        }
    }
    cout << result;
}
