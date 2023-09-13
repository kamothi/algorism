#include <iostream>
#include<algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m,n,l; // 사대의 수, 동물의 수,사거리
    cin >> m >> n >> l;
    int place[m];
    int result=0;
    int animal[n][2];
    for(int i=0;i<m;i++) cin >> place[i];
    sort(place,place+m);
    for(int i=0;i<n;i++) cin >> animal[i][0] >> animal[i][1];

    for(int i=0;i<n;i++){
        int left=0,right=m-1,mid;
        while(left<=right){
            mid = (right+left)/2;
            int temp = abs(place[mid]-animal[i][0])+animal[i][1];
            if(temp<=l){
                result++;
                break;
            }
            else{
                if(animal[i][0] >= place[mid])
                    left = mid+1;
                else right = mid-1;
            }
        }
    }
    cout << result;

}
