reverseNumber :: Integer -> Integer
reverseNumber = read . reverse . show

isPalindromic :: Integer -> Bool
isPalindromic n = show n == (reverse $ show n)

isLychrel :: Integer -> Bool
isLychrel n = isLychrel' 1 (n + reverseNumber n)

isLychrel' :: Integer -> Integer -> Bool
isLychrel' t n
	| t == 50 			= True
	| isPalindromic n 	= False
	| otherwise			= isLychrel' (t+1) (n + reverseNumber n)

main = print . length . filter (== True) $ map isLychrel [1 .. 10000]