#include<iostream>
#include<string.h>
using namespace std;

string input;

int main(){
    long long sum = 0;
    long long count =0;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> input;
    for(int i=0;i<input.size();i++){
        if(input[i] == '(') count++;
        else if(input[i] == ')' && input[i-1] == '('){
            count--;
            sum+=count;
        }
        else if(input[i] ==')' && input[i-1] == ')')count --;
    }
    cout << sum;
}
