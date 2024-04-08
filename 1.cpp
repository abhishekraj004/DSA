#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node*prev;
    node*next;

    node(){
        this->prev=NULL;
        this->next=NULL;
    }
    node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
};

void print(node*head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int findll(node*head){
    node*temp=head;
    int leng=0;
    while(temp!=NULL){
        leng++;
        temp=temp->next;
    }
    return leng;
}

void insertathead(node *&head,node*&tail,int data){
        
    if(head==NULL){
        node*newnode=new node(data);
        head=newnode;
        tail=newnode;
    }

    else{
        node* newnode= new node(data);
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
}

void insertattail(node *&head,node*&tail,int data){
    if(head==NULL){
        node*newnode=new node(data);
        head=newnode;
        tail=newnode;
    }

    else{
        node* newnode=new node(data);
        newnode->prev=tail;
        tail->next= newnode;
        tail=newnode;
    }
}

void insertatposition(node *&head,node*&tail,int data,int pos){
    if(head=NULL){
        node*newnode=new node(data);
        head=newnode;
        tail=newnode;
    }

    else{
        int len=findll(head);
        if(pos==1){
            insertathead(head,tail,data);
        }
        else if(pos==len+1){
            insertattail(head,tail,data);
        }
        else{
            node*newnode=new node(data);
            node*prevnode=NULL;
            node* currnode=head;
            while(pos!=1){
                pos--;
                prevnode=currnode;
                currnode=currnode->next;
            }
            prevnode->next=newnode;
            newnode->prev=prevnode;
            newnode->next=currnode;
            currnode->prev=newnode;
        }

    }

}


void deletenode(node*&head,node*&tail,int pos){
    if(head==NULL){
        cout<<"can not delete"<<endl;
        return;
    }
    int len=findll(head);
    if(head==tail){
        node*temp=head;
        delete temp;
        head=NULL;
        tail=NULL;
        return;
    }


    if(pos==1){
        //delete from head
        node*temp=head;
        head=head->next;
        head->prev=NULL;
        temp->next=NULL;
        delete temp;

    }

    else if(pos==len){
        node*prevnode=tail->prev;
        prevnode->next=NULL;
        tail->prev=NULL;
        delete tail;
        tail=prevnode;
    }
    else{
        //delete from middile
        node*prevnode=NULL;
        node*currnode=head;
        while(pos!=1){
            pos--;
            prevnode=currnode;
            currnode=currnode->next;
        }
        node*nextnode=currnode->next;
        prevnode->next=nextnode;
        currnode->prev=NULL;
        currnode->next=NULL;
        nextnode->prev=prevnode;
        delete currnode;
    }
}

 
int main(){
    node*head=new node(10);
    node*tail=NULL;
}