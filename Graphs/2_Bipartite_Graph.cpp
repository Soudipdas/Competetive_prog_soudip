class Solution {
public:
  
  //Exactly same code  Just change QUEUE -- STACK
  // By BFS
    bool bipbfs(vector<int>a[],int col[],int u){
    
        queue<int>q;
        q.push(u);
        col[u]=0;
        while(!q.empty()){
            int t=q.front();
            q.pop();
            for(int i=0;i<a[t].size();i++){
                if(col[a[t][i]]==-1){
                    q.push(a[t][i]);
                    if(col[t]==0)
                        col[a[t][i]]=1;
                    else
                        col[a[t][i]]=0;
                }
                else{
                    if(col[t]==col[a[t][i]]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
  
  // By DFS
  bool bipdfs(vector<int>a[],int col[],int u){
    
        stack<int>q;
        q.push(u);
        col[u]=0;
        while(!q.empty()){
            int t=q.top();
            q.pop();
            for(int i=0;i<a[t].size();i++){
                if(col[a[t][i]]==-1){
                    q.push(a[t][i]);
                    if(col[t]==0)
                        col[a[t][i]]=1;
                    else
                        col[a[t][i]]=0;
                }
                else{
                    if(col[t]==col[a[t][i]]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
  
  
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    int col[V+1];
	    memset(col,-1,sizeof(col));
	    for(int i=0;i<V;i++){
	        if(col[i]==-1){
	            if(!bipbfs(adj,col,i))
	                return false;
	        }
	    }
	    return true;
	    
	}

};
