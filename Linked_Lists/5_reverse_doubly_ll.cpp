
struct Node* reverseDLL(struct Node * head)
{
    while(head){
        struct Node*next=head->next;
        head->next=head->prev;
        head->prev=next;
        if(head->prev==NULL){
            //return head;
            break;
        }
        head=head->prev;
    }
    return head;
}
