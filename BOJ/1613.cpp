#include<iostream>
#include<vector>
#include<memory.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n >> m;
    int event[401][401];
    memset(event,0,sizeof(event));
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        event[b][a] = 1;
        event[a][b] = -1;
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if((event[i][k] == 1 || event[i][k] == -1) && event[k][j] == event[i][k]) event[i][j] = event[i][k];
            }
        }
    }

    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        cout << event[a][b] << "\n";
    }
}
