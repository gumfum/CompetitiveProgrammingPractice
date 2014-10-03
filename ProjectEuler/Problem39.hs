import Data.List
import Data.Ord

isRightTriangle :: Int -> Int -> Int -> Bool
isRightTriangle a b c
	| a*a + b*b == c*c = True
	| otherwise = False

rightTriangleTriplets :: Int -> [(Int, Int, Int)]
rightTriangleTriplets n = [(a, b, c) | c <- [(div n 3)..n], b <- [(div (n-c) 2)..(n-c)], let a = (n-b-c), a<b, b<c, isRightTriangle a b c]

rightTriangleNum :: Int -> Int
rightTriangleNum p = length $ rightTriangleTriplets p

main = print $ fst (maximumBy (comparing snd) tuples)
	where tuples = [(n, rightTriangleNum n) | n <- [1..1000]]