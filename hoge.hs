import Data.List
import Data.Numbers.Primes

factorial :: Integer -> Integer
factorial 0 = 1
factorial n = n * factorial (n-1)

evalue :: Integer -> Integer
evalue 0 = 10^1000
evalue n = div (10^1000) (factorial n) + evalue (n-1)

toInt :: String -> Integer
toInt s = read s :: Integer

evalueStr = take 1000 (show (evalue 2000))

main = print $ head (filter isPrime numList)
	where
		numList = map toInt list 
		list = map (take 10) (tails evalueStr)