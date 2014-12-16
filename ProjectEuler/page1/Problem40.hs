import Data.Char

champernowne :: String
champernowne = concat [show x | x <- [0..]]

d :: Int -> Int
d n = digitToInt (champernowne !! n)

main = print $ (d 1) * (d 10) * (d 100) * (d 1000) * (d 10000) * (d 100000) * (d 1000000)