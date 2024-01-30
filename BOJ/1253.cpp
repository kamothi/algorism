#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool t(pair<int,int> a, pair<int, int> b){
    return a.first < b.first;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, result = 0;
    vector<long long> arr;

    cin >> n;
    for(int i=0;i<n;i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    sort(arr.begin(),arr.end());

    for(int i=0;i<n;i++){
        int left = 0, right = n-2;
        vector<long long> temp = arr;
        temp.erase(temp.begin() + i);
        
        while(left < right){
            long long sum = temp[left] + temp[right];
            if(sum == arr[i]) {
                result++;
                break;
            }
            if(sum > arr[i]){
                right--;
            }
            else{
                left++;
            }
        }
    }

    cout << result;
    

}
