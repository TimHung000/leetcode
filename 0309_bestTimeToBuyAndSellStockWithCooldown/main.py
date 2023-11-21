from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        mem = [-1] * n
        def findMax(cur, n):
            if cur >= n:
                return 0
            if mem[cur] != -1:
                return mem[cur]
            
            maxVal = 0
            # buy the stock on cur day
            for i in range(cur+1, n):
                if prices[cur] < prices[i]:
                    # we can sell the stock at ith day and findMax from i+2th day
                    # we don't sel the stock on ith day
                    maxVal = max(maxVal, prices[i] - prices[cur] + findMax(i+2, n))

            # do not by the stock on cur day
            maxVal = max(maxVal, findMax(cur+1, n))
            mem[cur] = maxVal
            return maxVal
        
        return findMax(0, n)
    
class Solution1:
    def maxProfit(self, prices: List[int]) -> int:
        n = prices.size()
        if n <= 1:
            return 0
        noStock = [0] * n
        inHand = [0] * n
        Sold = [0] * n

        inHand[0] = -prices[0]

        for i in range(1, n):
            noStock[i] = max(noStock[i-1], Sold[i-1])
            inHand[i] = max(inHand[i-1], noStock[i-1] - prices[i])
            Sold[i] = inHand[i-1] + prices[i]

        res = max(noStock[-1], Sold[-1])
        return res


        