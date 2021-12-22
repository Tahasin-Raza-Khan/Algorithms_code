#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll modular_mul(ll a, ll b, ll num)
{
    ll res = 0;
    while (b)
    {
        if (1ll & b)
            res = (res + a) % num;
        a = (a * 2) % num;
        b >>= 1;
    }
    return res;
}
ll compute_power(ll a, ll b, ll num)
{
    ll res = 1;
    while (b)
    {
        if (1ll & b)
        {
            res = modular_mul(res, a, num);
            res %= num;
        }
        a = modular_mul(a, a, num);
        a %= num;
        b >>= 1;
    }
    return res;
}

bool compute_miller_rabin(ll num)
{
    if (num == 1)
        return false;
    if (num == 2)
        return true;
    if (num % 2 == 0)
        return false;
    ll d = num - 1, s = 0;
    while (d % 2 == 0)
    {
        s++;
        d /= 2;
    }
    long long a[9] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    for (int i = 0; i < 9; ++i)
    {
        if (a[i] > num - 2)
            continue;
        ll adn = compute_power(a[i], d, num);
        if (adn % num == 1)
            continue;

        bool prime = false;
        for (ll i = 0; i <= s - 1; ++i)
        {
            ll ss = compute_power(2, i, num);
            ll ads = compute_power(adn, ss, num);
            if (ads % num == num - 1)
            {
                prime = true;
                break;
            }
        }
        if (prime == false)
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;
    while (t--)
    {

        ll num;
        cin >> num;
        if (compute_miller_rabin(num))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}