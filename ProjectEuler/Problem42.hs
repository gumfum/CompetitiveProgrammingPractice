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

triangleNumbers :: [Integer]
triangleNumbers = scanl1 (+) [1..]

main = do
	input <- readFile "words.txt"
	let wordList = read ("[" ++ input ++ "]")
	let wordValues = map getNameValue wordList
	print $ length (filter ((flip elem) (take 100 triangleNumbers)) wordValues)