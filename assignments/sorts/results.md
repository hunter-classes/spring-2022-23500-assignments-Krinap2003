//OBSERVATION HOW DIFFERENT SORTING ALGORITHMS PERFORM

On a randomly selected array
    On a small size array all the algorithms(merge, quick1_badpivot, quick1_goodpivot,quick2_badpivot, and quick2_goodpivot) 
    performed the same they all had a run time of 0. But on a medium size vector of 500 quick2_badpivot and quick2_goodpivot 
    performed the best and almost the same, than the quick1_goodpivot than quick1_badpivot and last was merge sort. This could be because the qsort2
    algorithm saves time on creating different vectors. When the size of the vector was increased more to 100000, qsort2 performed
    the best than the quick1_badpivot, quick1_goodpivot, and merge sort.

On an already sorted vector
    When I tested these three 
    algorithms on Already sorted vector of size of large size, quick sort2 with a bad pivot point was slower than quickpoint2 good pivot point.
    the original quick sort algorithm with good pivot point was significatly faster than the one with bad pivot point.
    The merge sort did performe better than the original quick with bad pivot point. quick sort got slower as the size of the vector 
    increases and the merge sort got faster.
