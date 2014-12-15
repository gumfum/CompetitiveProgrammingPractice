import Data.List
import Data.Numbers.Primes

primeCount :: Int -> Int -> Int
primeCount a b = head (dropWhile check [0 ..])
	where check n = isPrime (n*n + a*n + b)

main = print $ ab
	where
		(ab, c) = maximumBy compare' tuples
		compare' (_, x) (_, y) = compare x y
		tuples = [(a*b, primeCount a b) | b <- takeWhile (<1000) primes, a <- [-999, -998 .. 999]]