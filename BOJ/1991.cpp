#include<iostream>
#include<vector>

using namespace std;
string pre;
void preorder(vector<char>* node,char root){
    if(root == '.') return;
    cout << root;
    preorder(node,node[root-'A'][0]); // 왼
    preorder(node,node[root-'A'][1]); // 오
}
void inorder(vector<char>* node,char root){
    if(root == '.') return;
    inorder(node,node[root-'A'][0]); // 왼
    cout << root;
    inorder(node,node[root-'A'][1]); // 오
}
void postorder(vector<char>* node,char root){
    if(root == '.') return;
    postorder(node,node[root-'A'][0]); // 왼
    postorder(node,node[root-'A'][1]); // 오
    cout << root;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<char>* v = new vector<char>[n];

    char root,left,right;
    for(int i=0;i<n;i++){
        cin >> root >> left >> right;
        v[root - 'A'].push_back(left);
        v[root - 'A'].push_back(right);
    }


    preorder(v,'A');
    cout << "\n";
    inorder(v,'A');
    cout << "\n";
    postorder(v,'A');
}
