# Can modify this to simulate creating all substrings, either all the ranges or the actual substrings
def createSubstrings(word):
    substrings = []
    idxCount = [0 for _ in range(len(word))]
    for i in range(len(word)):
        for j in range(i, len(word)):
            substrings.append((i,j))
            for k in range(i, j+1):
                idxCount[k] += 1
                if k==2:
                    print(word[i:j+1])
    return idxCount

if __name__ == '__main__':
    word = "noosabasboosa"
    print(createSubstrings(word))