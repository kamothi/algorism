#include<iostream>
#include<algorithm>
using namespace std;


bool comp(pair<pair<int, string>,int> a, pair<pair<int, string>,int> b) {
    if (a.first.first == b.first.first) {
        return a.second < b.second;
    }
    return a.first.first < b.first.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    pair<pair<int, string>,int> p[100000];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i].first.first >> p[i].first.second;
        p[i].second = i;
    }
    sort(p, p + n, comp);
    for (int i = 0; i < n; i++) cout << p[i].first.first << " " << p[i].first.second << "\n";

}
