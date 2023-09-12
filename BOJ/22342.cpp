#include <iostream>
#include<algorithm>

using namespace std;

int input[2002][2002];
int store[2002][2002];
int output[2002][2002];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int result = -1;
    int m,n; //행,열
    cin >> m >> n;
    for(int i=0;i<=m+1;i++){
        for(int j=0;j<=n+1;j++){
            store[i][j] = 0;
            output[i][j] = 0;
            input[i][j] = 0;
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++){
            char a; cin >> a;
            input[i][j] = a-'0';
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=-1;k<=1;k++){
                store[j][i] = max(store[j][i],output[j+k][i-1]);
            }
            output[j][i] = store[j][i] + input[j][i];
            result = max(result,store[j][i]);
        }
    }
    cout << result;
}
