integerToList = reverse . integerToList'

integerToList' :: Integer -> [Integer]
integerToList' 0 = []
integerToList' n = mod n 10 : integerToList' (div n 10)

factorial :: Integer -> Integer
factorial 1 = 1
factorial n = n * factorial (n-1)

main = print $ sum (integerToList (factorial 100))