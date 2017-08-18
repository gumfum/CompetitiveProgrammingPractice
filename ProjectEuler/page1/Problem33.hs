isEqual :: (Int, Int) -> (Int, Int) -> Bool
isEqual (a, b) (c, d) = a*d == b*c

cancelDigit :: (Int, Int) -> (Int, Int)
cancelDigit (x, y)
	| a == c 	= (b, d)
	| a == d 	= (b, c)
	| b == c 	= (a, d)
	| b == d 	= (a, c)
	| otherwise	= (-1, -1)
	where
		a = x `mod` 10
		b = x `div` 10
		c = y `mod` 10
		d = y `div` 10


main = print $ (numerator, denominator)
	where
		list = filter (\x -> x `mod` 10 /= 0) [11 .. 99]
		fractions = [cancelDigit (a, b) | a <- list, b <- list, a < b, isEqual (a, b) (cancelDigit (a, b))]
		numerator = product $ map fst fractions
		denominator = product $ map snd fractions