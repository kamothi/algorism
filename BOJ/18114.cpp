#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, c;
    cin >> n >> c;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(),v.end());
    int l=0,r=n-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(v[mid] > c)
        {
            r= mid - 1;
        }
        else if( v[mid] == c)
        {
            cout << 1;
            return 0;
        }
        else l = mid + 1;
    }
    for(int i=0;i<n;i++){
        if(v[i] < c){
            int num = c - v[i];
            l = i+1, r = n-1;
            while(l<=r){
                int mid = (l+r)/2;
                if(v[mid] > num)
                {
                    r= mid - 1;
                }
                else if( v[mid] == num)
                {
                    cout << 1;
                    return 0;
                }
                else l = mid + 1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(v[i] + v[j] < c){
                int num = c - v[i] - v[j];
                l = j+1, r = n-1;
                while(l<=r){
                    int mid = (l+r)/2;
                    if(v[mid] > num)
                    {
                        r= mid - 1;
                    }
                    else if( v[mid] == num)
                    {
                        cout << 1;
                        return 0;
                    }
                    else l = mid + 1;
                }
            }
        }
    }
    cout << 0;
}
