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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //node*ans;
        int c=0;
        node*ans=NULL;
        node*p=ans;
        while(l1!=NULL && l2!=NULL){
            int sum=(l1->val+l2->val)+c;
            int fill=sum%10;
            c=sum/10;
            if(ans==NULL){
                ans=new node(fill);
                p=ans;
            }
            else{
                node*t=new node(fill);
                p->next=t;
                p=p->next;
            }
            l1=l1->next;
            l2=l2->next;
        }
        
        while(l1!=NULL){
            int sum=(l1->val)+c;
            int fill=sum%10;
            c=sum/10;
            if(ans==NULL){
                ans=new node(fill);
                p=ans;
            }
            else{
                node*t=new node(fill);
                p->next=t;
                p=p->next;
            }
            l1=l1->next;
            
        }
        
        while(l2!=NULL){
            int sum=(l2->val)+c;
            int fill=sum%10;
            c=sum/10;
            if(ans==NULL){
                ans=new node(fill);
                p=ans;
            }
            else{
                node*t=new node(fill);
                p->next=t;
                p=p->next;
            }
            l2=l2->next;
            
        }
        
        if(c!=0){
            node*t=new node(c);
            p->next=t;
            p=p->next;
        }
        return ans;
    }
};
