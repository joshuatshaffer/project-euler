module Main where

import Data.Tuple (swap)
import Data.List (unfoldr,genericIndex)
import Data.Char (isLetter)

units :: Integral i => i -> String
units n = genericIndex wl (n - 1)
  where wl = ["one", "two", "three", "four", "five",
         "six", "seven", "eight", "nine", "ten", "eleven",
         "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
         "seventeen", "eighteen", "nineteen"]

tens :: Integral i => i -> String
tens n = genericIndex wl (n - 2)
  where wl = ["twenty", "thirty", "forty", "fifty",
              "sixty", "seventy", "eighty", "ninety"]

shortScale :: Integral i => i -> String
shortScale n = genericIndex wl (n - 1)
  where wl = ["thousand", "million", "billion", "trillion",
              "quadrillion", "quintillion", "sextillion",
              "septillion", "octillion", "nonillion", "decillion"]

to19 :: Integral i => i -> String
to19 0 = "zero"
to19 n = units n

to99 :: Integral i => i -> String
to99 n | n < 20    = to19 n
       | b == 0    = tens a
       | otherwise = tens a ++ "-" ++ to19 b
  where (a,b) = quotRem n 10

to999 :: Integral i => i -> String
to999 n | n < 100   = to99 n
        | b == 0    = units a ++ " hundred"
        | otherwise = units a ++ " hundred and " ++ to99 b
  where (a,b) = quotRem n 100

splitThousands :: Integral a => a -> [a]
splitThousands = unfoldr (\n -> if n > 0 then Just . swap $ quotRem n 1000 else Nothing)

showInWords :: Integral i => i -> String
showInWords n
  | n == 0    = "zero"
  | n < 0     = "negative " ++ showInWords (negate n)
  | otherwise = unwords . reverse . concatMap foo . zip [0..] . splitThousands $ n
  where
    foo :: Integral i => (i, i) -> [String]
    foo (_, 0) = []
    foo (0, m) = [to999 m]
    foo (i, m) = [to999 m ++ " " ++ shortScale i]

main :: IO ()
main = print . sum . map (length . filter isLetter . showInWords) $ [1..1000]
