class Solution {
public:
   bool cycle_found(vector<int>&visited ,vector<vector<int>>&graph,int course)
   {
       if(visited[course]==1) return true;
        if(visited[course]==2)  return false;
       visited[course]=1;
      // int x=false;
       for(auto it: graph[course])
       {
           if(cycle_found(visited,graph,it)) return true;
       }
       visited[course]=2;
       return false;
   }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
         int n=numCourses;
         int m=prerequisites.size();
         vector<int>visited(n,0);
         vector<vector<int>>graph(n);
         for (const auto& pre : prerequisites) {
    graph[pre[1]].push_back(pre[0]);
}

         for(int i=0;i<n;i++)
         {
            if(visited[i]==0 && cycle_found(visited,graph,i)==true)
            {
                return false;
            }
            
         }
         return true;

        
    }
};
