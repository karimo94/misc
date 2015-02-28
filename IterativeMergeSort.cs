static void iterativeMergeSort(int[] items, int first, int last)
        {
            int[] temp = new int[items.Length];
            int left, middle, right;
            for (int outer = 1; outer < last; outer *= 2)
            {
                for (int inner = 0; inner < last; inner += outer * 2)
                {
                    left = inner;
                    middle = (inner + outer) - 1;
                    right = (inner + (outer * 2))-1;
                    Merge(items, left, middle, right, temp);
                }
            }
        }
        static void Merge(int[] items, int first, int mid, int last, int[] temp)
        {
            if (mid >= items.Length)
            {
                mid = items.Length - 1;
            }
            if (last >= items.Length)
            {
                last = items.Length - 1;
            }
            int first1 = first;
            int last1 = mid;
            int first2 = mid + 1;
            int last2 = last;

            int index = first1;
            while (first1 <= last1 && first2 <= last2)
            {
                if (items[first1] < items[first2])
                {
                    temp[index] = items[first1];
                    first1++;
                }
                else
                {
                    temp[index] = items[first2];
                    first2++;
                }
                index++;
            }
            //finish off anything remaining
            while (first1 <= last1)
            {
                temp[index] = items[first1];
                first1++;
                index++;
            }
            while (first2 <= last2)
            {
                temp[index] = items[first2];
                first2++;
                index++;
            }
            for (index = first; index <= last; index++)
            {
                items[index] = temp[index];
            }           
        }
