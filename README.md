# ListSort
C sorting algorithm for linked lists 

I created this algorithm as part of an assignment in 2006, as I belived that it was inefficient to
traverse the list to determine its length and mid-points in order to implement Merge or Quick sort.

Based on Merge Sort, this sorting algorithm reduces Merge Sort's best time of nlog2(n) to n, while
maintaining its worst case of nlog2(n).

The basic premis is to treat the initial list as sorted (hence the best time of n). Once an out of
order element is found, it is considered to be the start of a new 'sorted' list. Theses 2 sorted list
are then merged into a single sorted list. The next 'sorted' list is then extrated from the remaining
elements so that this process can be repeated.
