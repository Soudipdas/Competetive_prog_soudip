void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
  
  //Very simple code 

        node*slow=head,*fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast)
                break;
        }
  //If slow==fast Loop found otherwise just return list
        if(slow!=fast)
            return;
  //Now slow needs to initialized at head and fast stays at the same place ... The place they meet is the 2nd place at the loop 
        slow=head;
  
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
    
    //To find first we traverse once more
  
        while(fast->next!=slow){
            fast=fast->next;
        }
        fast->next=NULL;
    }
