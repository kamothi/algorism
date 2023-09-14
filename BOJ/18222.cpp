#include <iostream>
#include<algorithm>
#include<queue>

using namespace std;

long long k;

long long FIND(long long x){
    if(x==0) return 0;
    else if(x==1) return 1;
    else if(x%2 == 0) return FIND(x/2);
    else return 1 - FIND(x/2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;
    cout << FIND(k-1);


}
