// #include<stdio.h> 
// #include<conio.h> 
// void main() 
// { 
// int a[10][10],m[10][10],ne[10][10],av[10],pri[10],flag,j,k,n,i,c[10],count=0,fla,f,fl[10]; 
// // clrscr(); 
// for(i=1;i<=10;i++) 
// c[i]=0; 
// printf("\nENTER THE NO OF PROCESSES :\t"); 
// scanf("%d",&n); 
// for(i=1;i<=n;i++) 
// { 
// printf("\nENTER THE MAX NEED FOR PROCESS P%d :\t",i); 
// for(j=1;j<=3;j++) 
// { 
// scanf("%d",&m[i][j]); 
// } 
// } 
// for(i=1;i<=n;i++) 
// { 
// printf("\nENTER THE RESOURSES ALLOCATED TO PROCESS P%d :\t",i); 
// for(j=1;j<=3;j++) 
// { 
// scanf("%d",&a[i][j]); 
// } 
// } 
// for(i=1;i<=n;i++) 
// { 
// for(j=1;j<=3;j++) 
// { 
// ne[i][j]=m[i][j]-a[i][j]; 
// } 
// } 
// printf("\nENTER THE NO OF AVAILABLE RESOURSES :\t"); 
// for(i=1;i<=3;i++) 
// { 
// scanf("%d",&av[i]); 
// } 
// printf("\n\t\tTABLE\n"); 
// printf("\nPROCESSES\t\tMAX NEED\t\tALLOCATED\t\tNEED\n"); 
// printf("\n\t\t\tA B C \t\tA B C\t\t\tA B C\n"); 
// for(i=1;i<=n;i++) 
// { 
// printf("\nP%d",i); 
// printf("\t\t\t%d %d %d \t\t%d",m[i][1],m[i][2],m[i][3],a[i][1],a[i][2]); 
// printf(" %d %d\t\t\t%d %d %d",a[i][2],a[i][3],ne[i][1],ne[i][2],ne[i][3]); 
// } 
// printf("\nAVAILABLE RESOURSES\nA\tB\tC\n"); 
// for(i=1;i<=3;i++) 
// { 
// printf("%d\t",av[i]); 
// } 
// label: 
// for(i=1;i<=n;i++) 
// { 
// for(j=1;j<=3;j++) 
// { 
// if((av[j]>=ne[i][j])&&c[i]==0) 
// flag=1; 
// else 
// { 
// flag=0; 
// break; 
// } 
// } 
// if(flag==1) 
// { 
// for(k=1;k<=3;k++) 
// { 
// av[k]=av[k]+a[i][k]; 
// } 
// c[i]=1; 
// count++; 
// pri[count]=i; 
// } 
// } 
// for(i=1;i<=n;i++) 
// { 
// for(j=1;j<=3;j++) 
// { 
// if((av[j]>=ne[i][j])&&c[i]==0) 
// fla=1; 
// else 
// { 
// fla=0; 
// break; 
// } 
// } 
// if(fla==1) 
// fl[i]=1; 
// } 
// for(i=1;i<=n;i++) 
// { 
// if(fl[i]==0) 
// f=0; 
// else 
// { 
// f=1; 
// break; 
// } 
// } 
// if(f==1) 
// goto labe; 
// else 
// { 
// printf("\nTHE DEADLOCK IS PRESENT IN SYSTEM"); 
// goto lab; 
// } 
// labe: 
// for(i=1;i<=n;i++) 
// { 
// if(c[i]==1) 
// flag=1; 
// else 
// { 
// flag=0; 
// break; 
// } 
// } 
// if(flag==0) 
// goto label; 
// printf("\nTHE SYSTEM IS IN SAFE MODE \n THE SEQUENCE IS:"); 
// for(i=1;i<=n;i++) 
// printf("\t ==> P%d",pri[i]); 
// lab: 
// getch(); 
// }



#include<iostream>
using namespace std;

int main()
{
    int a[10][10], m[10][10], ne[10][10], av[10], pri[10], flag, j, k, n, i, c[10], count = 0, fla, f, fl[10];
    // clrscr();
    for (i = 1; i <= 10; i++)
        c[i] = 0;
    cout << "\nENTER THE NO OF PROCESSES :\t";
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cout << "\nENTER THE MAX NEED FOR PROCESS P" << i << " :\t";
        for (j = 1; j <= 3; j++)
        {
            cin >> m[i][j];
        }
    }
    for (i = 1; i <= n; i++)
    {
        cout << "\nENTER THE RESOURCES ALLOCATED TO PROCESS P" << i << " :\t";
        for (j = 1; j <= 3; j++)
        {
            cin >> a[i][j];
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= 3; j++)
        {
            ne[i][j] = m[i][j] - a[i][j];
        }
    }
    cout << "\nENTER THE NO OF AVAILABLE RESOURCES :\t";
    for (i = 1; i <= 3; i++)
    {
        cin >> av[i];
    }
    cout << "\n\t\tTABLE\n";
    cout << "\nPROCESSES\t\tMAX NEED\t\tALLOCATED\t\tNEED\n";
    cout << "\n\t\t\tA B C \t\tA B C\t\t\tA B C\n";
    for (i = 1; i <= n; i++)
    {
        cout << "\nP" << i;
        cout << "\t\t\t" << m[i][1] << " " << m[i][2] << " " << m[i][3] << " \t\t" << a[i][1] << " " << a[i][2];
        cout << " " << a[i][3] << "\t\t\t" << ne[i][1] << " " << ne[i][2] << " " << ne[i][3];
    }
    cout << "\nAVAILABLE RESOURCES\nA\tB\tC\n";
    for (i = 1; i <= 3; i++)
    {
        cout << av[i] << "\t";
    }

label:
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= 3; j++)
        {
            if ((av[j] >= ne[i][j]) && c[i] == 0)
                flag = 1;
            else
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            for (k = 1; k <= 3; k++)
            {
                av[k] = av[k] + a[i][k];
            }
            c[i] = 1;
            count++;
            pri[count] = i;
        }
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= 3; j++)
        {
            if ((av[j] >= ne[i][j]) && c[i] == 0)
                fla = 1;
            else
            {
                fla = 0;
                break;
            }
        }
        if (fla == 1)
            fl[i] = 1;
    }

    for (i = 1; i <= n; i++)
    {
        if (fl[i] == 0)
            f = 0;
        else
        {
            f = 1;
            break;
        }
    }

    if (f == 1)
        goto labe;
    else
    {
        cout << "\nTHE DEADLOCK IS PRESENT IN SYSTEM";
        goto lab;
    }

labe:
    for (i = 1; i <= n; i++)
    {
        if (c[i] == 1)
            flag = 1;
        else
        {
            flag = 0;
            break;
        }
    }

    if (flag == 0)
        goto label;

    cout << "\nTHE SYSTEM IS IN SAFE MODE \n THE SEQUENCE IS:";
    for (i = 1; i <= n; i++)
        cout << "\t ==> P" << pri[i];

lab:
    return 0;
}
