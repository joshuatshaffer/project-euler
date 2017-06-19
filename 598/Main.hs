module Main where

{-
1 : (1,1) = 1
2 : (1,2) = 1
3 : (1,3) = 1
4 : (1,4) (2,2) = 1
5 : (1,5) = 1
6 : (1,6) (2,3) = 1
7 : (1,7) = 1
-}

-- given a the exponents of a prime factorization find the number of divisors
divisors :: [Integer] -> Integer
divisors = product . map (+1)

-- given a the exponents of a prime factorization find the number of divisor pairs
pairs :: [Integer] -> Integer
pairs = (`div` 2) . divisors

pad :: a -> [a] -> [a] -> ([a],[a])
pad z xs ys = if a > 0 then (xs, ys ++ b) else (xs ++ b, ys)
  where
    a = length xs - length ys
    b = replicate (abs a) z

factUnion :: [Integer] -> [Integer] -> [Integer]
factUnion x y = uncurry (zipWith (+)) $ pad 0 x y

factorize 1 = []

main :: IO ()
main = putStrLn "Hello World"
