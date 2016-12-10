def qsort(li):
    if not li: return li
    mid = li[len(li)/2]
    return qsort([elem for elem in li if elem < mid]) + [mid] + qsort([elem for elem in li if elem > mid])
