#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, temp;
    vector<int> v[1001];
    int MAX=-1;
    int cnt=-1;
    int num;
    int sum;
    cin >> n;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<5;j++){
            cin >> temp;
            v[i].push_back(temp);
        }
    }
    for(int g=n;g>0;g--){
        for(int i=0;i<=2;i++){
            for(int j=i+1;j<=3;j++){
                for(int k=j+1;k<=4;k++){
                    sum = (v[g][i]+v[g][j]+v[g][k])%10;
                    MAX = max(MAX,sum);
                }
            }
        }
        if(cnt < MAX){
            cnt = MAX;
            num = g;
        }
        MAX=0;
    }
    cout << num;
}
