#include <bits/stdc++.h>
using namespace std;

// Question: https://codeforces.com/problemset/problem/1575/A

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n, m; //n - number of books, m - length of book(s)'s name
    cin >> n >> m;

    vector <pair<string, int>> books(n);
    string book;

    for (int i = 0; i < n; i++)
    {
        cin >> book;        
        books[i] = {book, i + 1};
    }

    sort(books.begin(), books.end());

    bool even = true;
    
    for (int j = 1; j < m; j++)
    {
        long long start = 0;
        long long end;

        for (int i = 0; i < n - 1; i++)
        {
           if (books[i].first.substr(0,j) != books[i + 1].first.substr(0,j))
           {
              end = n - i - 1;
              if (even)
              {
                 sort(books.rbegin() + end, books.rend() - start);
              }
              else
              {
                 sort(books.begin() + start, books.end() - end);
              }
              start = i + 1;
           }
        }

         if (even)
         {
            sort(books.rbegin(), books.rend() - start);
         }
         else
         {
            sort(books.begin() + start, books.end());
         }
         even = !even;
    }

    for (auto i : books)
    {
        cout << i.second << " ";
    }
}