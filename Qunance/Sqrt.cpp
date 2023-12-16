#include <bits/stdc++.h>
using namespace std;
 



double Find_Square_binsearch(double n, double i, double j) // n is number
{
    double middle = (i + j) / 2;        //O(log 10^5)
    double sq = middle * middle;
    if ((sq == n) || (abs(sq - n) < 0.00001)) // answer correct upto 5 decimal places. 
        return middle;
        
    if(sq < n)  return Find_Square_binsearch(n, middle, j);
    else  return Find_Square_binsearch(n, i, middle);
}

void SSqrt(double n)       // finding the integer numbers whose square is closest to the given number
{
    double i = 1;
    bool flag = false;
    while (!flag) {
        if (i * i == n) {   // if it is a perfect square return the number;
            cout << fixed << setprecision(0) << i;
            flag = true;
        }
        else if (i * i > n) { // if the integer numbers are found between which the sqrt lie ... go on to decimals and apply binary search
            double res = Find_Square_binsearch(n, i - 1, i);
            cout << setprecision(5) << res;
            flag = true;
        }
        i++;        // O ((Sqrt(Number))
    }
}



int main()
{
    double number = 0;
 
    cout<<"Enter Number:\n";
    cin>>number;
    SSqrt(number);
 
    return 0;
}

//time complexity O(sqrt(N) * Log(10^5))