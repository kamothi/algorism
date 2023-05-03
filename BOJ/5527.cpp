#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int input[100000];
    int output[100000];
    int result = 0;
    vector<int> eval;
    int now = 0;

    cin >> n;
    eval.push_back(0);
    for (int i = 1; i <= n; i++) {
        cin >> input[i];
        if (i == 1) {
            output[1] = 1;
            now++;
            continue;
        }
        if (input[i] != input[i - 1]) {
            output[i] = output[i - 1] + 1;
            now++;
        }
        else {
            eval.push_back(now);
            output[i] = 1;
            now = 1;
        }
    }
    eval.push_back(now);
    eval.push_back(0);
    for(int i=1;i<eval.size()-1;i++) {
        result = max(eval[i] + eval[i - 1], result);
        result = max(eval[i] + eval[i + 1], result);
        result = max(eval[i] + eval[i + 1] + eval[i - 1], result);
    }
    cout << result;

}
