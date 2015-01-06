import Data.List

toInt :: String -> Int
toInt str = read str :: Int

makeTriplet :: String -> [(Int, Int, Int)]
makeTriplet str = [makeTriplet1 str, makeTriplet2 str]

makeTriplet1 :: String -> (Int, Int, Int)
makeTriplet1 str = (a, b, c)
	where
		a = toInt (take 2 str)
		b = toInt (take 3 (drop 2 str))
		c = toInt (drop 5 str)

makeTriplet2 :: String -> (Int, Int, Int)
makeTriplet2 str = (a, b, c)
	where
		a = toInt (take 1 str)
		b = toInt (take 4 (drop 1 str))
		c = toInt (drop 5 str)

isValidTriplet :: (Int, Int, Int) -> Bool
isValidTriplet (a, b, c) = (a * b == c)

main = print $ sum products
	where 
		get (a, b, c) = c
		products = nub (map get vaildTriplets)
		vaildTriplets = [t | t <- triplets, isValidTriplet t]
		triplets = concat (map makeTriplet (permutations "123456789"))