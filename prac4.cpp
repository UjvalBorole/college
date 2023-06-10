
#include <iostream>
using namespace std;

int check(int d, int x[10], int size)
{
    int flag = 0, i;
    for (i = 0; i < size; i++)
    {
        if (x[i] == d)
            flag = 1;
    }
    return flag;
}

int printse(int x[20], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (x[i] == -1)
            cout << "\t-";
        else
            cout << "\t" << x[i];
    }
    return 0;
}

int fifo(int a[20], int size, int n)
{
    int i, x[5], j, k = 1, flag, fault = 0;
    float s;
    for (i = 0; i < size; i++)
        x[i] = -1;
    j = 0;
    for (i = 0; i < n; i++)
    {
        flag = check(a[i], x, size);
        if (!flag)
        {
            x[j] = a[i];
            fault++;
            cout << "\nPAGE FRAME " << k++ << ":";
            printse(x, size);
            j = (j + 1) % 3;
        }
    }
    s = (float)fault / (float)n;
    cout << "\nTOTAL NO FAULTS ARE: " << fault;
    cout << "\nFAULT RATE IS: " << s;
    return 0;
}

int find0(int a[20], int n, int x[5], int size, int p)
{
    int k = 0, t[5], m = -1, j, i, q;
    j = 0;
    do
    {
        for (i = p; i < n; i++)
        {
            if (x[j] == a[i])
                break;
        }
        t[++k] = i;
        j++;
    } while (j < size);
    for (i = 0; i < size; i++)
    {
        if (t[i] > n)
            return i;
    }
    i = 0;
    while (i < size)
    {
        if (m < t[i])
        {
            m = t[i];
            q = i;
        }
        i++;
    }
    return q;
}

int find1(int a[20], int p, int x[5], int size)
{
    int j, i, t[5], q, m = 999, k = 0;
    j = 0;
    do
    {
        for (i = p; i >= 0; i--)
        {
            if (x[j] == a[i])
                break;
        }
        t[k++] = i;
        j++;
    } while (j < size);
    i = 0;
    while (i < size)
    {
        if (m > t[i])
        {
            m = t[i];
            q = i;
        }
        i++;
    }
    return q;
}

int optimal(int a[20], int n, int size)
{
    int i, x[5], j, flag, fault = 0, k = 1;
    float s;
    for (i = 0; i < size; i++)
        x[i] = -1;
    j = -1;
    for (i = 0; i < n; i++)
    {
        flag = check(a[i], x, size);
        if (!flag)
        {
            if (fault >= 3)
                j = find0(a, n, x, size, i + 1);
            else
                j++;
            x[j] = a[i];
            fault++;
            cout << "\nPAGE FRAME: " << k++;
            printse(x, size);
        }
    }
    cout << "\nTOTAL NO OF FAULTS ARE: " << fault;
    s = (float)fault / (float)n;
    cout << "\nFAULT RATE: " << s;
    return 0;
}

int lru(int a[20], int size, int n)
{
    int j, i, x[5], flag, fault = 0, k = 1;
    float s;
    for (i = 0; i < size; i++)
    {
        x[i] = -1;
    }
    j = -1;
    for (i = 0; i < n; i++)
    {
        flag = check(a[i], x, size);
        if (!flag)
        {
            if (fault >= 3)
                j = find1(a, i - 1, x, size);
            else
                j++;
            x[j] = a[i];
            fault++;
            cout << "\nPAGE FRAME: " << k++;
            printse(x, size);
        }
    }
    cout << "\nTOTAL NO FAULTS ARE: " << fault;
    s = (float)fault / (float)n;
    cout << "\nFAULT RATE: " << s;
    return 0;
}

int main()
{
    int i, size, n, a[20], ch;
    char c;
    cout << "\nENTER THE FRAME SIZE: ";
    cin >> size;
    cout << "\nHOW MANY PAGES DO YOU WANT TO ENTER: ";
    cin >> n;
    cout << "\nENTER THE SEQUENCE OF PAGES: ";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    do
    {
        cout << "\n1. FIFO ALGORITHM";
        cout << "\n2. OPTIMAL ALGORITHM";
        cout << "\n3. LRU ALGORITHM";
        cout << "\n4. EXIT";
        cout << "\nENTER YOUR CHOICE: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            fifo(a, size, n);
            break;
        case 2:
            optimal(a, size, n);
            break;
        case 3:
            lru(a, size, n);
            break;
        case 4:
            exit(0);
        }
    } while (ch != 4);
    return 0;
}
