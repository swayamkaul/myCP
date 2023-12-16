#include<bits/stdc++.h>
 using namespace std;
 typedef long long ll;
// Power function to return value of a ^ b mod P
ll power(ll a, ll b, ll P)
{
    if (b == 1)

        return a;
 
    else
        return (((ll)pow(a, b)) % P);
}
int main()
{
    ll P, G, x, a, y, b, ka, kb; 
    // Both the persons will be agreed upon the
        // public keys G and P
    P = 23; // A prime number P is taken
   cout<<"The value of P : "<<P<<"\n";
 
    G = 9; // A primitive root for P, G is taken
     cout<<"The value of G : "<< G<<"\n";
 
    // PersonA will choose the private key a
    a = 4; // a is the chosen private key
    cout<<"The private key a for PersonA : "<<a<<"\n";
    x = power(G, a, P); // gets the generated key
     
    // PersonB will choose the private key b
    b = 3; // b is the chosen private key
     cout<<"The private key b for PersonB : "<<b<<"\n";
    y = power(G, b, P); // gets the generated key
 
    // Generating the secret key after the exchange
        // of keys
    ka = power(y, a, P); // Secret key for PersonA
    kb = power(x, b, P); // Secret key for PersonB
     
    cout<<"Secret key for the PersonA is : "<< ka<<"\n";
    cout<<"Secret Key for the PersonB is : "<< kb;
     
    return 0;
}