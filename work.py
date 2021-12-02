import sys

def makePalindrome(num, base, isOdd):
    """
    num: int
    base: int
    isOdd: bool
    """
    palin = num
    if isOdd:
        num = num//base
    while num > 0:
        palin = palin * base + (num % base)
        num = num // base
    return palin

def convert(num, base):
    """
    num: int
    base: int
    """
    if num == 0:
        return 0
    else:
        return num % base + 10 * convert(num // base, base)

# def isPalindrome(num):
#     """
#     num: int
#     """
#     num = str(num)
#     return num == num[::-1]

def kmirror(k, n):
    """
    k: int
    n: int
    """
    arr = []
    based = []
    '''
    Iterate through all the palindromes starting from 1 to n
    generate the next palindrome from each palindrome number.
    '''
    for j in range(2):
        i = 1
        while (makePalindrome(i, 10, j % 2) <= N):
            arr.append(makePalindrome(i, 10, j % 2))
            i += 1
    for j in range(2):
        i = 1
        while (makePalindrome(i, k, j % 2) <= N):
            based.append(makePalindrome(i, k, j % 2))
            i += 1
    arr.sort()
    based.sort()
    i = 0
    rarr = []
    for v in arr:
        while (based[i] < v):
            i += 1
        if (based[i] == v):
            rarr.append(v)
        if len(rarr) == n:
            break
    print('result array', rarr, len(rarr))
    return sum(rarr)

# rewrite as a generator... 

# def kmirror(k: int, n: int) -> int:
    
#     def fn(x):
#         """Return next k-symmetric number."""
#         print(f'x={x}')
#         s = list(x)
#         print(s)
#         n = len(s)//2
#         print(f'len={n}')
#         for i in range(n, len(s)): 
#             print(f'i={i}')
#             print(f's[i]={s[i]}')
#             if int(s[i])+1 < k: 
#                 s[i] = s[~i] = str(int(s[i])+1)
#                 for ii in range(n, i): s[ii] = s[~ii] = '0'
#                 return "".join(s)
#         res = "1" + "0"*(len(s)-1) + "1"
#         print(res)
#         return res
            
#     x = "0"
#     ans = 0
#     for _ in range(n): 
#         while True: 
#             x = fn(x)
#             val = int(x, k) # converts the integer from base k to base 10
#             if str(val)[::-1] == str(val): break
#         ans += val
#     return ans 


if __name__ == '__main__':
    N = 70000000000 # 70 billion
    with open('input.txt', 'r') as file:
        k, n = map(int, file.readline().split())
    with open('output.txt', 'w') as file:
        sys.stdout = file
        print(kmirror(k, n))
    