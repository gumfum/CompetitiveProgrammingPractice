frac :: Int -> (Integer, Integer)
frac n
    | n == 0 = (3, 2)
    | otherwise = (x+2*y, x+y)
        where   
            x = fst $ a !! (n-1)
            y = snd $ a !! (n-1)

a :: [(Integer, Integer)]
a = map frac [0..]

isProper :: (Integer, Integer) -> Bool
isProper (x, y) = (length $ show x) > (length $ show y)

main = print $ length $ filter isProper $ take 1000 a