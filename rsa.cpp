#include <iostream>
#include <vector>
#include <cstdint>
#include "prime_number.h"
using namespace std;

int main()
{
	// PROCEDURE
	big_number p, q, N, phi, e, d;
	int bit_size = 64, k = 2;

	// STEP 1
	// choose two prime numbers say (p & q)
	p = get_random_prime(bit_size);
	cout << "p :: " << p << endl;
	q = get_random_prime(bit_size);
	// p and q should be different
	while (p == q)
	{
		q = get_random_prime(bit_size);
	}
	cout << "q :: " << q << endl;

	// STEP 2
	// find N i.e. p*q
	// will be used to take modulus
	N = p * q;
	cout << "N :: " << N << endl;

	// STEP 3
	// find phi i.e (p-1)*(q-1)
	// phi :: number of numbers between 1(inclusive) -
	// - and N(inclusive) that are co prime with N
	phi = (p - 1) * (q - 1);
	cout << "f :: " << phi << endl;

	// STEP 4
	// find e :: makes encryption key along with N
	// i.e. (e, N) collectively make encryption key or public key
	// `e` should satisfy two conditions
	// - 1 < e < phi
	// - coprime with N & phi
	// a random prime number with same BIT_SIZE as p & q -
	// - and not equal to p and q will satisfy these conditions
	e = get_random_prime(bit_size);
	big_number flag;
	flag = gcd(e, phi);
	while (flag != 1)
	{
		e = get_random_prime(bit_size);
		flag = gcd(e, phi);
	}
	cout << "e :: " << e << endl;

	// STEP 5
	// find d :: makes decryption key along with N
	// i.e. (d, N) collectively make decryption key or private key
	// `d` should satify this relation :: (d*e)(mod phi) = 1
	// or d = (1 + k * phi) / e ; where k is any random constant
	d = (1 + k * phi) / e;
	cout << "d :: " << d << endl;

	// STEP 6
	// encrypt & decrypt message
	big_number message, cypher_text, decyphered_text;
	// store message as a number
	message = 12;
	cypher_text = power_modulus(message, e, N);
	decyphered_text = power_modulus(cypher_text, d, N);
	return 0;
}