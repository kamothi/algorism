#include<iostream>
#include<vector>

using namespace std;

int n,m;
int arr[1000001];
int temp,result = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    bool chk = false;
    for(int i=1;i<=n;i++){
        cin >> temp;
        arr[i] = temp;
        if(temp == 1 && !chk) {
            result++;
            chk=true;
        }
        else if(temp ==0){
            chk=false;
        }
    }

    while(m--){
        cin >> temp;
        if(temp == 0) cout << result << "\n";
        else{
            cin >> temp;
            if(arr[temp] == 1) continue;
            else{
                arr[temp] = 1;
                if((temp) == 1) {
                    if (arr[temp+1] == 0) result++;
                }
                else if(temp == n) {
                    if(arr[temp - 1] == 0) result++;
                }
                else{
                    if(arr[temp-1] == 0 && arr[temp+1] == 0) result ++;
                    else if(arr[temp-1] == 1 && arr[temp+1] == 1) result--;
                }
            }
        }
    }
}
