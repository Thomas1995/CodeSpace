-- 1
p1 l = head (reverse l)

-- 2 
p2 l = l !! (length l - 2)

-- 10
p10 l = p10' l 1
p10' (x:[]) n = [(x,n)];
p10' (x:y:l) n = if x == y then p10' (y:l) (n+1) else (x,n) : p10' (y:l) 1

-- 19
p19 l n = if n >= 0 then drop n l ++ take n l
	  else drop (length l + n) l ++ take (length l + n) l

-- 20
p20 n l = (l !! (n-1), take (n-1) l ++ drop n l)

-- 28
p28 :: [String] -> [String]
p28 [] = []
p28 (x:l) = p28 [li | li<-l, length li <= length x] ++ [x]
            ++ p28 [li | li<-l, length li > length x]

-- 31
p31 x = p31' x 2
p31' x y
   | y > x `div` 2 = True
   | (x `mod` y) == 0 = False
   | otherwise = p31' x (y+1)

-- 40
p40 x = p40' x 2
p40' x p
   | p31 p && p31 (x-p) = (p, x-p)
   | otherwise = p40' x (p+1)

-- 41
p41 a b
   | odd a = p41 (a+1) b
   | a > b = []
   | otherwise = p40 a : p41 (a+2) b

p41' a b 50 = [(x,y) | (x,y)<-(p41 a b), x >= 50]

-- 46
p46 :: (Bool->Bool->Bool)->[(Bool,Bool,Bool)]
p46 f = (True,True,f True True):(True,False,f True False):(False,True,f False True):(False,False,f False False):[]
