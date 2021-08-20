#include <bits/stdc++.h>

using namespace std;

int main()
{
    int frame;
    cout << "Enter number of frames: ";
    cin >> frame;

    int frames[frame + 1];
    int window;
    cout << "Enter window size: ";
    cin >> window;

    for (int i = 1; i <= frame; i++)
    {
        cout << "Enter frame " << i << ": ";
        cin >> frames[i];
    }

    cout << endl;
    for (int i = 1; i <= frame; i++)
    {
        if (i % window == 0)
        {
            cout << frames[i] << endl;
            cout << "Acknowledgement of above frames sent is recieved by sender" << endl;
        }
        else
            cout << frames[i] << " ";
    }
    if (frame % window != 0)
        cout << "\nAcknowledgement of above frames sent is recieved by sender" << endl;
    return 0;
}