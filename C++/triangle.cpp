class Solution {
public:
    int dpf(int i, int j, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp)
    {
        if(i==n-1)
        return triangle[i][j];
        if(dp[i][j]!=-1)
        return dp[i][j];
        int downf = triangle[i][j] + dpf(i+1,j,n,triangle,dp);
        int diagonalf = triangle[i][j] + dpf(i+1,j+1,n,triangle,dp);
        return dp[i][j] = min(downf, diagonalf);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans = dpf(0,0,n,triangle,dp);
        return ans;
    }
};
