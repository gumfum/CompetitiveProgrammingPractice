fibList = 1 : 2 : zipWith (+) fibList (tail fibList)
evenFibList = [x | x <- fibList, mod x 2 == 0]

main = print (sum (takeWhile (<4000000) evenFibList))