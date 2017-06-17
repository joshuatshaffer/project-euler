module Main where

divides :: Integral a => a -> a -> Bool
divides a b = a `mod` b == 0

isLY :: Integral a => a -> Bool
isLY y = divides y 400 || (not (divides y 100) && divides y 4)

mons :: Integral a => a -> [Int]
mons y = [31, if isLY y then 29 else 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

ml :: [Int]
ml = concatMap mons [1901..2000]

dl :: [Int]
dl = cycle $ [1..6]++[0]

v [] d a = (a,d)
v (m:ms) d a = if head d == 0
                then v ms d' (a+1)
                else v ms d' a
  where
    d' = drop m d

main :: IO ()
main = do
  print ml
  print $ take 20 dl
  let (_,dl') = v (mons 1900) dl 0
  print . fst $ v ml dl' 0
