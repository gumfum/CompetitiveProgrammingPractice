import Data.List

toInt :: String -> Int
toInt str = read str :: Int

isPermuted :: Int -> Bool
isPermuted n = and [sort (show n) == sort x | x <- list]
	where list = map show [m*n | m <- [2..6]]

main = print $ head [n | n <- [100000 .. 166666], isPermuted n]