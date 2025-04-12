#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->left=NULL;
        this->right=NULL;
        this->val=val;
    }
};
void display(Node* root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    display(root->left);
    display(root->right);
}
int sum(Node* root){
    // if(root==NULL) return 0;
    // int leftSum = sum(root->left);
    // int rightSum = sum(root->right);
    // int sum = root->val + leftSum +rightSum;
    // return sum;

    // shortHand:-
    if(root==NULL) return 0;
    return root->val+sum(root->left)+sum(root->right);
}
int product(Node* root){
    if(root==NULL) return 1;
    return root->val*product(root->left)*product(root->right);
}
int size(Node* root){
    if(root==NULL) return 0;
    return 1+size(root->left)+size(root->right);
}
int maxInTree(Node* root){
    if(root==NULL) return INT16_MIN;
    int lMax = maxInTree(root->left);
    int rMax = maxInTree(root->right);
    return max(root->val,max(lMax,rMax));
}
int minInTree(Node* root){
    if(root==NULL) return INT16_MAX;
    int lMin = minInTree(root->left);
    int rMin = minInTree(root->right);
    return min(root->val,min(lMin,rMin));
}
int levels(Node* root){
    if(root==NULL) return 0;
    return 1+max(levels(root->left),levels(root->right));
}
int main(){
    Node* a = new Node(1);   //root Node
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);

    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    display(a);
    cout<<endl;
    cout<<sum(a);
    cout<<endl;
    cout<<size(a);
    cout<<endl;
    cout<<maxInTree(a);
    cout<<endl;
    cout<<levels(a);
    cout<<endl;
    cout<<product(a);
    cout<<endl;
    cout<<minInTree(a);
}