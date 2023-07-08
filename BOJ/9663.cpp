#include<iostream>
#include<cmath>

using namespace std;

int n;
int cnt = 0;
int queen[15];

void findQueen(int r){
    if(r == n) {
        cnt++;
        return;
    }
    for(int i=0;i<n;i++){
        bool check = false;
        queen[r] = i;
        for(int j=0;j<r;j++){
            if(queen[r] == queen[j] || abs(r-j) == abs(queen[r] - queen[j])) check = true;
        }
        if(!check) findQueen(r+1);
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    findQueen(0);
    cout << cnt;

}
