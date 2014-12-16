stringToInteger :: String -> Integer
stringToInteger = read :: String -> Integer

main = do
	str <- readFile "NumbersForProblem13.txt"
	print $ stringToInteger (take 10 (show (sum (map stringToInteger (lines str)))))