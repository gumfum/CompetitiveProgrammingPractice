combination :: Integer -> Integer -> Integer
combination m n = div (product [m-n+1..m]) (product [1..n])

main = print $ combination 40 20