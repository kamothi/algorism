#include <iostream>
#include<algorithm>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int e,em,m,mh,h;
    int result = 0;
    cin >> e >> em >> m >> mh >> h;
    while(1){
        if(e > 0 || em > 0){
            if(e > 0) e--;
            else{
                em--;
            }
        }
        else break;
        if(m > 0 || em > 0 || mh > 0){
            if(m > 0) m--;
            else{
                if(em >= mh) em--;
                else mh--;
            }
        }
        else break;
        if(h>0 || mh > 0){
            if(h > 0) h--;
            else{
                mh--;
            }
        }
        else break;
        result++;
    }
    cout << result;

}
