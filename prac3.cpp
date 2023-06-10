#include <iostream>
using namespace std;

int main()
{
    int i, j, n, t, size[10], req[10], nr, min, f, w = 1, l;
    int ch, fp[10], fm[10], fn[10], intfrg, k[10];
    cout << "\nEnter the number of blocks of memory: ";
    cin >> n;
    cout << "\nEnter the size of memory:\n";
    for (i = 1; i <= n; i++)
    {
        cin >> size[i];
    }
    cout << "Enter the number of memory requests: ";
    cin >> nr;
    cout << "\nEnter the request size of memory:\n";
    for (i = 1; i <= nr; i++)
    {
        cin >> req[i];
    }
    if (nr <= n)
    {
        do
        {
            for (i = 1; i <= n; i++)
            {
                fm[i] = 0;
                fp[i] = 0;
            }

            for (i = 1; i <= nr; i++)
            {
                fn[i] = 0;
            }
            cout << "\n\n\n1.>first fit";
            cout << "\n2.>next fit";
            cout << "\n3.>best fit";
            cout << "\n4.>worst fit";
            cout << "\n5.>exit";
            cout << "\n\tEnter your choice: ";
            cin >> ch;
            switch (ch)
            {
                //first fit
                case 1:
                    cout << "\n\tALLOCATION BY FIRST FIT:";
                    for (j = 1; j <= nr; j++)
                    {
                        for (i = 1; i <= n; i++)
                        {
                            if (size[i] >= req[j] && fm[i] == 0 && fn[j] == 0)
                            {
                                fm[i] = 1;
                                fn[j] = 1;
                                intfrg = size[i] - req[j];
                                cout << "\n\t" << req[j] << " memory size is allocated to " << size[i] << " and internal fragmentation is " << intfrg << ".";
                            }
                        }
                        if (fn[j] == 0)
                        {
                            cout << "\n\t" << req[j] << " is not allocated.";
                        }
                    }
                    break;
                case 2:
                //next fit
                    cout << "\n\tALLOCATION BY NEXT FIT:";
                    t = 1;
                    for (j = 1; j <= nr; j++)
                    {
                        for (i = t; i <= n; i++)
                        {
                            if (size[i] >= req[j] && fm[i] == 0 && fn[j] == 0)
                            {
                                fm[i] = 1;
                                fn[j] = 1;
                                intfrg = size[i] - req[j];
                                cout << "\n\t" << req[j] << " memory size is allocated to " << size[i] << " and internal fragmentation is " << intfrg << ".";
                                t = i;
                                break;
                            }
                            if (i == n)
                            {
                                t = 1;
                            }
                        }
                        if (fn[j] == 0)
                        {
                            cout << "\n\t" << req[j] << " is not allocated.";
                        }
                    }
                    break;
                case 3:
                // best fit
                    cout << "ALLOCATION BY BEST FIT:";
                    for (j = 1; j <= nr; j++)
                    {
                        l = 1;
                        f = 0;
                        for (i = 1; i <= n; i++)
                        {
                            if (size[i] >= req[j] && fm[i] == 0 && fn[j] == 0)
                            {
                                k[i] = size[i] - req[j];
                                f = 1;
                            }
                            else
                                k[i] = 999;
                        }
                        if (f == 0)
                        {
                            cout << "\n\t" << req[j] << " is not allocated.";
                        }
                        else
                        {
                            min = k[1];
                            for (i = 1; i <= n; i++)
                            {
                                if (min > k[i])
                                {
                                    min = k[i];
                                    l = i;
                                }
                            }
                            cout << "\n\t" << req[j] << " is allocated by " << size[l] << " internal fragmentation is " << min;
                            fm[l] = 1;
                        }
                    }
                    break;
                case 4:
                //worst fit
                    cout << "ALLOCATION BY WORST FIT:";
                    for (j = 1; j <= nr; j++)
                    {
                        l = 1;
                        f = 0;
                        for (i = 1; i <= n; i++)
                        {
                            if (size[i] >= req[j] && fm[i] == 0)
                            {
                                fp[j] = size[i];
                                k[i] = size[i] - req[j];
                                fm[i] = 1;
                            }
                        }
                        if (f == 0)
                        {
                            cout << "\n\t" << req[j] << " is not allocated.";
                        }
                        else
                        {
                            min = size[1];
                            for (i = 1; i <= n; i++)
                            {
                                if (min < size[i] && fp[w] == 0)
                                {
                                    min = size[i];
                                    l = i;
                                    w = i;
                                }
                            }
                            cout << "\n\t" << req[j] << " is allocated by " << min << " internal fragmentation is " << k[l];
                        }
                    }
                    break;
                case 5:
                    exit(0);
                    break;
                default:
                    cout << "\nInvalid choice.";
            }
        } while (ch != 5);
    }
    else
        cout << "\nYou have requested more holes than available.";

    return 0;
}
