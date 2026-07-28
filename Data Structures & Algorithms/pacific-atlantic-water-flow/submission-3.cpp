#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int n, m;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    void bfs(vector<vector<int>>& heights, queue<pair<int,int>>& q, vector<vector<uint8_t>>& vis, uint8_t flag) {
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                // Boundary check and visited check using bitwise AND
                if (nr < 0 || nr >= n || nc < 0 || nc >= m || (vis[nr][nc] & flag))
                    continue;

                // Water flows upstream (heights must increase or stay equal)
                if (heights[nr][nc] >= heights[r][c]) {
                    vis[nr][nc] |= flag;
                    q.push({nr, nc});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();

        // 1 byte per cell to hold both Pacific (1) and Atlantic (2) flags
        vector<vector<uint8_t>> vis(n, vector<uint8_t>(m, 0));
        queue<pair<int,int>> q_pacific;
        queue<pair<int,int>> q_atlantic;

        // Initialize Ocean Borders
        for (int i = 0; i < m; i++) {
            q_pacific.push({0, i});
            vis[0][i] |= (1 << 0);

            q_atlantic.push({n - 1, i});
            vis[n - 1][i] |= (1 << 1);
        }

        for (int i = 0; i < n; i++) {
            if (!(vis[i][0] & 1)) {
                q_pacific.push({i, 0});
                vis[i][0] |= (1 << 0);
            }
            if (!(vis[i][m - 1] & 2)) {
                q_atlantic.push({i, m - 1});
                vis[i][m - 1] |= (1 <<1 );
            }
        }

        // Run BFS for both oceans
        bfs(heights, q_pacific, vis, 1);
        bfs(heights, q_atlantic, vis, 2);

        // Collect cells where both bits are set (1 | 2 = 3)
        vector<vector<int>> result;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (vis[r][c] == 3) {
                    result.push_back({r, c});
                }
            }
        }

        return result;
    }
};