#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t,n;
    queue<int> q,q2;
    int arr[200];
    cin >> t;

    for(int i=0;i<t;i++){
        cin >> n;
        for(int j=0;j<n*2;j++){
            cin >> arr[j];
            if(j == 0){
                q2.push(arr[j]);
                q.push(arr[j]/3*4);
                continue;
            }
            if(arr[j] % 2 != 0){
                q2.push(arr[j]);
                q.push(arr[j]/3*4);
                continue;
            }
            if(arr[j] == q.front()){
                q.pop();
            }
            else{
                q2.push(arr[j]);
                q.push(arr[j]/3*4);
                continue;
            }
        }
        cout << "Case #" << i+1 << ":";
        int temp = q2.size();
        for(int j=0;j<temp;j++){
            cout << " " << q2.front();
            q2.pop();
        }
        cout << "\n";
    }

}
