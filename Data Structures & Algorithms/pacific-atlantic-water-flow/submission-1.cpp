class Solution {
public:

    int n, m;
    // Direction vectors for moving UP, DOWN, LEFT, RIGHT
    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};
   
    void dfs(vector<vector<int>>&heights , int r, int c , vector<vector<int>>&visited)
    {
       if(visited[r][c]==1) return ;
       visited[r][c]=1;
       
       for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            // 1. Check grid boundaries
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            
            // 2. Skip if already visited
           // if (visited[nr][nc]) continue;

            // 3. Move uphill or stay level (height[neighbor] >= height[current])
            if (heights[nr][nc] >= heights[r][c]) {
                dfs(heights, nr, nc, visited);
            }
        }


    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
           n=heights.size();
         m=heights[0].size();
        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));

       

        for(int i=0 ; i<m ;i++)
        {
           
            dfs(heights, 0 , i ,pacific);
        
        }

        for(int i=0;i<n;i++)
        {
            
            dfs(heights, i , 0 ,pacific);
        }

        for(int i=0 ; i<m ;i++)
        {
           
            dfs(heights, n-1 , i ,atlantic);
        
        }

        for(int i=0;i<n;i++)
        {
            
            dfs(heights, i , m-1 ,atlantic);
        }

        

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
