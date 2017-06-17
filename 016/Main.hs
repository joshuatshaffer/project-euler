module Main where

import Data.Tuple (swap)
import Data.List (unfoldr)

main :: IO ()
main = do
  print . sum . map (read . return) . show $ 2 ^ 1000
  print . sum . unfoldr (\n -> if n > 0 then Just . swap $ divMod n 10 else Nothing) $ 2 ^ 1000
