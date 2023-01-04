#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a;
    bool check =false;
    int n,m,k;
    int Member, cnt=10000002;
    int temp=0;
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a;
            temp += a;

            if(temp >= k && cnt > j +1 && check == false){
                cnt = j+1;
                Member = i+1;
                check =true;
            }
        }
        temp = 0;
        check = false;
    }

    cout << Member << " " << cnt;
}
