import Data.List

primes = sieve [2..]
	where sieve (x:xs) = x : sieve ([y | y <- xs, mod y x /= 0])
primeFactors n = factor n primes
	where factor n (x:xs)
		| n == 1		= []
		| mod n x == 0	= x : factor (div n x) (x:xs)
		| otherwise		= factor n xs

triangleNumbers :: [Integer]
triangleNumbers = scanl1 (+) [1..]

numberOfDivisors :: Integer -> Integer
numberOfDivisors n = product (map ((+1) . toInteger . length) ((group. primeFactors) n))

main = print $ head (filter ((>500) . numberOfDivisors) triangleNumbers)