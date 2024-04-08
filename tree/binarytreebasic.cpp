#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
    

};

// it return the root node of create tree
 Node*createtree(){
        cout<<"enter the value of node"<<endl;
        int data;
        cin>>data;

        if(data==-1){
            return NULL;
        }
        // step1 create root 
        Node*root= new Node(data);
        // create left subtree
        root->left=createtree();
        // create right subtree
        root->right=createtree();
        return root;
    }

void preorder(Node*root){
    // base case
    if(root==NULL){
        return;
    }
    // NLR(condtion of preorder)
    // N
    cout<<root->data<<" ";
    // L
    preorder(root->left);
    // R
    preorder(root->right);
}

void inorder(Node*root){
    // LNR
    // base case
    if(root==NULL){
        return;
    }
    //L
    inorder(root->left);
    //N
    cout<<root->data;
    // R
    inorder(root->right);

}

void postorder(Node*root){
    // base case
    if(root==NULL){
        return ;
    }
    // LRN
    //L
    postorder(root->left);
    // R
    postorder(root->right);
    // N
    cout<<root->data;
}

void levelordertraversal(Node*root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    // lets  start traversal
    while(!q.empty()){
        Node*front=q.front();
        q.pop();
        if(front==NULL){
           cout<<endl;
           if(!q.empty())
           q.push(NULL); 
        }
        else{
           cout<<front->data<<" ";
        if(front->left!=NULL){
            q.push(front->left);
        }
        if(front->right!=NULL){
            q.push(front->right);
        } 
            
        }
        
    }
}
int main(){
     Node*root=createtree();
     cout<<root->data<<endl;
}