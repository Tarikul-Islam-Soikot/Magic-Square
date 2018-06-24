#include<stdio.h>
#include<iostream>
using namespace std;
class MagicSquare
{
public:
    void DoubleEven(int n);
    void SingleEven(int n);
    void ForOddNumber(int n);
    void function_(int i,int j,int number, int a[][100],int n, int m)
    {
        int row, column;
        row=i;
        column=(j+m)/2;
        a[row][column]=number;

        while(number<=n)
        {
            number++;
            if((row==i)&& column==j)
            {
                row=row+1;
                a[row][column]=number;
            }
            else if(row-1<i)
            {
                row=m;
                column=column-1;
                a[row][column]=number;
            }
            else if(column-1<j)
            {
                row=row-1;
                column=m;
                a[row][column]=number;
            }
            else if(a[row-1][column-1]>0)
            {
                row=row+1;
                a[row][column]=number;
            }
            else
            {
                row=row-1;
                column=column-1;
                a[row][column]=number;
            }
        }
    }
    void function_2(int i,int j,int number, int a[][100],int n, int m, int m1)
    {
        int row, column;
        row=i;
        column=(j+m)/2;
        a[row][column]=number;
        for(; number<n;)
        {
            number++;
            if((row==i)&& column==j)
            {
                row=row+1;
                a[row][column]=number;

            }
            else if(row-1<i)
            {
                row=m1;
                column=column-1;
                a[row][column]=number;

            }
            else if(column-1<j)
            {
                row=row-1;
                column=m;
                a[row][column]=number;
            }
            else if(a[row-1][column-1]>0)
            {
                row=row+1;
                a[row][column]=number;
            }
            else
            {
                row=row-1;
                column=column-1;
                a[row][column]=number;
            }
        }
    }

};
void MagicSquare::SingleEven(int n)
{

    int m, n1, n2, i, j, m1,temp,number;

    int a[100][100]= {0};
    m=(n-1)/2;
    n1=n*n;
    n2=n1/4;
    number=1;
    function_(0, 0,number, a, n2, m);

    number=n2+1;
    n2=n1/2;
    m=n-1;
    function_(n/2, n/2, number,a, n2, m);

    number=n2+1;
    n2=(n1/4)*3;
    m1=(n-1)/2;
    function_2(0, n/2, number,a, n2, m, m1);

    number=n2+1;
    n2=n1;
    m=(n-1)/2;
    m1=n-1;
    function_2((n/2), 0, number, a,n2, m, m1);
    m=(n-1)/2;
    n1=n/4;
    for(j=0; j<n1; j++)
    {
        for(i=0; i<=m; i++)
        {
            if(i==(m/2))
            {
                temp=a[i][j+1];
                a[i][j+1]=a[(n/2)+i][j+1];
                a[(n/2)+i][j+1]=temp;
            }
            else
            {
                temp=a[i][j];
                a[i][j]=a[(n/2)+i][j];
                a[(n/2)+i][j]=temp;
            }
        }
    }
    for(j=(n-n1+1); j<n; j++)
    {
        for(i=0; i<=m; i++)
        {
            temp=a[i][j];
            a[i][j]=a[(n/2)+i][j];
            a[(n/2)+i][j]=temp;

        }
    }

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
        printf("%5d", a[i][j]);
        }
        printf("\n\n\n");
    }

}
void MagicSquare::ForOddNumber(int n)
{

    int i, j, k, l, m, number;

    int  a[100][100]= {0};

    number=1;
    m=n/2;
    a[0][m]=number;
    i=0;
    j=m;
    while(number<=n*n)
    {
        number++;
        if((i==0) && (j==0))
        {
            i=i+1;
            a[i][j]=number;
        }
        else if((i-1)<0)
        {
            i=n-1;
            j=j-1;
            a[i][j]=number;

        }

        else if((j-1)<0)
        {
            i=i-1;
            j=n-1;
            a[i][j]=number;

        }
        else if(a[i-1][j-1]>0)
        {
            i=i+1;
            a[i][j]=number;


        }

        else
        {
            i=i-1;
            j=j-1;
            a[i][j]=number;
        }
    }
    printf("\n\n");


    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%5d", a[i][j]);
        }
        printf("\n\n\n");
    }

}
void MagicSquare::DoubleEven(int n)
{

    int i, j,  number, k=0, m, b[100];


    int a[100][100]= {0};
    m=n/4;

    number=k=0;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {

            if((i<m) && (j<m))
            {

                number++;
                a[i][j]=number;
            }
            else if((i<m) && (j>=(n-m)))
            {

                number++;
                a[i][j]=number;
            }
            else if(((i>=m) && (i<(n-m))) && ((j>=m)&& (j<(n-m))))
            {

                number++;
                a[i][j]=number;
            }
            else if((i>=(n-m)) && (j<m))
            {

                number++;
                a[i][j]=number;
            }
            else if((i>=(n-m)) && (j>=(n-m)))
            {

                number++;
                a[i][j]=number;
            }
            else
            {
                number++;
                b[k]=number;
                k++;


            }
        }
    }

    k=0;
    for(i=n-1; i>=0; i--)
    {
        for(j=n-1; j>=0; j--)
        {
            if(a[i][j]==0)
            {
                a[i][j]=b[k];
                k++;
            }
            printf("%5d", a[i][j]);
        }
        printf("\n\n\n");
    }

}
int main()
{

    MagicSquare x;
    int n;
    cout<<"Enter the number for which you want to see magic Square: ";
    while(cin>>n)
    {
        if(n==2)
        {
            cout<<"\n\nMagic Square for input 2 is not possible...\n\n"<<endl;
        }
        else if(n%2!=0)
        {
            x.ForOddNumber(n);
        }
        else if((n%2==0) && (n%4==0))
            x.DoubleEven(n);
        else
            x.SingleEven(n);


    }
    return 0;
}
