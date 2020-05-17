import Data.List.Split

toDouble :: String -> Double
toDouble str = read str :: Double

toDoubleList :: [String] -> [Double]
toDoubleList list = map toDouble list

toTuple :: [a] -> (a,a)
toTuple [a,b] = (a,b)

calculate :: (Double, Double) -> Double
calculate (b, e) = e * log b

main = do
  str <- readFile "p099_base_exp.txt"
  let list = map (splitOn ",") (lines str)
  let tuples = map toTuple $ map toDoubleList list
  let calculatedTuples = zip (map calculate tuples) [1..] 
  print $ snd $ maximum calculatedTuples
