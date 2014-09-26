import Data.List
import Data.Ord

countCycle :: Int -> Int
countCycle d = countCycle' d 10 []

countCycle' :: Int -> Int -> [Int] -> Int
countCycle' d 0 rs = 0
countCycle' d r rs =
	let r' = mod r d
	in case elemIndex r' rs of
		Just i  -> i + 1
		Nothing -> countCycle' d (10 * r') (r':rs)

main = do
	let tuples = [(n, countCycle n) | n <- [1..1000]]
	print $ fst (maximumBy (comparing snd) tuples)