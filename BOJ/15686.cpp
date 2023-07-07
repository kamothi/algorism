#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int n,m;
char map[50][50];
vector<pair<int,int>> house,chicken,tmp;
bool chickenSelect[13];
int result = 200000000;

int dis(){
    int sum = 0;
    for(int i=0;i<house.size();i++){
        int d = 200000000;
        for(int j=0;j<tmp.size();j++){
            int dist = abs(house[i].first - tmp[j].first) + abs(house[i].second - tmp[j].second);
            d = min(d,dist);
        }
        sum += d;
    }
    return sum;
}

void checkChicken(int x, int cnt){
    if(m == cnt){
        result = min(result,dis());
        return;
    }
    for(int i=x;i<chicken.size();i++){
        if(chickenSelect[i]) continue;
        chickenSelect[i] = true;
        tmp.push_back(chicken[i]);
        checkChicken(i,cnt+1);
        chickenSelect[i] = false;
        tmp.pop_back();
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> map[i][j];
            if(map[i][j] == '1') house.push_back({i,j});
            if(map[i][j] == '2') chicken.push_back({i,j});
        }
    }
    checkChicken(0,0);

    cout << result;

}
