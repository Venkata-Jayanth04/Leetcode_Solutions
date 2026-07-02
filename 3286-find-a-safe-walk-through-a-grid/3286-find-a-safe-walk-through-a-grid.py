from collections import deque
from typing import List

class Solution:
    def findSafeWalk(self, grid: List[List[int]], health: int) -> bool:
        m = len(grid)
        n = len(grid[0])

        dist = [[float('inf')] * n for _ in range(m)]

        dq = deque()

        dist[0][0] = grid[0][0]
        dq.appendleft((0,0))

        directions = [(-1,0),(1,0),(0,-1),(0,1)]

        while dq:
            r,c = dq.popleft()

            for dr,dc in directions:
                nr = r + dr
                nc = c + dc

                if nr < 0 or nr >= m or nc < 0 or nc >= n:
                    continue
                
                cost = grid[nr][nc]

                if dist[r][c] + cost < dist[nr][nc]:
                    dist[nr][nc] = dist[r][c] + cost

                    if cost == 0:
                        dq.appendleft((nr,nc))
                    else:
                        dq.append((nr,nc))
    
        return dist[m - 1][n - 1] < health