#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v(100001);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, result = 0;
    cin >> n;

    for(int i=0;i<n;i++) cin >> v[i];

    for(int i=0;i<n;i++){
        if(v[i+1] > v[i+2]){
            int tmp = min(v[i],v[i+1]-v[i+2]);
            result += 5*tmp;
            v[i] -= tmp; v[i+1] -= tmp;
            int tmp2 = min({v[i],v[i+1],v[i+2]});
            v[i] -= tmp2; v[i+1] -= tmp2; v[i+2] -= tmp2;
            result += 7*tmp2;
        }else{
            int tmp = min({v[i],v[i+1],v[i+2]});
            result += tmp*7;
            v[i] -= tmp; v[i+1] -= tmp; v[i+2] -= tmp;
            int tmp2 = min(v[i],v[i+1]);
            v[i] -= tmp2; v[i+1] -= tmp2;
            result += tmp2*5;
        }
        result += v[i] * 3;
    }



    cout << result;

}
