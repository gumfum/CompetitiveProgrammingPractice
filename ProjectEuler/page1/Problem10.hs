--http://www.cs.hmc.edu/~oneill/papers/Sieve-JFP.pdf
primes :: [Integer]
primes = 2 : (minus [3..] composites)
	where composites = union [multiples p | p <- primes]
multiples :: Integer -> [Integer]
multiples n = map (n*) [n..]
minus :: [Integer] -> [Integer] -> [Integer]
minus (x:xs) (y:ys)	| x < y  = x : minus xs (y:ys)
					| x == y = minus xs ys
					| x > y  = minus (x:xs) ys
union :: [[Integer]] -> [Integer]
union = foldr merge []
	where
		merge (x:xs) ys = x : merge' xs ys
		merge' (x:xs) (y:ys) | x < y  = x : merge' xs (y:ys)
							 | x == y = x : merge' xs ys
							 | x > y  = y : merge' (x:xs) ys	

main = print $ sum $ takeWhile (<2000000) primes