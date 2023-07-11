from typing import List
from collections import defaultdict
from collections import Counter
import heapq

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = defaultdict(lambda: 0)
        for num in nums:
            freq[num] += 1
        
        freq = dict(sorted(freq.items(), key = lambda x: x[1], reverse=True))
        result = list(freq.keys())[:k]
        return result

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq_table = {}
        for i in nums:
            freq_table[i] = freq_table.get(i, 0) + 1
        heap = []
        for i in freq_table.keys():
            if len(heap) == k: # If size is k then we dont want to increase the size further 
                heapq.heappushpop(heap, (freq_table[i], i))
            else: # Size is not k then freely push values
                heapq.heappush(heap, (freq_table[i], i))
		# After this operation the heap contains only k largest values of all the values in nums
        ans = []
        while k > 0:
            k -= 1
            ans.append(heapq.heappop(heap)[1])
        return ans

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq_table = Counter(nums)
        ans_table = freq_table.most_common()
        ans = []
        for key, _ in ans_table:
            if k <= 0:
                break
            k -= 1
            ans.append(key)
        return ans
    
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq_table = Counter(nums)
        heap = []
        for i in freq_table.keys():
            heapq.heappush(heap, (freq_table[i], i))
        freq_table = heapq.nlargest(k,heap)
        ans = []
        for i, j in freq_table:
            ans.append(j)
        return ans
    
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq_table = Counter(nums)
        heap = []
        for i in freq_table.keys():
            heapq.heappush(heap, (-freq_table[i], i))
        ans = []
        while k > 0:
            k -= 1
            ans.append(heapq.heappop(heap)[1])
        return ans