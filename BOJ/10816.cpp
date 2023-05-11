#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> card(n);
    for(int i=0;i<n;i++) cin >> card[i];
    int m;
    cin >> m;
    vector<int> num(m);
    for(int i=0;i<m;i++) cin >> num[i];

    sort(card.begin(),card.end());
    for(int i=0;i<m;i++){
        int count = upper_bound(card.begin(),card.end(),num[i]) - lower_bound(card.begin(),card.end(),num[i]);
        cout<<count<<" ";

    }
}
