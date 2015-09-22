import Data.List

toInt :: String -> Int
toInt s = read s :: Int

main = print $ maximum properNumList
	where
		properNumList = [(fst t) * 100000 + (snd t) | t <- properTuples]
		properTuples = [t | t <- tuples, div (snd t) (fst t) == 2, mod (snd t) (fst t) == 0]
		tuples = [(toInt (take 4 s), toInt (drop 4 s)) | s <- list]
		list = permutations "123456789"