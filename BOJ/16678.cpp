#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    sort(v.begin(),v.end());
    long long result = 0;
    int num = 1;
    for(int i=0;i<n;i++){
        if (v[i] >= num)
        {
            result += v[i] - num;
            num++;
        }
    }
    cout << result;
}
