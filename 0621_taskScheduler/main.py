from typing import List
import collections
import heapq

class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:

        count = collections.Counter(tasks)
        maxHeap = [-cnt for cnt in count.values()]
        heapq.heapify(maxHeap)

        time = 0
        queue = collections.deque()

        while maxHeap or queue:
            time += 1

            if maxHeap:
                cnt = 1 + heapq.heappop(maxHeap)
                if cnt != 0:
                    queue.append((cnt, time + n))
            
            if queue and queue[0][1] == time:
                heapq.heappush(maxHeap, queue.popleft()[0])
        
        return time
    

"""
Example explanation:

tasks = ["A","A","A","B","B","B"], n = 2

Procedure:

1.
# Build a dictionary for tasks
# key   : task
# value : occurrence of task

max_occ = 3

number_of_taks_of_max_occ = 2 with {'A', 'B'}

2.
#Make (max_occ - 1) = 2 groups, groups size = n+1 = 3
#Fill each group with uniform iterleaving as even as possible

group = '_ _ _' with size = 3

=> make 2 groups with uniform iterleaving 

A B _ A B _

3.
# At last, execute for the last time of max_occ jobs

A B _ A B _ A B


length of task scheduling with cooling = 8

'''


from collections import Counter

"""
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        
        if n == 0:
            # Quick response for special case on n = 0
            # no requirement for cooling, just do those jobs in original order
            return len(tasks)
        
        
        # key   : task
        # value : occurrence of tasks 
        task_occ_dict = collections.Counter( tasks )
        
        # max occurrence among tasks
        max_occ = max( task_occ_dict.values() )
        
        # number of tasks with max occurrence
        number_of_taks_of_max_occ = sum( ( 1 for task, occ in task_occ_dict.items() if occ == max_occ ) )
        
        # Make (max_occ-1) groups, each groups size is (n+1) to meet the requirement of cooling
        # Fill each group with uniform iterleaving as even as possible
        
        # At last, execute for the last time of max_occ jobs
        intervl_for_schedule = ( max_occ-1 )*( n+1 ) + number_of_taks_of_max_occ
        
        # Minimal length is original length on best case.
        # Otherswise, it need some cooling intervals in the middle
        return max( len(tasks), intervl_for_schedule)