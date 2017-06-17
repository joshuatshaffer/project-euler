module Main where

import Data.List (union)

main :: IO ()
main = do
  print . sum . filter (\x -> x `mod` 3 == 0 || x `mod` 5 == 0) $ [1..999]
  print . sum $ union [0,3..999] [0,5..999]
