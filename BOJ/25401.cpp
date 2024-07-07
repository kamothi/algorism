#include<iostream>
#include<algorithm>
using namespace std;


int n;
int arr[500];
int tmp1,tmp2,result=500,cnt;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];

    for(int i=0;i<n;i++){
        for(int j = i + 1; j < n ;j++) {
            if ((arr[j] - arr[i]) % (j - i) != 0) continue;

            int tmp2 = (arr[j] - arr[i]) / (j - i);
            cnt = 0;

            for(int k = 0 ; k < n ; k++){
                tmp1 = arr[i] + (k-i) * tmp2;
                if(arr[k] != tmp1) cnt++;
            }
            
            result = min(result, cnt);

        }
    }
    cout << result;
}
