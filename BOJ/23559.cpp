#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,money,nowMoney=0,nowHappy=0,Max=-1;
    int five[100000];
    int one[100000];
    int dist[100000];

    cin >> n >> money;
    for(int i=0;i<n;i++) {
        cin >> five[i] >> one[i];
        nowHappy += one[i];
        nowMoney += 1000;
        dist[i] = five[i] - one[i];
    }

    int temp = money - nowMoney;
    temp = temp/4000;

    sort(dist,dist+n,greater<int>());
    for(int i=0;i<temp;i++){
        if(dist[i] < 0 ) break;
        nowHappy += dist[i];
    }
    cout << nowHappy;
}
