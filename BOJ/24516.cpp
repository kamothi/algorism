#include <iostream>
#include<algorithm>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for(int i=2;i<=n*2;i=i+2){
        cout << i << " ";
    }

}
