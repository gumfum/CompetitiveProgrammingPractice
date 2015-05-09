ways :: [Int] -> [Int]
ways [] = 1 : repeat 0
ways (c : coins) = n
	where n = zipWith (+) (ways coins) (replicate c 0 ++ n)

main = print $ ways [1, 2, 5, 10, 20, 50, 100, 200] !! 200