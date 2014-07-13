list = [1..100]
sumOfTheSqureas = sum $ map (^2) list
squaresOfTheSum = (sum list) * (sum list)

main = print $ squaresOfTheSum - sumOfTheSqureas