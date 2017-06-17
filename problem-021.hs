module Main where

import System.IO

divides :: Integral a => a -> a -> Bool
a `divides` b = b `mod` a == 0

d :: Integral a => a -> a
d n = sum . filter (`divides` n) $ [1..(n-1)]

isAmicable :: Integral a => a -> Bool
isAmicable a = a /= b && d b == a
  where b = d a

main :: IO ()
main = do
  let az = filter isAmicable $ [1..10000]
  hSetBuffering stdout NoBuffering
  print az
  print $ sum az
