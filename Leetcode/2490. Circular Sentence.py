class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        words = sentence.split(' ')
        n = len(words)
        check = True
        for i in range(n - 1):
            if words[i][len(words[i]) - 1] != words[i + 1][0]:
                check = False
                break
        check = check and words[n - 1][len(words[n - 1]) - 1] == words[0][0]
        return check