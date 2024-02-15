#include<iostream>
#include<algorithm>


int map[100][100];
int n;

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin >> map[i][j];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(map[i][k] && map[j][i]) map[j][k] = 1;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cout << map[i][j] << " ";
        cout << "\n";
    }

}

