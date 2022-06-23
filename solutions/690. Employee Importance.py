"""
# Definition for Employee.
class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates
"""
class Solution:
    def getImportance(self, employees: List['Employee'], id: int) -> int:
        root: Employee = None
        for e in employees:
            if e.id == id:
                root = e
                break
        importance: int = root.importance
        if not root.subordinates:
            return importance
        q = collections.deque()
        q.extend(root.subordinates)
        while len(q):
            id = q.popleft()
                
            for e in employees:
                if e.id == id:
                    root = e
                    break
            importance += root.importance
            q.extend(root.subordinates)
        
        return importance
