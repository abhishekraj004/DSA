#include<iostream>
using namespace std;

class Node{

};
int searchinorder(int inorder[],int size,int target){

}
// pass the preindex by byreference
void Node* pretoin(int preorder[],int inorder[],int preindex, int inorderstart,int inorderend,int size){
    if(preindex>=size || inorderstart>inorderend){
        return NULL;
    }
    int element=preorder[prorderindex];
    preindex++;
    Node*root=new Node(element);
    // now search element from inorder
    int position=serchinorder(inorder,size,element);
    root->left=pretoin(preorder,inorder,preindex,inorderstart,positon-1,size);
    root->right=pretoin(preorder,inorder,preindex,positon+1,inorderend,size);
    return root;
}
int main(){
    int inorder[]={};
    int preorder[]={};
    int size=6;
    int preorderindex=0;
    int inorderstart=0;
    int inorderend=5;
    return 0;

}
