#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int gcd(int a,int b)
{
    int c=a%b;
    while(c){
        a=b;
        b=c;
        c=a%b;
    }
    return b;
}

int main()
{

	int p = 3;
	int q = 7;
	// First part of public key:
	int n = p*q;
	// Finding other part of public key.
	// e stands for encrypt
	int e = 2;
	int phi = (p-1)*(q-1);
	while (e < phi)
	{
		// e must be co-prime to phi and
		// smaller than phi.
		if (gcd(e, phi)==1)
			break;
		else
			e++;
	}

	// Private key (d stands for decrypt)
	// choosing d such that it satisfies
	// d*e = 1 + k * totient
	int k = 2; // A constant value
	double d = (1 + (k*phi))/e;
	// Message to be encrypted
	double msg = 15;

	cout<<"Message data = "<< msg;

	// Encryption c = (msg ^ e) % n
	double c = pow(msg, e);
	c = fmod(c, n);
	cout<<"\nEncrypted data = "<< c;

	// Decryption m = (c ^ d) % n
	double m = pow(c, d);
	m = fmod(m, n);
	cout<<"\nOriginal Message Sent = "<< m;

	return 0;
}
