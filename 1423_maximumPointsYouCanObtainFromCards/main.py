class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        frontToEnd = [0] * (k + 1)
        endToFront = [0] * (k + 1)
        for i in range(k):
            frontToEnd[i+1] = frontToEnd[i] + cardPoints[i]
            endToFront[i+1] = endToFront[i] + cardPoints[len(cardPoints)-i-1]
        
        res = 0
        for i in range(k+1):
            cur = frontToEnd[i] + endToFront[k-i]
            if cur > res:
                res = cur

        return res


    # sliding window technique
    def maxScore1(delf, cardPoints: List[int], k:int) -> int:
        leftPtr, rightPtr = 0, len(cardPoints) - k
        total = sum(cardPoints[rightPtr:])
        res = total

        while rightPtr < len(cardPoints):
            total += (cardPoints[leftPtr] - cardPoints[rightPtr])
            res = max(res, total)
            leftPtr += 1
            rightPtr += 1
        return res

