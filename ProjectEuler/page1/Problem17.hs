zeroToNineteen = [
	"zero", "one", "two", "three", "four",
	"five",	"six", "seven", "eight", "nine",
	"ten", "eleven", "twelve", "thirteen", "fourteen",
	"fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
	]

twentyToNinety = [
	"", "", "twenty", "thirty", "forty",
	"fifty", "sixty", "seventy", "eighty", "ninety"
	]

numberLetters :: Int -> String
numberLetters n
	| n == 0 = []
	| n < 20 = (zeroToNineteen !! n)
	| 20 <= n && n < 100 = twentyToNinety !! (div n 10) ++ numberLetters (mod n 10)
	| 100 <= n && n < 1000 && mod n 100 == 0 = zeroToNineteen !! (div n 100) ++ "hundred"
	| 100 < n && n < 1000 = numberLetters ((div n 100) * 100) ++ "and" ++ numberLetters (mod n 100)
	| n == 1000 = "onethousand"

main = print $ length (concat (map numberLetters [1..1000]))