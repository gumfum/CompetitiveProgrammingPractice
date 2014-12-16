import Data.Char

factorial :: Int -> Int
factorial n = product $ enumFromTo 1 n

factorialSum :: Integer -> Integer
factorialSum n = toInteger $ sum (map factorial (map digitToInt (show n)))

main = print $ sum [x | x <- [3..3000000], x == factorialSum x] 