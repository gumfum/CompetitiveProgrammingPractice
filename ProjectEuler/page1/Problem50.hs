import Data.List
import Data.Numbers.Primes

makeSumPair :: [Int] -> (Int, Int)
makeSumPair list = (n, s)
	where
		n = length list
		s = sum list

isValidPrimePair :: (Int, Int) -> Bool
isValidPrimePair (n, s) = and [isPrime s, s < 1000000]

main = print $ snd (last (sort primePairList))
	where
		primePairList = filter isValidPrimePair sumPairList
		sumPairList = map makeSumPair (concat (map tails (inits primeList)))
		primeList = filter isPrime (2 : [3,5..49999])

solution = (maximumBy (\(x,y) (x',y') -> compare y y') . filter (\(x,y) -> x < 1000000 && y > 100 && isPrime' x) . concat . map (\xs -> map (\x -> (x, from Just(elemIndex x xs)+1)) xs) . map (drop 1 . scanl (+) 0) . tails . take 600) primes where isPrime' n = not(any (0 ==) (map (mod n) (take 200 primes)))
