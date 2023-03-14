#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    vector<int> v;
    vector<int> output;
    int tmp;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp;
        v.push_back(tmp);
    }

    for(int i=0;i<n;i++){
        if(i==0){
            if(v[i] && v[i] == v[i+1]){
                cout << -1;
                return 0;
            }
            else if(v[i]==0){
                for(int j=1;j<4;j++){
                    if(v[i+1] != j){
                        v[i] = j;
                        break;
                    }
                }
            }
        }
        if(i==(n-1)){
            if(v[i]==0){
                for(int j=1;j<4;j++){
                    if(v[i-1] != j){
                        v[i] = j;
                        break;
                    }
                }
            }
        }
        if(v[i] == 0){
            for(int j=1;j<4;j++){
                if(v[i+1] != j && v[i-1] != j){
                    v[i] = j;
                    break;
                }
            }
        }
        else{
            if(v[i] == v[i+1] || v[i] == v[i-1]){
                cout << -1;
                return 0;
            }
            else{
                continue;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << v[i] << " ";
    }
}
