template <typename T>
T interpolationSearch (T key , T p[] , int len)
{
    int start = 0 , end = len - 1;
    int mid = len / 2;
    if (key == p[end])     return end;
    if (key == p[start])   return start;
    while (p[mid] != key)
    {
        if (p[mid] < key)   start = mid;
        if (p[mid] > key)   end = mid;
        mid = (start + end) / 2;
        if (mid == start || mid == end)
              return -1;
    }
     return mid;
}
