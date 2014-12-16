import Data.Set

powersOfDigits :: Integer -> Integer
powersOfDigits = powersOfDigits' 0

powersOfDigits' :: Integer -> Integer -> Integer
powersOfDigits' n 0 = n
powersOfDigits' n m = powersOfDigits' (n + ((mod m 10) ^ 5)) (div m 10)

main = print $ sum [x | x <- [2..1000000], x == powersOfDigits x]