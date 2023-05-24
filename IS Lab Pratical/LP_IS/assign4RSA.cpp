#include <bits/stdc++.h>

using namespace std;



long long gcd(long long a, long long b)
{
    long long temp;
    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
long long checkprime(long long n)
{
    if (n <= 1)
    {
        return false;
    }

    for (long long i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

long long public_key(long long p, long long q)
{
    long long fie = (p - 1) * (q - 1);

    for (long long i = 2; i < fie; i++)
    {
        long long e = i;

        if (e < fie && gcd(e, fie) == 1 && e != p && e != q)
        {
            return e;
        }
    }
}

long long private_key(long long e, long long p, long long q)
{
    long long d;
    long long fie = (p - 1) * (q - 1);

    for (long long i = 1; i < INT_MAX; i++)
    {

        d = i;
        long long temp = (e * d) % fie;
        if (temp == 1 && d < fie)
        {
            return d;
        }
    }
}

long long encryption(long long e, long long n, long long m)
{
 return (long long)pow(m,e)%n;
}

long long decryption(long long d, long long n, long long c)
{
    return (long long)pow(c,d)%n;
}

int main()
{

    long long p, q, n, e, m;

    long long pk;

    cout << "Enter values of p and q:" << endl;
    cin >> p >> q;

    cout << "Enter message:" << endl;
    cin >> m;

    if (checkprime(p) == 0 && checkprime(q) == 0)
    {
        cout << "Enter the prime numbers" << endl;
    }

    else
    {
        n = p * q;
        e = public_key(p, q);

        cout << "public key is :" << public_key(p, q) << "," << n << endl
             << endl;
        cout << "e:" << e << endl;
        cout << "Private key is :" << private_key(e, p, q) << "," << n << endl
             << endl;

        long long d = private_key(e, p, q);

        cout << "d :" << d << endl;

        cout << "Encrpyted msg is:" << encryption(e, n, m) << endl
             << endl;

        long long c = encryption(e, n, m);

        cout << "plaintext  msg is:" << decryption(d, n, c) << endl;
    }
    return 0;
}
