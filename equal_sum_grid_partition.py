class Solution:
    def canPartitionGrid(self, grid: List[List[int]]) -> bool:
        m, n = len(grid), len(grid[0])
        
        # 1. Calculate the total sum of the entire grid
        total_sum = sum(sum(row) for row in grid)
        
        # If total sum is odd, it's impossible to split into two equal integer sums
        if total_sum % 2 != 0:
            return False
        
        target = total_sum // 2
        
        # 2. Check Horizontal Cuts (Row-wise)
        # We check prefix sums of rows. Must stop at m-1 to keep both sections non-empty.
        current_row_sum = 0
        for i in range(m - 1):
            current_row_sum += sum(grid[i])
            if current_row_sum == target:
                return True
                
        # 3. Check Vertical Cuts (Column-wise)
        # To keep it O(M*N), we first pre-calculate the sum of each individual column.
        col_sums = [0] * n
        for i in range(m):
            for j in range(n):
                col_sums[j] += grid[i][j]
        
        # Now check prefix sums of the columns. Must stop at n-1.
        current_col_sum = 0
        for j in range(n - 1):
            current_col_sum += col_sums[j]
            if current_col_sum == target:
                return True
        
        return False
