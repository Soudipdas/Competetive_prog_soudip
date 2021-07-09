#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef struct node{
    int data;
    node*next;
};

node*top;

void push(int data){
    node*temp=new node();
    temp->data=data;

    temp->next=top;
    top=temp;
}

void pop(){
    if(top==NULL)
        return;
    node*temp=top;
    top=top->next;
    temp->next=NULL;
    free(temp);
}

bool isempty(){
    if(top==NULL)
        return false;
    return true;
}

int peek(){
    if(top==NULL)
        return -1;
    return top->data;
}

int main() {

    push(4);
    push(3);
    push(88);
    push(-2);
    pop();
    pop();
    cout<<peek()<<" ";
    pop();
    pop();
    pop();
}
