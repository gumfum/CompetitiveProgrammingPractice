sumSquareDigit :: Int -> Int
sumSquareDigit 0 = 0
sumSquareDigit n = (mod n 10)^2 + sumSquareDigit (div n 10)

loopSumSquareDigit :: Int -> Int
loopSumSquareDigit 1 = 1
loopSumSquareDigit 89 = 89
loopSumSquareDigit n = loopSumSquareDigit $ sumSquareDigit n

main = print $ length . filter (== 89) $ map loopSumSquareDigit [1..10000000]
