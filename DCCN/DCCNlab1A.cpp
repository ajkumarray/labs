//  checksum program
#include <bits/stdc++.h>

using namespace std;

int sender(int ray[10], int num)
{
    cout << "\n\t---Sender---" << endl;
    int sum = 0;
    for (int i = 0; i < num; i++)
        sum += ray[i];

    cout << "Sum is: " << sum << endl;

    int checksum;
    checksum = ~sum; //  binary comliment of sum is checksum
    cout << "Checksum is: " << checksum << endl;
    return checksum;
}

int receiver(int ray[10], int num, int sCheck)
{
    cout << "\n\t---Reciever---" << endl;
    int sum = 0;
    for (int i = 0; i < num; i++)
        sum += ray[i];

    cout << "Sum is: " << sum << endl;

    int checksum;
    sum = sum + sCheck;
    checksum = ~sum;
    cout << "Checksum is: " << checksum << endl;
    return checksum;
}

int main()
{
    int num;
    cout << "\nEnter number of frames: ";
    cin >> num;

    int ray[10];
    cout << "Enter the frames\n"
         << endl;
    for (int i = 0; i < num; i++)
    {
        cout << "Frame " << (i + 1) << " :";
        cin >> ray[i];
    }

    int sCheck = sender(ray, num);
    int rCheck = receiver(ray, num, sCheck);

    if (rCheck == 0)
        cout << "\n\nNo error detectd\n"
             << endl;
    else
        cout << "\n\nError detected\n"
             << endl;
    return 0;
}