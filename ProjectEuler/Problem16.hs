integerToList = reverse . integerToList'

integerToList' :: Integer -> [Integer]
integerToList' 0 = []
integerToList' n = mod n 10 : integerToList' (div n 10)

main = print $ sum (integerToList (2 ^ 1000))