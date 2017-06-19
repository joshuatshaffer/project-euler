module Main where

fac :: (Enum a, Num a) => a -> a
fac n = product [1..n]

popAt :: Int -> [a] -> (a, [a])
popAt n xs = (head ys, take n xs ++ tail ys)
  where ys = drop n xs

perm :: Int -> [a] -> [a]
perm _ [] = []
perm n xs = y:perm m ys
  where
    (d,m) = divMod n $ fac (length xs - 1)
    (y,ys) = popAt d xs

main :: IO ()
main = do
  print $ perm (1000000 - 1) "0123456789"
