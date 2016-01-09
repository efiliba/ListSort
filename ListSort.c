void sort(EmplList **head, int (*fnPtr)(EmplRec, EmplRec))
{
    *head = listSort(*head, fnPtr);     /* Can just call head=listSort(head) */
}

/* Based on Merge Sort, this sort algorithm reduces Merge Sort's best time of
// nlog2(n) to n, and maintains its worst case of nlog2(n). It is simpler to 
// implement for linked lists, than Merge Sort, as you do not need to know the
// number of nodes to repeatedly halve.
//
// I have also optimised the merging algorithm, it's also useful in Merge Sort.
// Instead of just recursively merging the top elements in each list, it scans
// the lists looking for the next position to merge them at. This results in
// the other list now having the smallest item, so only that list has to be
// scanned. Basically, determine the list with the smallest head item, scan its
// elements looking for the first value greater than the head of the other list
// Repeat, alternating remaining list with previous big head, until all done.*/

EmplList* listSort(EmplList *head, int (*fnPtr)(EmplRec, EmplRec))
{
   EmplList *list = head;                 /* The current sorted list's head  */
   EmplList *nextList = NULL;             /* Start of next list to sort      */

   while (list->next && fnPtr(list->data, list->next->data))      /* Ordered?*/
      list = list->next;

   nextList = list->next;                 /* Set start pos of unsorted list  */
   list->next = NULL;                     /* Break sorted list from unsorted */

   /* If no more elements to sort then return this list, else sort remaining */
   return nextList ? mergeList(head, ListSort(nextList, fnPtr), fnPtr) : head;
}

EmplList* mergeList(EmplList *left, EmplList *right, int (*fnPtr)(EmplRec, EmplRec))
{
   /* Use list with the smallest head to start merging from, will alternate */
   return fnPtr(left->data, right->data) ?
      joinToSmallest(left, right, fnPtr) : joinToSmallest(right, left, fnPtr);
}

/* Merge big side into small side - i.e. right into left */
EmplList* joinToSmallest(EmplList *small, EmplList *big, int (*fnPtr)(EmplRec, EmplRec))
{
   EmplList *head = small;

   /* Traverse list with smallest head finding first item > item on big side */
   while (small->next && fnPrt(small->next->data, big->data))
      small = small->next;

   /* Alternate small->next and big, until small exhausted, then set to big  */
   small->next = small->next ? joinToSmallest(big, small->next, fnPtr) : big;

   return head;
}
