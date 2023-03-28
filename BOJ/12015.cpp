#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,j=1;
    vector<int> a,b;
    cin >> n;
    for(int i=0;i<n;i++) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    b.push_back(a[0]);
    for(int i=1;i<n;i++){
        int left,right,mid;
        left = 0;
        right = j;
        if(b[j-1] < a[i]) {
            b.push_back(a[i]);
            j++;
        }
        else{
            while(left <= right){
                mid = (left + right)/2;
                if(b[mid] >= a[i]){
                    right = mid-1;
                }
                else{
                    left = mid + 1;
                }
            }
            b[right+1] = a[i];
        }
    }
    cout << j;
}
