
bool findPair(Node* head, int k)
{
    // Write your code here.
    Node*first=head;
    Node*sec=head;
    while(sec->next!=NULL){
        sec=sec->next;
    }
    while(first!=sec && sec->next!=first){
        if(first->data+sec->data==k){
            return true;
        }
        else if(first->data+sec->data<k)
            first=first->next;
        else
            sec=sec->prev;
    }
    return false;
    //return false;
}
