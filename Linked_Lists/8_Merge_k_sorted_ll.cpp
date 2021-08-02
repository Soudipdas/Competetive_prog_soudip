
typedef Node node;

struct comp{
    bool operator()(node*a, node*b){
        return (a->data>b->data);
    }
}; 
    
class Solution{
  public:
    //Function to merge K sorted linked list.
    
    
    Node * mergeKLists(Node *arr[], int k)
    {
        priority_queue<node*,vector<node*>,comp>pq;
        
        for(int i=0;i<k;i++){
            if(arr[i]!=NULL)
                pq.push(arr[i]);
        }
        if(pq.empty())
            return NULL;
        node*dummy=new node(-1);
        node*cur=dummy;
        
        while(!pq.empty()){
            node*minm=pq.top();
            pq.pop();
            
            if(minm->next)
                pq.push(minm->next);
            cur->next=minm;
            cur=cur->next;
        }
        return dummy->next;
        
           // Your code here
    }
};
