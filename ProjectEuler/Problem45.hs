isPentagonal :: Integer -> Bool
isPentagonal n = (floor m == ceiling m)
	where m = ((sqrt (1+24*(fromInteger n))) + 1) / 6
	
hexagonals :: [Integer]
hexagonals = [2*n*n-n | n <- [1,2..]]

main = print $ head [n | n <- dropWhile (<= 40755) hexagonals, isPentagonal n]