#include <bits/stdc++.h>
using namespace std;

// Question: https://codeforces.com/problemset/problem/1614/B

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);    
 
    int t; //number of test cases
    cin >> t; 
    
    while (t--)
    {
        int n; //number of buildings
        cin >> n;

        vector<pair<int, int>> a(n);

        int times;

        for (int i = 0; i < n; i++)
        {
            cin >> times;
            a[i] = {times, i + 1};
        }

        sort(a.rbegin(), a.rend());

        vector<int> x(n + 1);
        x[0] = 0;

        long long nextDist = 1;
        bool pos = true;

        long long totalDist = 0;

        for (unsigned int i = 0; i < n; i++)
        {
            if(pos)
            {
                x[a[i].second] = nextDist;
                totalDist += nextDist * abs(2 * a[i].first);
            }
            else
            {
                x[a[i].second] = nextDist * -1;
                totalDist += nextDist * abs(2 * a[i].first);
                nextDist++;
            }
            pos = !pos;
        }

        cout << totalDist << "\n";
        for (auto i : x) 
        {
            cout << i << " ";
        }
        cout << "\n";
    
    }
    return 0; 
}
