list = [a*b*(1000-a-b) | a <- [1..1000], b <- [a+1..1000-a], a*a+b*b==(1000-a-b)*(1000-a-b)]

main = mapM_ print list