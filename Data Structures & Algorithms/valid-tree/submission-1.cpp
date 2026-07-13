class Solution {
public:


void  dfs(vector<int>&visited, int& count ,vector<vector<int>>&graph,int current)
       {
           if(visited[current]==1)
           {
              return ;
           } 

           visited[current]=1;
           count--;
           for(auto it:graph[current])
           {
              dfs(visited,count,graph,it);
           }
           
       }
    bool validTree(int n, vector<vector<int>>& edges) {
       vector<int>visited(n,0);
       int count=n;
       vector<vector<int>>graph(n);
       int current=0;

       for(int i=0;i<edges.size();i++)
       {
           graph[edges[i][0]].push_back(edges[i][1]);
           graph[edges[i][1]].push_back(edges[i][0]);
       }

       

        if(edges.size()==n-1)
        {
            dfs(visited,count,graph,current);
            if(count==0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }

    }
};
