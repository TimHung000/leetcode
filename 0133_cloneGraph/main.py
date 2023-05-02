from typing import Dict

class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        def newNode(_map: Dict['Node', 'Node'], _node: 'Node' ):
            if node is None:
                return None

            cloneNode = Node(_node.val, [])
            map[_node] = cloneNode

            for neighbor in _node.neighbors:
                if neighbor in map:
                    cloneNode.neighbors.append(map[neighbor])
                else:
                    cloneNode.neighbors.append(newNode(_map, neighbor))
            return cloneNode

        map: Dict['Node', 'Node'] = dict()
        return newNode(map, node)



if __name__ == '__main__':
    sol = Solution()
    sol.cloneGraph(None)

