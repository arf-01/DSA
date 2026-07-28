class Solution {
public:

    int n, m;
    // Direction vectors for moving UP, DOWN, LEFT, RIGHT
    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};
   
    void bfs(vector<vector<int>>&heights  ,queue<pair<int,int>>&q,  vector<vector<int>>&vis)
    {  

        

         while(!q.empty())
         {
            pair<int,int>p = q.front();
            q.pop();
           

               for(int i=0;i<4;i++)
               {
                  int nr=p.first +dr[i];
                  int nc=p.second+dc[i];

                  if (nr < 0 || nr >= n || nc < 0 || nc >= m || vis[nr][nc]==1)
                         continue;

                 

                  if(heights[nr][nc]>= heights[p.first][p.second])
                  {
                     q.push({nr,nc});
                     vis[nr][nc]=1;
                  }


               }
         }

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
         n=heights.size();
         m=heights[0].size();
        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>>atlantic(n, vector<int>(m, 0));

        queue<pair<int,int>>q_pacific;
        queue<pair<int,int>>q_atlantic;

       

        for(int i=0 ; i<m ;i++)
        {
            q_pacific.push({0,i});
            pacific[0][i]=1;
        
        }

        for(int i=0;i<n;i++)
        {
            
            q_pacific.push({i,0});
            pacific[i][0]=1;
        }

        for(int i=0 ; i<m ;i++)
        {
           
            q_atlantic.push({n-1,i});
            atlantic[n-1][i]=1;
        
        }

        for(int i=0;i<n;i++)
        {
            q_atlantic.push({i,m-1});
            atlantic[i][m-1]=1;
            
        }

        bfs(heights,q_pacific,pacific);
        bfs(heights,q_atlantic,atlantic);

        

      vector<vector<int>> result;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r, c});
                }
            }
        }

        return result;
        
    }
};
