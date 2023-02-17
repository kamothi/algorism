#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    vector<int> v;
    int Min=0;
    int arr[200000]={0,};

    cin >> n;
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    Min = v[0];
    cout << 0 << " ";
    for(int i=1;i<n;i++){
        if(Min > v[i]) Min = v[i];
        arr[i] = (v[i] - Min) > arr[i-1] ? (v[i]-Min) : arr[i-1];
        cout << arr[i] << " ";
    }
}
