typedef struct node node;

struct node*update(struct node*start,int p)
{
    //Add your code here
    node*nhead;
    node*end=start;
    while(end!=NULL && p>0){
        p--;
        end=end->next;
    }
    nhead=end;
    node*temp=nhead->prev;
    nhead->prev=NULL;
    temp->next=NULL;
    
    while(end->next!=NULL){
        end=end->next;
    }
    end->next=start;
    start->prev=end;
    return nhead;
}
