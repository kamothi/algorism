#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,s; //n은 층수, s는 기숙사 층수
    vector<int> speed;
    string command,out_command;
    int now_speed=0, now_position = 1;

    cin >> n >> s;
    int tmp;
    speed.push_back(-1);
    for(int i=0;i<n;i++){
        cin >> tmp;
        speed.push_back(tmp);
    }
    cin >> command;
    reverse(command.begin(),command.end());
    cout << command;

}
