class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        seen = set()
        results = set()
        for i in range(len(s) - 9):
            pattern = s[i:i+10]
            if pattern not in seen:
                seen.add(pattern)
            else:
                results.add(pattern)
        return list(results)
