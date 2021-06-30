#include <stdlib.h>
#include <ctime>
#include <stdio.h>
#include <math.h>

struct Array
{
    int* arr;
    int count;

    void create(int count);
    void create(int min, int max, int count);
    void create(int* source, int count);

    void destruct();

    void print();

    int getMin();
    int getMax();
    int long getSumm();

    int getElementCount(int element);
    void printElementCount();
    int getSubArrayCount(int* subArr, int count);

    void invert();
    void copyFrom(Array sourceArr);

    void indexOf(int element);

    void sortInser();
    void sortInserBin();

    void sortSelection();

    void sortBubble();

    void silf(int k, int n);
    void sortHeap();

    void sortFast(int left, int right);
    void sortFast();

    void sortComb();
};
 //________________________________________________________
void Array::create(int count)
{
    this -> count = count;
    arr = (int*)calloc(count, sizeof(int));
}

void Array::create(int min, int max, int count)
{
    this -> count = count;
    arr = (int*)calloc(count, sizeof(int));

    for (int i = 0; i < count; i++)
    {
        arr[i]  = rand() % (max - min + 1) + min;
    }
}

void Array::create(int* source,int count)
{
    this -> count = count;
    arr = (int*)calloc(count, sizeof(int));

    for (int i = 0; i < count; i++)
    {
        arr[i]  = source[i];
    }
}

void Array::destruct()
{
    free(arr);
    arr = NULL;
    count = 0;
}

void Array::print()
{
    for (int i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int Array::getMin()
{
    int min = arr[0];
    for (int i = 1; i < count; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    return min;
}

int Array::getMax()
{
    int max = arr[0];
    for (int i = 1; i < count; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

int long Array::getSumm()
{
    int summ = arr[0];
    for (int i = 1; i < count; i++)
    {
        summ += arr[i];
    }
    return summ;
}

int Array::getElementCount(int element)
{
    int n = 0;
    for (int i = 1; i < count; i++)
    {
        if (element == arr[i])
        {
            n++;
        }
    }
    return n;
}

void Array::printElementCount() //!!!!!!!!!!!!!!!!!!!!!!!
{
    bool* element;
    element = (bool*)calloc(count, sizeof(bool)); //FALSE
    int n = 0;

    for (int i = 0; i < count; i++)
    {
        if (!element[i])
        {
            n = 1;
            element[i] = true;
            for (int j = i + 1; j < count; j++)
            {
                if (arr[i] == arr[j])
                {
                    element[j] = true;
                    n++;
                }
            }
            printf("%d ", arr[i]);
            printf("- ");
            printf("%d ", n);
            printf("sht.");
            printf("\n");
        }
    }
}

int Array::getSubArrayCount(int* subArr, int count)
{
    bool get = false;
    int n = 0;
    for (int i = 0; i < (this -> count) - count + 1; i ++)
    {
        if (arr[i] == subArr[0])
        {
            get = true;
            for (int j = 1; j < count; j ++)
            {
                if (arr[i + j] != subArr[j])
                {
                   get = false;
                   break;
                }
            }

            if (get == true)
            {
                n++;
            }
        }
    }
    return (n);
}

void Array::invert()
{
    int tmp = 0;
    for (int i = 0; i < (count + 1) / 2; i++)
    {
        tmp = arr[i];
        arr[i] = arr[count - i - 1];
        arr[count - i - 1] = tmp;
    }
}

void Array::copyFrom(Array sourceArr)
{
    if(count >= sourceArr.count)
    {
         arr = (int*)realloc(arr, sourceArr.count * sizeof(int));
    }
    count = sourceArr.count;

    for (int i = 0; i < count; i++)
    {
        arr[i] = sourceArr.arr[i];
    }
}

void Array::indexOf(int element)
{
    int n = -2;
    for (int i = 0; i < count; i++)
    {
        if (arr[i] == element)
        {
            n = i;
            break;
        }
    }
    printf ("%d", n + 1);
}

void Array::sortInser()
{
   int j, tmp;
   for (int i = 1; i < count; i++)
   {
       tmp = arr[i];
       j = i - 1;
       while (tmp < arr[j] && j >= 0)
       {
           arr[j + 1] = arr[j];
           j = j - 1;
       }
       arr[j + 1] = tmp;
   }
}

void Array::sortInserBin()
{
   int j, tmp, l, r;
   for (int i = 1; i < count; i++)
   {
       tmp = arr[i];
       l = 0;
       r = i - 1;
       while (l <= r)
       {
           int m = (l + r) / 2;
           if (tmp < arr[m])
           {
               r = m - 1;
           }
           else
           {
               l = m + 1;
           }
       }
       for (int j = i - 1; j >= l; j--)
       {
           arr[j + 1] = arr[j];
       }
       arr[l] = tmp;
   }
}

void Array::sortSelection()
{
    int tmp;
    for (int i = 0; i < count - 1; i++)
    {
        int k = i;
        tmp = arr[i];
        for (int j = i + 1; j < count; j++)
        {
            if(arr[j] < tmp)
            {
                k = j;
                tmp = arr[j];
            }
        }
        arr[k] = arr[i];
        arr[i] = tmp;
    }
}

void Array::sortBubble()
{
    int tmp;
    for (int i = 0; i < count; i++)
    {
        for (int j = count - 1; j > i; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
        }
    }
}

void Array::silf(int k, int n)
{
    int child;
    int new_ = arr[k];
    while (k <= n / 2)
    {
        child = 2 * k;
        if (child < n && arr[child] < arr[child + 1])
        {
            child++;
        }
        if (new_ >= arr[child])
        {
            break;
        }
        arr[k] = arr[child];
        k = child;
    }
    arr[k] = new_;
}

void Array::sortHeap()
{
    int tmp;
    for (int i = count / 2 - 1; i >= 0; i--)
    {
        silf(i, count - 1);
    }
    for (int i = count - 1; i > 0; i--)
    {
        tmp = arr[i];
        arr[i] = arr[0];
        arr[0] = tmp;

        silf(0, i - 1);
    }
    //invert();
}

void Array::sortFast(int left, int right)
{
    int l =  left;
    int r = right;
    int mElement = arr[(right + left) / 2];
    int tmp = 0;

    while (l < r)
    {
        while (arr[l] < mElement)
        {
            l++;
        }
        while (arr[r] > mElement)
        {
            r--;
        }

        if (l <= r)
        {
            tmp = arr[l];
            arr[l] =  arr[r];
            arr[r] = tmp;
            l++;
            r--;
        }
    }

    if (r > left)
    {
        this -> sortFast(left, r);
    }
    if (l < right)
    {
        this -> sortFast(l, right);
    }
}

void Array::sortFast()
{
    this -> sortFast(0, count - 1);
}

void Array::sortComb()
{
    int fc = 1.247330950103979;
    int n = ceil(count / fc);
    int tmp;

    while (n >= 1)
    {
        for (int i = 0; i <= count - n + 1; i ++)
        {
            if (arr[i + n] < arr[i])
            {
                tmp = arr[i];
                arr[i] = arr[i + n];
                arr[i + n] = tmp;
            }
        }
        if(n == ceil(n / fc))
        {
            n--;
        }
        else
        {
            n = ceil(n / fc);
        }
    }
}

