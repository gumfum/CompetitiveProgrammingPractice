import Data.Char

toBinaryString :: Int -> String
toBinaryString n = toBinaryString' "" n

toBinaryString' :: String -> Int -> String
toBinaryString' str 0 = str
toBinaryString' str n = toBinaryString' ((intToDigit (mod n 2)) : str) (div n 2)

isPalindromeString :: String -> Bool
isPalindromeString str = str == reverse str

isPalindromeNumber :: Int -> Bool
isPalindromeNumber n = isPalindromeString (show n)

main = print $ sum [x | x <- [1..1000000], isPalindromeNumber x, isPalindromeString (toBinaryString x)]

