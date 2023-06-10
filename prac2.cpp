
#include <iostream>

using namespace std;

struct process
{
    int bt, wt, tt, no, prio;
};

int main()
{
    process p[10], t;
    float avg_w, avg_t;
    int i, j, k, ch, n, qntm, c;
    

    do
    {
        cout << "\n---------- MENU ----------\n";
        cout << "\n\n1-FCFS";
        cout << "\n2-SJF";
        cout << "\n3-PRIORITY SCHEDULING";
        cout << "\n4-ROUND ROBIN";
        cout << "\n5-EXIT";
        cout << "\nEnter your choice:\t";
        cin >> ch;

        switch (ch)
        {   
            //FCFS
            case 1:
                cout << "\nEnter the number of processes:\t";
                cin >> n;

                for (i = 0; i < n; i++)
                {
                    cout << "Enter burst time for P" << i + 1 << ": ";
                    cin >> p[i].bt;
                    p[i].prio = 0;
                    p[i].no = i + 1;
                }

                p[0].wt = 0;
                for (i = 1; i < n; i++)
                    p[i].wt = p[i - 1].wt + p[i - 1].bt;

                for (i = 0; i < n; i++)
                    p[i].tt = p[i].wt + p[i].bt;

                //clrscr();();
                cout << "\nGantt Chart is:";
                cout << "\n0 ";
                for (i = 0; i < n; i++)
                    cout << "P" << p[i].no << " " << p[i].tt << " ";

                cout << "\n\nProcess BT WT TT";
                for (i = 0; i < n; i++)
                    cout << "\n" << p[i].no << " " << p[i].bt << " " << p[i].wt << " " << p[i].tt;

                avg_w = 0;
                avg_t = 0;
                for (i = 0; i < n; i++)
                {
                    avg_w = avg_w + p[i].wt;
                    avg_t = avg_t + p[i].tt;
                }

                avg_w = (float)avg_w / n;
                avg_t = (float)avg_t / n;

                cout << "\n\nAverage waiting time is: " << avg_w;
                cout << "\nAverage turn around time is: " << avg_t;
                break;

            //SJF
            case 2:
                cout << "\nEnter the number of processes:\t";
                cin >> n;

                for (i = 0; i < n; i++)
                {
                    cout << "Enter execution time for P" << i + 1 << ": ";
                    cin >> p[i].bt;
                    p[i].prio = 0;
                    p[i].no = i + 1;
                }

                for (i = 0; i < n; i++)
                {
                    for (j = i + 1; j < n; j++)
                    {
                        if (p[i].bt > p[j].bt)
                        {
                            t = p[i];
                            p[i] = p[j];
                            p[j] = t;
                        }
                    }
                }

                p[0].wt = 0;
                for (i = 1; i < n; i++)
                    p[i].wt = p[i - 1].wt + p[i - 1].bt;

                for (i = 0; i < n; i++)
                    p[i].tt = p[i].wt + p[i].bt;

                //clrscr();();
                cout << "\nGantt Chart is:";
                cout << "\n0 ";
                for (i = 0; i < n; i++)
                    cout << "P" << p[i].no << " " << p[i].tt << " ";

                for (i = 0; i < n; i++)
                {
                    for (j = i + 1; j < n; j++)
                    {
                        if (p[i].no > p[j].no)
                        {
                            t = p[i];
                            p[i] = p[j];
                            p[j] = t;
                        }
                    }
                }

                cout << "\n\nProcess BT WT TT";
                for (i = 0; i < n; i++)
                    cout << "\n" << p[i].no << " " << p[i].bt << " " << p[i].wt << " " << p[i].tt;

                avg_w = 0;
                avg_t = 0;
                for (i = 0; i < n; i++)
                {
                    avg_w = avg_w + p[i].wt;
                    avg_t = avg_t + p[i].tt;
                }

                avg_w = (float)avg_w / n;
                avg_t = (float)avg_t / n;

                cout << "\n\nAverage waiting time is: " << avg_w;
                cout << "\nAverage turn around time is: " << avg_t;
                break;

            //PRIORITY SCHEDULING
            case 3:
                cout << "\nEnter the number of processes:\t";
                cin >> n;

                for (i = 0; i < n; i++)
                {
                    cout << "Enter burst time for P" << i + 1 << ": ";
                    cin >> p[i].bt;
                    cout << "Enter priority for P" << i + 1 << ": ";
                    cin >> p[i].prio;
                    p[i].no = i + 1;
                }

                for (i = 0; i < n; i++)
                {
                    for (j = i + 1; j < n; j++)
                    {
                        if (p[i].prio > p[j].prio)
                        {
                            t = p[i];
                            p[i] = p[j];
                            p[j] = t;
                        }
                    }
                }

                p[0].wt = 0;
                for (i = 1; i < n; i++)
                    p[i].wt = p[i - 1].wt + p[i - 1].bt;

                for (i = 0; i < n; i++)
                    p[i].tt = p[i].wt + p[i].bt;

                //clrscr();();
                cout << "\nGantt Chart is:";
                cout << "\n0 ";
                for (i = 0; i < n; i++)
                    cout << "P" << p[i].no << " " << p[i].tt << " ";

                for (i = 0; i < n; i++)
                {
                    for (j = i + 1; j < n; j++)
                    {
                        if (p[i].no > p[j].no)
                        {
                            t = p[i];
                            p[i] = p[j];
                            p[j] = t;
                        }
                    }
                }

                cout << "\n\nProcess BT WT TT Priority";
                for (i = 0; i < n; i++)
                    cout << "\n" << p[i].no << " " << p[i].bt << " " << p[i].wt << " " << p[i].tt << " " << p[i].prio;

                avg_w = 0;
                avg_t = 0;
                for (i = 0; i < n; i++)
                {
                    avg_w = avg_w + p[i].wt;
                    avg_t = avg_t + p[i].tt;
                }

                avg_w = (float)avg_w / n;
                avg_t = (float)avg_t / n;

                cout << "\n\nAverage waiting time is: " << avg_w;
                cout << "\nAverage turn around time is: " << avg_t;
                break;

                //Round Robin
            case 4:
                cout << "\nEnter the number of processes:\t";
                cin >> n;
                cout << "\nEnter Time Quantum:\t";
                cin >> qntm;

                for (i = 0; i < n; i++)
                {
                    cout << "Enter burst time for P" << i + 1 << ": ";
                    cin >> p[i].bt;
                    p[i].prio = 0;
                    p[i].no = p[i].bt;
                    p[i].tt = 0;
                    p[i].wt = 0;
                }

               
                cout << "\nGantt Chart is:";
                c = 0;
                i = 0;
                j = 0;
                cout << "\n0";
                while (c < n)
                {
                    if (p[i].bt > 0)
                    {
                        if (p[i].bt < qntm)
                        {
                            p[i].wt = p[i].wt + (j - p[i].tt);
                            c++;
                            j += p[i].bt;
                            p[i].tt = j;
                            p[i].bt = 0;
                            cout << " P" << i + 1 << " " << p[i].tt;
                        }
                        else
                        {
                            p[i].bt -= qntm;
                            p[i].wt = p[i].wt + (j - p[i].tt);
                            j += qntm;
                            p[i].tt = j;
                            cout << " P" << i + 1 << " " << p[i].tt;
                            if (p[i].bt == 0)
                                c++;
                        }
                    }

                    if (i == n - 1)
                        i = 0;
                    else
                        i++;
                }

                for (i = 0; i < n; i++)
                {
                    p[i].bt = p[i].no;
                    p[i].no = i + 1;
                }

                cout << "\n\nProcess BT WT TT";
                for (i = 0; i < n; i++)
                    cout << "\n" << p[i].no << " " << p[i].bt << " " << p[i].wt << " " << p[i].tt;

                avg_w = 0;
                avg_t = 0;
                for (i = 0; i < n; i++)
                {
                    avg_w = avg_w + p[i].wt;
                    avg_t = avg_t + p[i].tt;
                }

                avg_w = (float)avg_w / n;
                avg_t = (float)avg_t / n;

                cout << "\n\nAverage waiting time is: " << avg_w;
                cout << "\nAverage turn around time is: " << avg_t;
                break;

            case 5:
                //clrscr();();
                cout << "\n\nProgram is Exiting...";
                break;

            default:
                //clrscr();();
                cout << "\n\nInvalid Choice. Please try again.";
        }

    } while (ch != 5);

    return 0;
}
