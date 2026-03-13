class Solution:
    def maxStability(self, n: int, edges: list[list[int]], k: int) -> int:
        # 1. Identify all possible stability scores (candidates)
        candidates = set()
        for u, v, s, must in edges:
            candidates.add(s)
            if must == 0:
                candidates.add(2 * s)
        
        sorted_candidates = sorted(list(candidates))
        
        def can_form_tree(min_strength):
            parent = list(range(n))
            
            def find(i):
                if parent[i] == i: return i
                parent[i] = find(parent[i])
                return parent[i]

            def union(i, j):
                root_i, root_j = find(i), find(j)
                if root_i != root_j:
                    parent[root_i] = root_j
                    return True
                return False

            edges_count = 0
            upgrades_used = 0
            
            # Step A: Process MUST edges
            # If a 'must' edge forms a cycle, this min_strength (and any other) is invalid
            for u, v, s, must in edges:
                if must == 1:
                    if s < min_strength: return False
                    if not union(u, v): return False # Contradiction: Must edge forms a cycle
                    edges_count += 1
            
            if edges_count > n - 1: return False

            # Step B: Use "Free" Optional edges (already >= min_strength)
            for u, v, s, must in edges:
                if must == 0 and s >= min_strength:
                    if union(u, v):
                        edges_count += 1
            
            # Step C: Use "Upgrade" Optional edges (2*s >= min_strength)
            for u, v, s, must in edges:
                if edges_count == n - 1: break
                if must == 0 and s < min_strength and 2 * s >= min_strength:
                    if upgrades_used < k:
                        if union(u, v):
                            edges_count += 1
                            upgrades_used += 1
                            
            return edges_count == n - 1

        # 2. Binary Search for the maximum possible min_strength
        low = 0
        high = len(sorted_candidates) - 1
        ans = -1
        
        while low <= high:
            mid = (low + high) // 2
            if can_form_tree(sorted_candidates[mid]):
                ans = sorted_candidates[mid]
                low = mid + 1
            else:
                high = mid - 1
                
        return ans
