import Data.List

toInt :: String -> Int
toInt str = read str :: Int

substr :: String -> Int -> Int -> String
substr str i j = take j (drop i str)

isDivisable :: Int -> Int -> Bool
isDivisable n d = mod n d == 0

isProper :: String -> Bool
isProper str = and [isDivisable (toInt (substr str (i+1) 3)) (d!!i) | i <- [0..6]]
	where 
		d = [2, 3, 5, 7, 11, 13, 17]

main = print $ sum numList
	where 
		numList = map toInt [s | s <- strList, isProper s]
		strList = permutations "1234567890"