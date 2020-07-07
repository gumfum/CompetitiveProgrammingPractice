countDigit :: Integer -> Integer
countDigit n = floor ((log (1.0*(fromIntegral n))) / (log 10)) + 1

isPowerfulPair :: (Integer, Integer) -> Bool
isPowerfulPair (x, n) = n == countDigit (x^n)

main = print $ length $ filter isPowerfulPair [(x, n) | x <- [1..9], n <- [1..21]]
