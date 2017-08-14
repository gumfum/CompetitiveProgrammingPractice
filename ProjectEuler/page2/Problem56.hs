digitSum :: Integer -> Integer
digitSum 0 = 0
digitSum n = (n `mod` 10 ) + digitSum (n `div` 10)

main = print $ maximum $ map digitSum [a^b | a <- [1 .. 100], b <- [1 .. 100]]