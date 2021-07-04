class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
    //int b=0;
    
    //By BFS
    bool cycbfs(vector<int>a[],int u,int vis[],int par[]){
        
        queue<int>q;
        q.push(u);
        
        vis[u]=1;
        
        while(!q.empty()){
            int node=q.front();
            
            q.pop();
            
            for(int i=0;i<a[node].size();i++){
                
                if(!vis[a[node][i]]){
                    vis[a[node][i]]=1;
                    q.push(a[node][i]);
                    par[a[node][i]]=node;
                }
                else{
                    if(par[node]!=a[node][i]){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
    //By DFS
    bool cycdfs(vector<int>a[],int par,int vis[],int u){
        vis[u]=1;
        for(int i=0;i<a[u].size();i++){
            if(!vis[a[u][i]]){
                if(cycdfs(a,u,vis,a[u][i]))
                    return true;
            }
            else if(par != a[u][i]){
                return true;
            }
        }
        return false;
    }
    
	bool isCycle(int V, vector<int>adj[])
	{
	    int vis[V+1]={0};
	    int par[V+1];
	    memset(par,-1,sizeof(par));
	    for(int i=0;i<V;i++){
	        if(vis[i]==0){
	            if(cycdfs(adj,-1,vis,i))
	                return true;
	        }
	    }
	    return false;
	}
};
