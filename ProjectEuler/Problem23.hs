import Data.Array

divisorsList :: Int -> [Int]
divisorsList n = [m | m <- [1..(div n 2)], (mod n m) == 0]

sumOfDivisors :: Int -> Int
sumOfDivisors n = sum $ divisorsList n

isAbundant :: Int -> Bool
isAbundant n
	| n < sumOfDivisors n = True
	| otherwise = False

main = print $ sum list
	where
		list = filter notAbundantSum [1..28123]
		abundantArray = listArray (1, 28123) [isAbundant n | n <- [1..28123]]
		abundantList = filter (abundantArray!) [1..28123]
		notAbundantSum n = and [not $ abundantArray ! (n - m) | m <- (takeWhile (<= div n 2) abundantList)]