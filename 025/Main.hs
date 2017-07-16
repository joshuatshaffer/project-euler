module Main where

fibs = 0:scanl (+) 1 fibs

main :: IO ()
main = print . fst . head . dropWhile ((< 1000) . length . snd) . zip [0..] $ map show fibs
