#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int dpMax[3];
    int dpMin[3];

    cin >> n;
    cin >> dpMax[0] >> dpMax[1] >> dpMax[2];
    dpMin[0] = dpMax[0]; dpMin[1] = dpMax[1]; dpMin[2] = dpMax[2];


    for(int i=1;i<n;i++){
        int in1,in2,in3;
        cin >> in1 >> in2 >> in3;

        int tmp1 = dpMax[0], tmp2 = dpMax[2];
        dpMax[0] = max(dpMax[0],dpMax[1]) + in1;
        dpMax[2] = max(dpMax[1],dpMax[2]) + in3;
        dpMax[1] = max({tmp1,tmp2,dpMax[1]}) + in2;

        tmp1 = dpMin[0], tmp2 = dpMin[2];
        dpMin[0] = min(dpMin[0],dpMin[1]) + in1;
        dpMin[2] = min(dpMin[1],dpMin[2]) + in3;
        dpMin[1] = min({tmp1,tmp2,dpMin[1]}) + in2;

    }
    int Max = max({dpMax[0],dpMax[1],dpMax[2]});
    int Min = min({dpMin[0],dpMin[1],dpMin[2]});

    cout << Max << " " << Min;
}
