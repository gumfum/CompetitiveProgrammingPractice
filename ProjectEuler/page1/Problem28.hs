a n = (2*n-1) ^ 2
b n = 4*(a n) - 12*(n-1)

main = print $ sum (map b [2..501]) + 1