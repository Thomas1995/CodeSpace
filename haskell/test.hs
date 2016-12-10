-- mergesort

inter l [] = l
inter [] l = l
inter l1 l2 = if head l1 < head l2 
	      then head l1 : inter (drop 1 l1) l2
	      else head l2 : inter l1 (drop 1 l2)

mergesort [] = []
mergesort [x] = [x]
mergesort l = inter (mergesort (take half l)) 
	            (mergesort (drop half l))
	      where half = length l `div` 2

-- qsort

qsort [] = []
qsort l = qsort (filter (<mid) l) ++ [mid] ++ qsort (filter (>mid) l)
	where mid = l !! (length l `div` 2)

-- qsort (chei multiple)

mqsort [] = []
mqsort l = mqsort [x | x<-li, x <= mid] ++ [mid] ++ mqsort [x | x<-li, x > mid]
         where half = length l `div` 2
	       mid = l !! half
	       li = take half l ++ drop (half+1) l

-- split

splitch :: Char->String->[String]
splitch c [] = []
splitch c l = li : splitch c (drop (1 + length li) l)
	  where li = takeWhile (/=c) l

split = splitch ' '

-- delete

deleteall c l = foldr (\x acc -> if x == c then acc else x : acc ) [] l

delete c [] = []
delete c (x:l) = if x == c
		 then l
		 else x : delete c l

-- extract min sort

minsort [] = []
minsort l = minimum l : minsort (delete (minimum l) l)

-- huffman
extract_min [] mn = mn
extract_min (x:l) mn
	| snd mn > snd x = extract_min l x
	| otherwise = extract_min l mn
extract_min' l = extract_min (drop 1 l) (head l)

huffman' [x] = []
huffman' l = (fst first, 0) : (fst second, 1) : huffman' (fise:l2)
	where first = extract_min' l
	      l1 = delete first l
	      second = extract_min' l1
	      l2 = delete second l1
	      fise = (fst first ++ fst second, snd first + snd second)

getpath l c = getstring [show (snd e) | e<-(huffman' l), c `elem` fst e]
getstring [] = []
getstring (x:l) = getstring l ++ x

chtostr l = [(fst e : [], snd e) | e<-l]

huffman [x] = [(fst x, "0")]
huffman l = [(fst e, getpath (chtostr l) (fst e) ) | e<-l]
