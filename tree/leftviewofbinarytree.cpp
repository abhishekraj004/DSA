#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;
class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;

    }
};
Node*createtree(){
    int value;
    cin>>value;
    if(value==-1){
        return NULL;
    }
    // create tree;
    Node*root= new Node(value);
    root->left=createtree();
    root->right=createtree();
    return root;

}

void preorder(Node*root){
    if(root==NULL){
        return ;
    }
    //NLR;
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
}

// level order
void levelordere(Node*root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
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

void leftview(Node*root,int level,vector<int> &leftside){
    if(root==NULL){
        return;
    }
    if(level==leftside.size()){
        // means left view ki node mil gai hai
        leftside.push_back(root->data);
    }
    leftview(root->left,level+1,leftside);
    leftview(root->right,level+1,leftside );
}

void topview(Node*root,int hd){
    map<int,int> hdtonodemap;
    queue<pair<Node*,int>> q;
    q.push(make_pair(root,0));
    while(!q.empty()){
       pair<Node*,int> temp=q.front();
       q.pop();
       Node*frontNode=temp.first;
       int hd=temp.second;
       // if there is no entry for hd in map then create a new entry in map
       if(hdtonodemap.find(hd)==hdtonodemap.end()){
        hdtonodemap[hd]=frontNode->data;
       } 
       // child ka lia 
       if(frontNode->left!=NULL){
        q.push(make_pair(frontNode->left,hd-1));
       }

       if(frontNode->right!=NULL){
        q.push(make_pair(frontNode->right,hd+1));
       }
    }
    cout<<"printing top view "<<endl;
    for(auto i: hdtonodemap){
        cout<<i.second<<" "; 
    }
}

void bottomview(Node*root,int hd){
    map<int,int> hdtonodemap;
    queue<pair<Node*,int>> q;
    q.push(make_pair(root,0));
    while(!q.empty()){
       pair<Node*,int> temp=q.front();
       q.pop();
       Node*frontNode=temp.first;
       int hd=temp.second;
       // overwrite the answer so that deeper nodes can be stored 
        hdtonodemap[hd]=frontNode->data;
       
       // child ka lia 
       if(frontNode->left!=NULL){
        q.push(make_pair(frontNode->left,hd-1));
       }

       if(frontNode->right!=NULL){
        q.push(make_pair(frontNode->right,hd+1));
       }
    }
    cout<<"printing top view "<<endl;
    for(auto i: hdtonodemap){
        cout<<i.second<<" "; 
    }
}



// these three left,leaf,right boundary combine print the bundary of the binary tree
void printleftboundary(Node*root){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        return;
    }
    cout<<root->data;
    if(root->left!=NULL){
        printleftboundary(root->left);
    }
    else{
        printleftboundary(root->right);
    }
}

void printleafboundary(Node*root){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        cout<<root->data;
    }
    printleafboundary(root->left);
    printleafboundary(root->right);
}

void printrightbundary(Node*root){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        return;
    }

    if(root->right!=NULL){
        printrightbundary(root->right);
    }
    else{
        printrightbundary(root->left);
    }
    cout<<root->data<<" ";
}

void boundarytraverasal(Node*root){
    if(root==NULL){
        return;
    }
    printleftboundary(root);
    printleafboundary(root);
    if(root->right!=NULL){
        printrightbundary(root->right);
    }
    else{
        printrightbundary(root->left);
    }
}

int main(){

}