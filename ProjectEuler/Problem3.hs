primes = sieve [2..]
	where sieve (x:xs) = x : sieve ([y | y <- xs, mod y x /= 0])
primeFactors n = factor n primes
	where factor n (x:xs)
		| n == 1		= []
		| mod n x == 0	= x : factor (div n x) (x:xs)
		| otherwise		= factor n xs

main = print $ maximum (primeFactors 600851475143)