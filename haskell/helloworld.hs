addOne :: Int -> Int
addOne n = n + 1

addOneM :: Int -> IO Int
addOneM n = do
  print $ "Applying (+1) to " ++ show n ++ " ..."
  return $ n + 1

timesThree :: Int -> Int
timesThree n = n * 3

timesThreeM :: Int -> IO Int
timesThreeM n = do
  print $ "Applying (*3) to " ++ show n ++ " ..."
  return $ n * 3

subtractTwo :: Int -> Int
subtractTwo n = n - 2

subtractTwoM :: Int -> IO Int
subtractTwoM n = do
  print $ "Subtracting 2 from " ++ show n ++ " ..."
  return $ n - 2
