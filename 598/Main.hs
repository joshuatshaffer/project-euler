module Main where

-- given a the exponents of a prime factorization find the number of divisors
divisors :: [Integer] -> Integer
divisors = product . map (+1)

-- given a the exponents of a prime factorization find the number of divisor pairs
pairs :: [Integer] -> Integer
pairs = (`div` 2) . divisors

main :: IO ()
main = putStrLn "Hello World"
