#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,j=1;
    stack<int> s,s2;
    vector<int> a,b;
    cin >> n;
    for(int i=0;i<n;i++) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    b.push_back(a[0]);
    s.push(0);
    s2.push(a[0]);
    for(int i=1;i<n;i++){
        int left,right,mid;
        left = 0;
        right = j;
        if(b[j-1] < a[i]) {
            b.push_back(a[i]);
            s.push(j);
            j++;
            s2.push(a[i]);
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
            s2.push(a[i]);
            s.push(right+1);
        }
    }
    vector<int> c(j);
    int now = j-1;
    while(!s.empty() && !s2.empty()){
        int tmp = s.top();
        s.pop();
        if(c[tmp] == 0 && tmp == now) {
            c[tmp] = s2.top();
            now--;
        }
        s2.pop();
    }
    cout << j << "\n";
    for(auto i : c) cout << i << " ";
}
