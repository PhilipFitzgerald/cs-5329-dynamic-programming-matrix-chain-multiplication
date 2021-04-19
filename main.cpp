#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <stack>
using namespace std;

void printTable(stack<int>table, int size, int message)
{
  cout<<endl;
  if (message == 0 )
  {
cout<<"M Table: "<< endl<<"Table indexes are printed in reverse. Left side is 6-1 starting from the bottom and the right side is 1-6 starting from the bottom"<<endl;
  }
  else{
    cout<<"S Table: "<< endl<<"Table indexes are printed in reverse. Left side is 5-1 starting from the bottom and the right side is 2-6 starting from the bottom"<<endl;
  }
  
    for(int i = 1, k = 0; i <= (size-1); i++, k = 0)
    {
        for(int j = 1; j <= (size-1)-i; j++)
        {
            cout <<"  ";
        }

        while(k != i && !table.empty())
        {
          if(table.top()==0)
          {
            cout<<table.top()<<"     ";
          }
          else{
            cout<<table.top()<<"  ";
          }
            table.pop();
            ++k;
        }
        cout << endl;
    }  
  
}

int MatrixChainOrder(int p[], int n)
{
 stack<int> mtable;
 stack<int>stable;
 int actual=0;//used to track what k value is to put in stable

    int m[n][n];
 
    int j , q;
    int tracker =n-1; // counter 

    while(tracker!=0)
    {
      mtable.push(0);
      tracker--;
    }
 
    for (int i = 1; i < n; i++)
        m[i][i] = 0;
 
    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                q = m[i][k] + m[k + 1][j]
                    + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    actual = k;
                }
            }
            mtable.push(m[i][j]);
            stable.push(actual);
        }
    }
    printTable(mtable,n,0);
    printTable(stable,n,1);
    return m[1][n - 1];
}

int main()
{
     int sizeOne = 7;
     int sizeTwo = 4;
    int arrOne[] = { 30, 35, 15, 5,10, 20, 25 };
    int arrTwo[]= {10,5,20,30};
    int arrThree[] ={20,10,20,30};
    int arrFour[] = {25,20,30,10};
    int arrFive[] = {16,10,20,25};
    int multi[]={40500,7000,16000,22500,11200};
    const int CAPSIZE = 5;
    int * arrCap[CAPSIZE]={arrOne,arrTwo,arrThree,arrFour,arrFive};
    int counter = 0;
    int min=0;
    for (int i =0; i<CAPSIZE; i++)
    {
      if(counter==0)
      {
        cout<<"Dimensions: " <<endl;
        for (int i =0; i<sizeOne-1;i++)
        {
          cout<<arrOne[i]<<" x "<< arrOne[i+1]<< ", ";
        }
        cout<<endl;
        
       min = MatrixChainOrder(arrCap[i], sizeOne);
         counter++;
         cout << endl<<"Minimum number of multiplications when using dynamic programming: "
         <<min<<endl;
         cout << endl<<"Minimum number of multiplications when not using dynamic programming: "
         <<multi[i]<<endl;
         cout<<"*************************************************************"<<endl;

      }
      else{
         cout<<"Dimensions: " <<endl;
  
          for (int j =0; j<sizeTwo-1; j++)
          {
          cout<<arrCap[i][j]<<" x "<< arrCap[i][j+1]<< ", ";

          }
          cout<<endl;

        min = MatrixChainOrder(arrCap[i], sizeTwo);
         counter++;
         cout << endl<<"Minimum number of multiplications when using dynamic programming: "
         <<min<<endl;
         cout << endl<<"Minimum number of multiplications when not using dynamic programming: "
         <<multi[i]<<endl;
         cout<<"*************************************************************"<<endl;


      }
      cout<<endl;
    }

    getchar();
    return 0;
}