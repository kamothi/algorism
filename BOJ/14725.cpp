#include<iostream>
#include<map>

using namespace std;

struct Tree{
    map<string,Tree> m;
};

void printTree(Tree& node, string prefix) {
    for (auto& [key, child] : node.m) {
        cout << prefix << key << endl;
        printTree(child, prefix + "--");
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    Tree t;
    cin >> n;

    for(int i=0;i<n;i++){
        int a;
        string str;
        cin >> a;
        Tree* current = &t;
        for(int j=0;j<a;j++){
            cin >> str;
            if(current->m.find(str) == current->m.end()){
                current->m[str] = Tree();
            }
            current = &(current->m[str]);
        }
    }
    printTree(t, "");
}
