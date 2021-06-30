#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
    string s;
    cin >> s;

    long long n = s.length();

    if (n == 1)
    {
        cout << "1\n";
        return 0;
    }
    if (n == 2)
    {
        if (s[0] == s[1])
        {
            cout << "1\n";
            return 0;
        }
        else
        {
            cout << "2\n";
            return 0;
        }
    }

    vector<string> v;
    long long i = 0;
    if (s[0] != s[1])
    {
        string t1(1, s[0]);
        string t2(1, s[1]);
        v.pb(t1);
        v.pb(t2);
        i = 2;
    }
    else
    {
        string t1(1, s[0]);
        string t2;
        t2 += s[1];
        t2 += s[2];
        v.pb(t1);
        v.pb(t2);
        i = 3;
    }

    for (; i < n; i++)
    {
        string old = v.back();
        if (old.length() == 2)
        {
            string t1(1, s[i]);
            v.pb(t1);
        }
        else
        {
            string curr;
            curr += s[i];

            int a1 = old.compare(curr);
            if (a1 != 0)
            {
                v.pb(curr);
            }
            else
            {
                // Both are Equal
                if (i + 1 < n)
                {
                    curr += s[i + 1];
                    v.pb(curr);
                    i++;
                }
                else
                {
                    // No Need to do anything
                }
            }
        }
    }

    cout << v.size() << endl;
}
