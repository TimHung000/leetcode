import math

class Solution:
    def eliminateMaximum(self, dist: List[int], speed: List[int]) -> int:
        minuteToFail = []
        for d, s in zip(dist, speed):
            minute = math.ceil(d / s)
            minuteToFail.append(minute)
        minuteToFail.sort()
        res = 0
        for minute in minuteToFail:
            if minute > res:
                res += 1
            else:
                break
        return res