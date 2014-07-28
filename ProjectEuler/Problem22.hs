import Data.Char
import Data.List

getCharValue :: Char -> Integer
getCharValue c = toInteger(ord c - ord 'A' + 1)

getNameValue :: [Char] -> Integer
getNameValue s = getNameValue' s 0 

getNameValue' :: [Char] -> Integer -> Integer
getNameValue' [] n = n
getNameValue' (x:xs) n
	| isUpper x = getNameValue' xs (n + getCharValue x)
	| otherwise = getNameValue' xs n

getScore :: (Integer, [Char]) -> Integer
getScore (a, b) = a * getNameValue b

main = do 
	input <- readFile "names.txt"
	let nameList = sort (read ("[" ++ input ++ "]"))
	let nameValues = map getNameValue nameList
	print $ sum (zipWith (*) [1..] nameValues)