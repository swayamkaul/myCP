with open('input.txt') as f:
    lines = f.readlines()

from heapq import *

class solve():
    def _init_(self,a,b,c):
        self.a = a
        self.b = b
        self.c = c
        self.ans = [float("inf")]*a

        self.m = {i:[] for i in range(a)}
        self.cost = {}

        for a,b,c,t in c:
            self.m[a].append([b,c,t])
            self.m[b].append([a,c,t])
    #dijkstra algo
    def dk(self,s):
        pq = [[0,s]]
        visited = set()
        self.ans[s] = min(self.ans[s],self.b[s])

        while pq:
            w,cur = heappop(pq)
            if cur in visited:
                continue
            visited.add(cur)
            for node,c,t in self.m[cur]:
                cost = (w+c)*(1+t) + self.b[node]
                print(cost)
                self.ans[cur] = min(cost,self.ans[cur])
                heappush(pq,[w+c,node])


    def solution(self):
        for i in range(self.a):
            # applying for each node, not very optimized
            self.dk(i)
        return self.ans

for _ in range(1):
    a = int(lines[0])
    b = list(map(int,lines[1].split()))
    c = []
    for i in range(a-1):
        row = list(map(int,lines[2].split()))
        c.append(row)
    obj = solve(a,b,c)
    print(obj.solution())