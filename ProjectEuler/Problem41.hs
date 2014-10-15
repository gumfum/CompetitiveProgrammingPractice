import Data.List
import Data.Numbers.Primes

toInt :: String -> Int
toInt str = read str :: Int

main = print $ maximum (filter isPrime pandiginalNumbers)
	where pandiginalNumbers = map toInt (permutations "1234567")
