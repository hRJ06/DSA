class Solution:
    def isValid(self, word: str) -> bool:
        vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}
        n_vowels = sum(1 for char in word if char in vowels)
        n_consonants = sum(1 for char in word if char.isalpha() and char not in vowels)
        valid = set('0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ')
        n_invalid = sum(1 for char in word if char not in valid)
        return len(word) >= 3 and n_vowels >= 1 and n_consonants >= 1 and n_invalid == 0
