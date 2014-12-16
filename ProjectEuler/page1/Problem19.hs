countDays n
	| mod n 100 == 0 = 365
	| mod n 4 == 0   = 366
	| otherwise      = 365

daysList n
	| n == 366  = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
	| otherwise = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

days = scanl1 (+) (concat (map daysList (map countDays [1901..2000])))

main = print $ length (filter (\x -> mod x 7 == 0) days)