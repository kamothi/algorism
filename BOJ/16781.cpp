#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> a;

    // a 처리
    for(int i=1;i<=63;i++){
        for(int j=66;j<=128;j++){
            string tmp = to_string(j);
            string tmp2 = to_string(i);
            a.push_back("A"+tmp2+ " C"+tmp);
        }
    }


    for(int i=64;i<=128;i++){
        for(int j=1;j<=64;j++){
            string tmp = to_string(j);
            string tmp2 = to_string(i);
            a.push_back("A"+tmp2+" B"+tmp);
        }
    }


    // b 처리
    for(int i=65;i<=128;i++){
        for(int j=1;j<=65;j++){
            string tmp = to_string(j);
            string tmp2 = to_string(i);
            a.push_back("B"+tmp2+" C"+tmp);
        }
    }


    // 다시 반으로 나누기, G1확인
    a.push_back("A1 B1");
    a.push_back("A1 B2");
    a.push_back("A1 C1");
    for(int i=2;i<=65;i++){
        string tmp = to_string(i);
        a.push_back("A1 C"+tmp);
    }

    for(int i=2;i<=63;i++){
        for(int j=1;j<=2;j++){
            string tmp = to_string(j);
            string tmp2 = to_string(i);
            a.push_back("A"+tmp2+" B"+tmp);
        }
    }

    for(int i=2;i<=63;i++){
        for(int j=2;j<=65;j++){
            string tmp = to_string(j);
            string tmp2 = to_string(i);
            a.push_back("A"+tmp2+" C"+tmp);
        }
    }

    a.push_back("B1 C1");
    a.push_back("B2 C1");

    for(int i=3;i<=64;i++){
        for(int j=1;j<=65;j++){
            string tmp = to_string(j);
            string tmp2 = to_string(i);
            a.push_back("B"+tmp2+" C"+tmp);
        }
    }


    // G2 처리, 3개 틀림
    a.push_back("C66 B65");
    a.push_back("C66 B66");
    a.push_back("C66 A64");
    for(int i=65;i<=128;i++){
        string tmp = to_string(i);
        a.push_back("C66 A"+tmp);
    }

    for(int i=67;i<=128;i++){
        for(int j=65;j<=66;j++){
            string tmp = to_string(j);
            string tmp2 = to_string(i);
            a.push_back("C"+tmp2+" B"+tmp);
        }
    }

    for(int i=67;i<=128;i++){
        for(int j=65;j<=128;j++){
            string tmp = to_string(j);
            string tmp2 = to_string(i);
            a.push_back("C"+tmp2+" A"+tmp);
        }
    }

    a.push_back("B65 A64");
    a.push_back("B66 A64");

    for(int i=67;i<=128;i++){
        for(int j=64;j<=128;j++){
            string tmp = to_string(j);
            string tmp2 = to_string(i);
            a.push_back("B"+tmp2+" A"+tmp);
        }
    }

    cout << a.size() << "\n";
    for(int i=0;i<a.size();i++){
        cout << a[i] << "\n";
    }

}
