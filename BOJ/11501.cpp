#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> v;
    long long T,day;
    long long result = 0,sum=0,MAX=0;
    cin >> T;
    while(T--){
        int temp;
        cin >> day;
        for(int i=0;i<day;i++){
            cin >> temp;
            v.push_back(temp);
        }
        MAX = v[day-1];
        for(int i=day-2;i>=0;i--){
            if(MAX >= v[i]) result += (MAX - v[i]);
            else MAX = v[i];
        }
        sum =0;
        MAX = 0;
        cout << result << "\n";
        result = 0;
        v.clear();
    }
}
