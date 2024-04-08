#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int value){
        this->data=value;
        this->left=NULL;
        this->right=NULL;
    }
};

Node*insertintobst(Node*root,int data){
    if(root==NULL){
        root= new Node(data);
        return root;
    }
    if(data>root->data){
       root->right= insertintobst(root->right,data);
    }
    else{
        root->left=insertintobst(root->left,data);
    }
}

void createbst(Node*&root){
    int data;
    cout<<"Enter the data";
    cin>>data;
    while(data!=-1){
        root=insertintobst(root,data);
        cin>>data;
    }
}

void levelorder(Node*root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node*temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
    }
}

 Node*minvalue(Node*root){
    if(root==NULL){
      return  NULL;
    }
    Node*temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

Node*maxvalue(Node*root){
    if(root==NULL){
        return NULL;
    }
    Node*temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}

// very important ,delete the node as per required
Node* deletefrombst(Node*root,int target){
    if(root==NULL){
        return NULL;
    }
    // if target get found than for case is possible
    if(target==root->data){
        // 1 case both left and right is null means ki it is leaf nonde
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        // 2 case when left is equal to null but right is not null
        else if(root->left==NULL && root->right!=NULL){
            Node*childnode=root->right;
            delete root;
            return childnode;
        }
        else if(root->left!=NULL && root->right==NULL){
            Node*childnode=root->left;
            delete root;
            return childnode;
        }
        // else one is 4 case when both of right and left not equal to null
        else{
            Node*maxi=maxvalue(root->left);
            root->data=maxi->data;

            root->left=deletefrombst(root->left,maxi->data);
            return root;
        }

        
    }

    else if(root->data>target){
         root->left=deletefrombst(root->left,target);   
    }
    else{
        root->right=deletefrombst(root->right,target);
    }
    

}


Node *bstfrominorder(int inorder[],int s,int e){
    // base case
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    int element=inorder[mid];
    Node*root=new Node(element);
    root->left=bstfrominorder(inorder,s,mid-1);
    root->right=bstfrominorder(inorder,mid+1,e);
    return root; 

}


void convertbsttodll(Node*root,Node*&head){
    if(root==NULL){
        return;
    }
    // rnl
    convertbsttodll(root->right,head);
    /* node part */
    root->right=head;
    if(head!=NULL){
        head->left=root;
    }
    head=root;
    // left part
    convertbsttodll(root->left,head);
}

void printll(Node*head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"-> ";
        temp=temp->right;
    }
    cout<<endl;
}


int main(){
    int inorder[]={1,2,3,4,5,6,7,8,9};
    int s=0;
    int e=8;
    Node*root=bstfrominorder(inorder,s,e);
    
    Node*head=NULL;
    levelorder(root);
    convertbsttodll(root,head);
    printll(head);
    

    
}