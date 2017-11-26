import Data.Numbers.Primes

check :: Integer -> Bool
check n = or [isPrime (n-2*x*x) | x <- list]
	where
		list = takeWhile (< n) [1, 2..]

main = print $ head $ filter (\x -> check x == False) list
	where list = filter (\x -> isPrime x == False) [3, 5..]
