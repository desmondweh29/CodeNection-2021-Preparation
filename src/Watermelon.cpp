#include <iostream>
using namespace std;

// Question: https://codeforces.com/problemset/problem/4/A

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int w;
    cin >> w; 
    if (w >= 1 && w <= 100)
    {
        if(w%2)
            cout << "NO\n";
        else
        {
            for (int i = 2; i < w; i++)
            {
                int a = w / i;
                if (a%2 == 0) 
                {
                    cout << "YES\n";
                    return 0;
                }
            }
            cout << "NO\n";
        }   
    }
}