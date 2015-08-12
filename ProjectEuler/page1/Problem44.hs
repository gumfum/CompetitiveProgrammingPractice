import Data.Set

pentaList :: [Int]
pentaList = [div (x*(3*x-1)) 2 | x <- [1..4000]]

isPenta :: Int -> Bool
isPenta n = member n pentaSet
	where
		pentaSet = fromList pentaList

main = print $ head [a-b | a <- pentaList, b <- pentaList, a > b, isPenta (a+b), isPenta (a-b)]