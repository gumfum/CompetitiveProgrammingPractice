import Data.List
import Data.Numbers.Primes

toInt :: String -> Int
toInt str = read str :: Int

isTruncatablePrime :: Int -> Bool
isTruncatablePrime n = all isPrime (truncatedNumbers n)

truncatedNumbers :: Int -> [Int]
truncatedNumbers n = map toInt ((tail $ inits s) ++ (init $ tails s))
	where s = show n

main = print $ sum (take 11 [x | x <- primes, 10 < x, isTruncatablePrime x])
