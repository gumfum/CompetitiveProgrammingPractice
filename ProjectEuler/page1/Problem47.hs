import Data.Numbers.Primes
import Data.List

factors :: Integer -> [Integer]
factors n = [x | x <- [1] ++ primes, n `mod` x == 0]

factorization :: Integer -> [Integer]
factorization 1 = []
factorization x = v : factorization (x `div` v)
  where
    v = (factors x) !! 1

hasFourDistinctPrimeFactors :: Integer -> Bool
hasFourDistinctPrimeFactors n = length (nub (factorization n)) == 4

isCorrectQuadruplets :: (Integer, Integer, Integer, Integer) -> Bool
isCorrectQuadruplets (a, b, c, d) = and [hasFourDistinctPrimeFactors a, hasFourDistinctPrimeFactors b, hasFourDistinctPrimeFactors c, hasFourDistinctPrimeFactors d]

main = print $ head $ filter isCorrectQuadruplets list
	where list = [(x, x+1, x+2, x+3) | x <- [1..]]