/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
typedef ListNode node;
class Solution {
public:
    
    
//APPROACH -- 
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        node*p=head;
        node*prev=NULL;
        node*temp;
        node*par=NULL;
        int len=0;
        int ext=k;
        
        //Find length
        while(p!=NULL){
            p=p->next;
            len++;
        }
        p=head;
        int tot=len/k;
        
        //Reverse in groups
        while(k && tot){
            
            //Normal reverse
            temp=p->next;
            p->next=prev;
            prev=p;
            p=temp;
            --k;
            
            //If k==0 i.e. one rotation ends we will do the following
            if(k==0){
                
                tot--;
                //We'll do this only once and ave the result head
                if(par==NULL){
                    par=prev;
                }
                
                //For other rotations we'll do this
                else if(par!=NULL){
                    node*pp=par;
                    while(pp->next!=NULL){
                        pp=pp->next;
                    }
                    pp->next=prev;
                }
                
                //After every rotation we need to fix this
                prev=NULL;
                
                //If total is >0 we'll continue our loop 
                if(tot>0)
                    k=ext;
                
                //If no more loops allowed we'll tie up the remaining nodes
                //Only to be done when situation is as given in this question 
                else{
                    node*pp=par;
                    while(pp->next!=NULL){
                        pp=pp->next;
                    }
                    pp->next=p;
                }
            }  
        }
        return par;
        
    }
};
