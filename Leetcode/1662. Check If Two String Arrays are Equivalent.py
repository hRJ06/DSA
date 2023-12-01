class Solution:
    def arrayStringsAreEqual(self, word1: List[str], word2: List[str]) -> bool:
        a = ""
        b = ""
        for s in word1:
            a += s
        for s in word2:
            b += s
        return a == b