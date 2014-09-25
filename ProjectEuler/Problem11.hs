import Data.Array
import Data.List.Split

convertStringToInteger :: String -> Integer
convertStringToInteger str = read str :: Integer

toIntegerList :: String -> [Integer]
toIntegerList str = map convertStringToInteger (concat (map (splitOn " ") (lines str)))

maxMulHorizontal :: Array (Integer, Integer) Integer -> Integer
maxMulHorizontal array =
	maximum [(mul i j) | i <- [1..20], j <- [1..17]]
	where mul i j = (array!(i, j) * array!(i, j+1) * array!(i, j+2) * array!(i, j+3))

maxMulVertical :: Array (Integer, Integer) Integer -> Integer
maxMulVertical array =
	maximum [(mul i j) | i <- [1..17], j <- [1..20]]
	where mul i j = (array!(i, j) * array!(i+1, j) * array!(i+2, j) * array!(i+3, j))

maxMulDiagonalRD :: Array (Integer, Integer) Integer -> Integer
maxMulDiagonalRD array =
	maximum [(mul i j) | i <- [1..17], j <- [1..17]]
	where mul i j = (array!(i, j) * array!(i+1, j+1) * array!(i+2, j+2) * array!(i+3, j+3))

maxMulDiagonalLD :: Array (Integer, Integer) Integer -> Integer
maxMulDiagonalLD array =
	maximum [(mul i j) | i <- [1..17], j <- [4..20]]
	where mul i j = (array!(i, j) * array!(i+1, j-1) * array!(i+2, j-2) * array!(i+3, j-3))

maxMul :: Array (Integer, Integer) Integer -> Integer
maxMul array = maximum [maxMulHorizontal array, maxMulVertical array, maxMulDiagonalRD array, maxMulDiagonalLD array]

main = do
	str <- readFile "NumbersForProblem11.txt"
	let array = listArray ((1, 1), (20, 20)) (toIntegerList str)
	print $ (maxMul array)