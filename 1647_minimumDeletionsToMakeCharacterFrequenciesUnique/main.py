class Solution:
    def minDeletions(self, s: str) -> int:
        countDict = {}
        for c in s:
            countDict[c] = countDict.get(c, 0) + 1

        used_freq = set()
        res = 0
        for c, freq in countDict.items():
            while freq > 0 and freq in used_freq:
                freq -= 1
                res +=1
            used_freq.add(freq)

        return res


# the first solution i came up
# not efficient
class Solution:
    def minDeletions(self, s: str) -> int:
        countDict = {}
        maxVal = 0
        for c in s:
            countDict[c] = countDict.get(c, 0) + 1
            maxVal = max(maxVal, countDict[c])

        count = [0] * (maxVal + 1)
        for val in countDict.values():
            count[val] += 1

        res = 0
        for i in range(maxVal, 0, -1):
            while count[i] > 1:
                if i - (count[i] - 1) >= 0:
                    count[i-(count[i]-1)] += 1
                    res += count[i] - 1
                    count[i] -= 1
                else:
                    res += i
                    count[i] -= 1

        return res
    

if __name__ == "__main__":
    print(Solution().minDeletions("ceabaacb"))



        

