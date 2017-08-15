import Data.List
import Data.Numbers.Primes

isPermutated :: Int -> Int -> Int -> Bool
isPermutated a b c = 
	((sort $ show a) == (sort $ show b)) && ((sort $ show b) == (sort $ show c))

isArithmetic :: Int -> Int -> Int -> Bool
isArithmetic a b c = (c - b) == (b - a)

-- too slow algorithm
main = print $ [(a, b, c) | a <- list, b <- list, c <- list, isPermutated a b c, isArithmetic a b c, a < b, b < c]
	where
		list = filter isPrime [1000 .. 9999]