module Main where

main :: IO ()
main = print $ sum . map (read . return) . show $ product [1..100]
