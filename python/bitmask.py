from collections import Counter
import sys
"""
An example of using functional programming in python with bitmask and dfs
"""
def findNumOfValidWords(words, puzzles):
    """
    Given a list of words and a list of puzzles, find the number of valid words
    """
    def char_to_bit(char):
        """
        Convert a character to a bit string.
        """
        return 1 << (ord(char) - ord('a'))

    def word_to_mask(word):
        """
        Convert a word to a bit mask.
        """
        mask = 0
        for bit in map(char_to_bit, word):
            mask |= bit
        return mask

    counts = Counter(map(word_to_mask, words))
    valids = [0 for _ in range(len(puzzles))]
    def dfs(pidx, subpuzzle, pos, submask):
        """
        pidx is the index of the puzzle we are currently working on
        subpuzzle is the current puzzle we are working on
        pos is the current position in the puzzle
        submask is the current mask of the word
        """
        if pos == len(subpuzzle):
            valids[pidx] += counts[submask]
            return
        dfs(pidx, subpuzzle, pos+1, submask)
        dfs(pidx, subpuzzle, pos+1, submask | char_to_bit(subpuzzle[pos]))

    for i, puzzle in enumerate(puzzles):
        dfs(i, puzzle, 1, char_to_bit(puzzle[0]))
    return valids


if __name__ == '__main__':
    words = ["aaaa","asas","able","ability","actt","actor","access"]
    puzzles = ["aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"]
    sys.stdout = open("output.txt", "w")
    print(findNumOfValidWords(words, puzzles))
    sys.stdout.close()
