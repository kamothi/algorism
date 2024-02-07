#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int n;
int ability[20][20];
int result = 2000000000;
bool selected[20];


// 현재까지 뽑힌 인원의 수와 다음 선수 위치
void team(int count, int idx){

    int scoreA = 0;
    int scoreB = 0;

    // 이렇게 하면 나누어진 경우
    if(count==n/2){ 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if (selected[i] && selected[j]) {
                    scoreA += ability[i][j];
                }
                else if (!selected[i] && !selected[j]) {
                    scoreB += ability[i][j];
                }
            }
        }
        int diff = abs(scoreA-scoreB);
        result = min(diff,result);
    }

    for(int i=idx;i<n;i++){
        selected[i] = true;
        team(count+1,i+1);
        selected[i] = false;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin >> ability[i][j];
    }

    team(0,0);
    cout << result;


}
