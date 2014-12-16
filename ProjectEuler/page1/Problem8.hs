import Data.Char
import Data.List

remove :: [Char] -> [Char]
remove [] = []
remove (x:xs)
	| x == '\n' = remove xs
	| otherwise = x : remove xs

main = do
	str <- readFile "NumbersForProblem8.txt"
	let numbers = map toInteger (map digitToInt (remove str))
	let list = map (take 13) (tails numbers)
	print $ maximum (map product list)