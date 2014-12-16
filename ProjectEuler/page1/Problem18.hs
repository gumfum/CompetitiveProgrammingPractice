import Data.List.Split

toInt :: String -> Int
toInt str = read str :: Int

toIntList :: [String] -> [Int]
toIntList list = map toInt list

sumMax :: Int -> Int -> Int -> Int
sumMax a b c = a + max b c

sumMaxList :: [Int] -> [Int] -> [Int]
sumMaxList xs ys = zipWith3 sumMax xs ys (tail ys)

main = do
	str <- readFile "NumbersForProblem18.txt"
	let list = map (splitOn " ") (lines str)
	let intList = map toIntList list
	print $ head (foldr1 sumMaxList intList)