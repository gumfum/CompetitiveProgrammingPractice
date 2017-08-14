factorial :: Integer -> Integer
factorial 0 = 1
factorial 1 = 1
factorial n = n * factorial (n-1)

combi :: Integer -> Integer -> Integer
combi n r = (factorial n) `div` ((factorial r) * factorial (n-r)) 

main = print $ length $ filter (>= 1000000) [combi n r | n <- [1 .. 100], r <- [1 .. n]]