//  regulaFalsiMethod
//  Created by Ajit Kumar on May24//2021 AD.
//  Copyright © 2021 Ajit Kumar. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

#define e 0.0000001
double fun(double x)
{
    double fx = x*x*x - 5*x + 1;
    return fx;
}

bool check(double x1, double x2)
{
    if(fun(x1)*fun(x2) < 0)
        return true;
    
    return false;
}

int initialGuess()
{
    for(int i = 0; i >= 0; i++)
        if(check(i,(-i)))
            return i;
    return 0;
}

int main(int argc, const char * argv[]) {
    
    double x1 = initialGuess();
    double x2 = -x1;
    double x3 = x2 - (float)((fun(x2) * (x2 - x1)) / (fun(x2) - fun(x1)));
    int i = 1;
    cout << "Initial Guess: x1 = " << x1 << ", x2 = " << x2 << endl;
    
    cout << "Iteration \t x1 \t\t\t x2 \t\t\t x3 \t\t\t fun(x1) \t\t fun(x2) \t\t  fun(x3)\n" << endl;
    cout << fixed << setprecision(6) << i << "\t\t\t" << x1 << "\t\t" << x2 << "\t\t" << x3 << "\t\t" << fun(x1) << "\t\t" << fun(x2) << "\t\t" << fun(x3) << endl;
    i++;
    while(fabs(fun(x3)) > e)
    {
        if(check(x1, x3))
            x2 = x3;
        else
            x1 = x3;
        
        x3 = (float)((x1 * fun(x2) - x2 * fun(x1)) / (fun(x2) - fun(x1)));
        cout << fixed << setprecision(6) << i << "\t\t\t" << x1 << "\t\t" << x2 << "\t\t" << x3 << "\t\t" << fun(x1) << "\t\t" << fun(x2) << "\t\t" << fun(x3) << endl;
        i++;
        if(fabs(x1 - x2) < e)
            break;
    }
    cout << "\nApproximate root = " << x3 << endl;
    return 0;
}
