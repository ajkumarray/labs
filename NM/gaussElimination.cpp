//  gaussElimination

#include <bits/stdc++.h>
#define n 3

using namespace std;

//int n;

int forwardElimination(double ray[n][n+1]);

void backSub(double ray[n][n+1]);


void backSub(double ray[n][n+1])
{
    double x[n];
    
    for(int i = n - 1; i >= 0; i--)
    {
        x[i] = ray[i][n];
        
        for(int j = i + 1; j < n; j++)
            x[i] -= ray[i][j] * x[j];
        
        x[i] = x[i] / ray[i][i];
    }
    cout << "Solution for the system: " << endl;
    for(int i = 0; i < n; i++)
        cout << x[i] << endl;
}

void swapRow(double ray[n][n+1], int i, int j)
{
    for(int k = 0; k <= n; k++)
    {
        double temp = ray[i][k];
        ray[i][k] = ray[j][k];
        ray[j][k] = temp;
    }
}

int forwardElimination(double ray[n][n+1])
{
    for(int k = 0; k < n; k++)
    {
        int iMax = k;
        int vMax = ray[iMax][k];
        
        for(int i = k + 1; i < n; i++)
            if(abs(ray[i][k]) > vMax)
            {
                vMax = ray[i][k];
                iMax = i;
            }
        
        if(!ray[k][iMax])
            return k;
        
        if(iMax != k)
            swapRow(ray, k, iMax);
        
        for(int i = k + 1; i < n; i++)
        {
            double f = ray[i][k] / ray[k][k];
            
            for(int j = k + 1; j <= n; j++)
                ray[i][j] -= ray[k][j] * f;
            
            ray[i][k] = 0;
        }
    }
    return -1;
}

void gaussElimination(double ray[n][n + 1])
{
    int singularFlag = forwardElimination(ray);
    if(singularFlag != -1)
    {
        cout << "Singular Matrix" << endl;
        if(ray[singularFlag][n])
            cout << "Inconsistent System" << endl;
        else
            cout << "May have infinitely many solutions" << endl;
        
        return;
    }
    backSub(ray);
}


int main(int argc, const char * argv[]) {
    //cout << "Enter number of unknowns: ";
    //cin >> n;
    double ray[n][n + 1];
    cout << "Enter augmented matrix:" << endl;
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= n; j++)
            cin >> ray[i][j];
    gaussElimination(ray);
    return 0;
}
