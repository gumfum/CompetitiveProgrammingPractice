collatzList :: Integer -> [Integer]
collatzList 1 = [1]
collatzList n
	| even n = n : collatzList (div n 2)
	| odd n  = n : collatzList (3*n+1)

collatzTuple :: Integer -> (Integer, Integer)
collatzTuple n = (toInteger (length (collatzList n)), n)

main = print $ snd (maximum (map collatzTuple [1..1000000]))