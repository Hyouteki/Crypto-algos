#include<iostream>
#include<vector>
#include<cstdint>
#include"64_bit_prime_number.h"
using namespace std;

/*
- choose two prime numbers say (p & q)
- N (mod number) = p*q
- phi(N) = number of numbers coprime with N
	i.e. phi(N) = (p-1)*(q-1)
- choose e (encryption key) should satisfy two conditions
	- 1 < e < phi(N)
	- coprime with N, and phi(N) 
- choose d (decryption key) should satisfy this relation
	d*e(mod phi(N)) = 1

- encryption key = (e, N)
- decryption key = (d, N)
- cypher text = message^e(mod N)
- decrypted text = cypher^d(mod N)
*/

vector<uint64_t> getPrimeNumberPair() {
	uint64_t p = 2, q = 7;
	return {p, q};
}

uint64_t getModulus(uint64_t p, uint64_t q) {
	return multiply_and_modulus(p, q, );
}

uint64_t getPhi(uint64_t p, uint64_t q) {
	return (p-1)*(q-1);
}

uint64_t getEncryptionKey(uint64_t N, uint64_t phi) {
	// for (ll i = 1; i < phi; ++i) {
		
	// }
	return 0;
}

int main() {
	// vector<ll> primeNumbers = getPrimeNumberPair();
	// ll p = primeNumbers[0], q = primeNumbers[1];
	// cout << p << " " << q << endl;
	// ll N = getModulus(p, q);
	// cout << N << endl;
	// ll f = getPhi(p, q);
	// cout << f << endl;
	uint64_t prime = get_random_64_bit_prime();
	cout << prime;
	return 0;
}