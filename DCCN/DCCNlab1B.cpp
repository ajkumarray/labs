#include <bits/stdc++.h>

using namespace std;

string xorString(string str, string div)
{
  int i = 0, j = 0, count = 0;
  string res = "", ans = "";
  while (i < str.size())
  {
    j = 0;
    while (j < div.size())
    {
      if (str[i] == div[j])
        str[i] = '0';
      else
        str[i] = '1';
      i++;
      j++;
    }
    int k = 0;
    while (k < i)
    {
      if (str[k] == '1')
        break;
      k++;
    }
    i = k;
  }
  return str;
}

string remainder(string send, string str)
{
  int i = send.size() - 1, j;
  bool flag = true;
  while (flag)
  {
    j = str.size() - 1;
    while (j >= 0)
    {
      if (send[i] == str[j])
        send[i] = '0';
      else
        send[i] = '1';
      i--;
      j--;
    }
    flag = false;
  }
  return send;
}

string sender(string str, string div, string original)
{
  cout << "\n\t Transmission\n";
  cout << "Original Message: " << original << endl;
  string send = str;
  string res = xorString(str, div);
  send = remainder(send, res);
  cout << "Message after transmission CRC: " << send << endl;
  //int zero = str.size() - div.size() + 1;
  //send = original + res.substr(zero, div.size() - 1);
  return send;
}
void reciever(string str, string div, string original)
{
  string rec = sender(str, div, original);
  cout << "\n\t Reciever\n";
  cout << "Message recieved is: " << rec << endl;
  string res = xorString(rec, div);
  cout << "Message after reciever CRC: " << res << endl;
  set<char> s(res.begin(), res.end());
  if (s.size() == 1 && res[0] == '0')
    cout << "\tMessage successfully recieved\n"
         << endl;
  else
    cout << "\tData mismatched\n\tError!" << endl;
}
int main()
{
  cout << "\n\nEnter original message: ";
  string str, div;
  cin >> str;
  string original = str;
  cout << "Enter divisor string: ";
  cin >> div;
  int zero = div.size() - 1;
  while (zero--)
    str += '0';
  reciever(str, div, original);
}