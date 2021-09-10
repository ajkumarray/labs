//  iterativeMethod
//  Created by Ajit Kumar on May24//2021 AD.
//  Copyright © 2021 Ajit Kumar. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

#define e 0.00001

float fun(float x)
{
    float fx = (float)(x*x*x +1) / 5;
    return fx;
}

int initialGuess()
{
    for(int i = 0; i >= 0; i++)
        if(fun(i)*fun(-i) < 0)
            return i;
    return 0;
}

int main(int argc, const char * argv[]) {
    float x = initialGuess();
    int i = 1;
    while(fabs(fun(x)) > e && i <= 50)
    {
        x = fun(x);
        cout << "Iteration" << i << ": " << "x = " << x << "\t\tfx = " << fun(x) << endl;
        i++;
        if(fabs(x - fun(x)) < e)
            break;
    }
    return 0;
}
