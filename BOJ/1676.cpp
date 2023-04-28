#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int num1=0,num2=0;
    cin >> n;
    for(int i=1;i<=n;i++){
        if(i%125 == 0) num2 += 3;
        else if(i%25 == 0) num2+=2;
        else if(i%5 == 0) num2 +=1;
    }
    cout << num2;

}
