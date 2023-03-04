template <typename T>
void insertionSort (T *p , int len)
{
    T temp;
    for (int i, j = 1; j < len; j++)
    {
          temp = p[j];
          i = j - 1;
          while (i >= 0 &&  p[i] > temp)
          {
              p[i+1] = p[i];
              i--;
          }
          p[i+1] = temp;
    }
}
