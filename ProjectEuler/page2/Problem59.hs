import Data.List.Split
import Data.Char
import Data.Bits
import Data.List

toInt :: String -> Int
toInt str = read str :: Int

main = do
    str <- readFile "p059_cipher.txt"
    let list = map toInt $ splitOn "," str
    let keyList = [[x, y, z] | x <- [(ord 'a')..(ord 'z')], y <- [(ord 'a')..(ord 'z')], z <- [(ord 'a')..(ord 'z')]]
    print $ map sum $ map (map ord) $ filter (isInfixOf "number") $ map (map chr) $ map (zipWith xor list) (map cycle keyList)