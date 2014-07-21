fibList :: [Integer]
fibList = 0 : 1 : zipWith (+) fibList (tail fibList)

digits :: Integer -> Integer
digits n = digits' n 0

digits' :: Integer -> Integer -> Integer
digits' 0 0 = 1
digits' 0 n = n
digits' m n = digits' (div m 10) (n+1)

main = print $ length (takeWhile (<1000) (map digits fibList))