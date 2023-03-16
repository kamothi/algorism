#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, MIN=0;
    int L_cnt = 0,R_cnt = 0,LR_cnt = 30000000,RL_cnt = 30000000;
    int left1,right1,left2,right2;
    int arr[300000];
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];

    for(int i=0;i<n;i++){
        if(arr[i] == 1) {
            R_cnt = n-i;
            break;
        }
    }

    for(int i=n-1;i>=0;i--){
        if(arr[i] == 1){
            L_cnt = i+1;
            break;
        }
    }
    // for문 한번 더 돌려야함 왼쪽에서 하나씩 이동하면서 l지점과 r지점을 찾의며 최소값을 계속 비교해가야함

    for(int i=0;i<n-1;i++){
        int tmp1,tmp2;
        int lr_tmp,rl_tmp;
        if(arr[i] == 1){
            tmp1 = i;
            for(int j=i+1;j<n;j++){
                if(arr[j] == 1){
                    tmp2 = j;
                    lr_tmp = 2*(tmp1+1) - (tmp2+1) + n +1;
                    rl_tmp = 2*n +2 - (2*(tmp2+1)) + tmp1 + 1;
                    if(lr_tmp < LR_cnt){
                        LR_cnt = lr_tmp;
                        left1 = tmp1;
                        right1 = tmp2;
                    }
                    if(rl_tmp < RL_cnt){
                        RL_cnt = rl_tmp;
                        left2 = tmp1;
                        right2 = tmp2;
                    }
                    break;
                }
            }
        }
    }


    if(L_cnt && R_cnt && LR_cnt && RL_cnt){
        MIN = min({L_cnt,R_cnt,LR_cnt,RL_cnt});
        cout << MIN << "\n";
        if(MIN == L_cnt){
            for(int i=0;i<L_cnt;i++){
                cout << 'L';
            }
        }
        else if(MIN == R_cnt){
            for(int i=0;i<R_cnt;i++){
                cout << 'R';
            }
        }
        else if(MIN == LR_cnt){
            for(int i=0;i<left1+1;i++) cout << 'L';
            for(int i=0;i<LR_cnt-(left1+1);i++) cout << 'R';
        }
        else{
            for(int i=0;i<n-right2;i++) cout << 'R';
            for(int i=0;i<RL_cnt-(n-right2);i++) cout << 'L';
        }
    }
    else{
        if(L_cnt > R_cnt){
            cout << R_cnt << "\n";
            for(int i=0;i<R_cnt;i++){
                cout << 'R';
            }
        }
        else{
            cout << L_cnt << "\n";
            for(int i=0;i<L_cnt;i++){
                cout << 'L';
            }
        }
    }
    //cout << "\n" << L_cnt << R_cnt << LR_cnt << RL_cnt;
}
