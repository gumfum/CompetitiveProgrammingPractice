import Data.Numbers.Primes
import Data.List

hasFourDistinctPrimeFactors :: Integer -> Bool
hasFourDistinctPrimeFactors n = length (nub (primeFactors n)) == 4

isCorrectQuadruplets :: (Integer, Integer, Integer, Integer) -> Bool
isCorrectQuadruplets (a, b, c, d) = and [hasFourDistinctPrimeFactors a, hasFourDistinctPrimeFactors b, hasFourDistinctPrimeFactors c, hasFourDistinctPrimeFactors d]

main = print $ head $ filter isCorrectQuadruplets list
	where list = [(x, x+1, x+2, x+3) | x <- [1..]]