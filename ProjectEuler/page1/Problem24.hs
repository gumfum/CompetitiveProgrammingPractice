import Data.List

listToInteger :: [Integer] -> Integer
listToInteger x = listToInteger' x 0

listToInteger' :: [Integer] -> Integer -> Integer
listToInteger' [] n = n
listToInteger' (x:xs) n = listToInteger' xs (n*10+x)

main = print $ sort (map listToInteger (permutations [0..9])) !! (1000000-1)