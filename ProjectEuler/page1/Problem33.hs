import Data.Ratio

canSimplify :: (Int, Int) -> Bool
canSimplify (a, b) = ((x == y) && (a%b == w%z))
	where
		(w, x) = divMod a 10
		(y, z) = divMod b 10

main = print $ product fractions
	where
		list = filter (\x -> x `mod` 10 /= 0) [11 .. 99]
		fractions = [a%b | a <- list, b <- list, a < b, canSimplify (a, b)]