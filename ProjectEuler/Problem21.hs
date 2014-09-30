divisorsList :: Int -> [Int]
divisorsList n = [m | m <- [1..(div n 2)], (mod n m) == 0]

d :: Int -> Int
d n = sum (divisorsList n)

main = print $ sum [m+n | m <-[1..10000], let n = d m, m < n, d n == m]