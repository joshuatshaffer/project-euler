module Main where

import Data.List (sort)

alphVal :: String -> Int
alphVal = sum . map (\c -> fromEnum c - fromEnum 'A' + 1)

main :: IO ()
main = do
  s <- readFile "names.txt"
  let names = read $ "[" ++ s ++ "]"
  print . sum . zipWith (*) [1..] . map alphVal . sort $ names
