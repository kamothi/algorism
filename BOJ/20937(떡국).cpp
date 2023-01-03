#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int MIN=0;
    int n;
    int temp;
   cin >> n;
   map<int, int> m;
   for(int i=0;i<n;i++){
       cin >> temp;
       m[temp]++;
   }

   for(auto iter:m){
       MIN = max(MIN,iter.second);
   }

   cout<< MIN;
}
