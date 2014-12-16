primes = 2 : sieve [3,5..]
	where sieve (x:xs) = x : sieve ([y | y <- xs, mod y x /= 0])
primeFactors n = factor n primes
	where factor n (x:xs)
		| n == 1		= []
		| mod n x == 0	= x : factor (div n x) (x:xs)
		| otherwise		= factor n xs
isPrime 1 = False
isPrime n = case (primeFactors n) of
	(_:_:_) 	-> False
	otherwise	-> True

rotationList :: Int -> [Int]
rotationList n = rotationList' n []

rotationList' :: Int -> [Int] -> [Int]
rotationList' n ns
	| elem n ns = ns
	| otherwise = rotationList' (nextRotation n) (n:ns)

nextRotation :: Int -> Int
nextRotation n = (div n 10) + (mod n 10) * (10 ^ (length (show n) - 1))

isCircularPrime :: Int -> Bool
isCircularPrime n = isPrimeList $ rotationList n

isPrimeList :: [Int] -> Bool
isPrimeList l = and (map isPrime l)

notContainFive :: Int -> Bool
notContainFive n = not (elem '5' (show n))

main = print $ (length (filter (== True) (map isCircularPrime primeList)) + 1)
	where primeList = filter notContainFive (takeWhile (<1000000) primes)