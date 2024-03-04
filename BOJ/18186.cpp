#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> v(1000000);

int main(){
    long long n, b, c;
    long long result = 0;
    cin >> n >> b >> c;

    for(int i=0;i<n;i++) cin >> v[i];

    if(2*b > b+c){
        for(int i=0;i<n;i++){
            if(v[i+1] > v[i+2]){
                int tmp = min(v[i],v[i+1]-v[i+2]);
                result += (b+c)*tmp;
                v[i] -= tmp; v[i+1] -= tmp;
                int tmp2 = min({v[i],v[i+1],v[i+2]});
                v[i] -= tmp2; v[i+1] -= tmp2; v[i+2] -= tmp2;
                result += (b+2*c)*tmp2;
            }else{
                int tmp = min({v[i],v[i+1],v[i+2]});
                result += tmp*(b+2*c);
                v[i] -= tmp; v[i+1] -= tmp; v[i+2] -= tmp;
                int tmp2 = min(v[i],v[i+1]);
                v[i] -= tmp2; v[i+1] -= tmp2;
                result += tmp2*(b+c);
            }
            result += v[i] * b;
        }
    }
    else{
        if((2*b <= b+c)){
            for(int i=0;i<n;i++) result+=v[i];
            result *= b;
        }else{
            for(int i=0;i<n;i++){
                if(v[i+1] > v[i+2]){
                    int tmp = min(v[i],v[i+1]-v[i+2]);
                    result += (b*2)*tmp;
                    v[i] -= tmp; v[i+1] -= tmp;
                    int tmp2 = min({v[i],v[i+1],v[i+2]});
                    v[i] -= tmp2; v[i+1] -= tmp2; v[i+2] -= tmp2;
                    result += (b+2*c)*tmp2;
                }else{
                    int tmp = min({v[i],v[i+1],v[i+2]});
                    result += tmp*(b+2*c);
                    v[i] -= tmp; v[i+1] -= tmp; v[i+2] -= tmp;
                    int tmp2 = min(v[i],v[i+1]);
                    v[i] -= tmp2; v[i+1] -= tmp2;
                    result += tmp2*(b*2);
                }
                result += v[i] * b;
            }
        }
    }

    cout << result;
}
