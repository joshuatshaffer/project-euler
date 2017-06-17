module Main where

fac n = product [1..n]

paths n m = fac (n + m) `div` (fac n * fac m)

main :: IO ()
main = print $ paths 20 20
