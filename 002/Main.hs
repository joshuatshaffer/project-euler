module Main where

fibs :: [Integer]
fibs = 0:scanl (+) 1 fibs

main :: IO ()
main = print . sum . filter even $ takeWhile (< 4000000) fibs
