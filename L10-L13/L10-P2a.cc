#include <cstring>
#include "L-10-P2.hh"

uint64_t f2c(uint64_t n) {
	uint64_t sum = 0;
	for (uint64_t i = 1; i <= n; i++)
		sum += i / (i+1);
	return sum;
}

 // read sequentially, add all elements in array
uint64_t f3a(uint64_t a[], uint64_t n) {
	uint64_t sum = 0;
	for (uint64_t i = 0; i < n; i++)
		sum += a[i];
	return sum;
}

/*
	read elements 0, 2, 4, ...
	then          1, 3, 5, ...

	In other words, read the same number of elements as f4, but a bit out of order
*/
uint64_t f3b(uint64_t a[], uint64_t n) {
	uint64_t sum = 0;
	for (uint64_t j = 0; j < 2; j++)
		for (uint64_t i = j; i < n; i += 2) {
			sum += a[i];
		}
	return sum;
}

// same but every k elements
uint64_t f3c(uint64_t a[], uint64_t n, uint64_t k) {
	//TODO:
	uint64_t sum = 0;
	for (uint64_t j = 0; j < k; j++)
		for (uint64_t i = j; i < n; i += k) {
			sum += a[i];
		}
	return sum;
}

// Write a function that adds
uint64_t f3d(uint64_t a[], uint64_t n) {
	uint64_t sum = 0;
	for (uint64_t j = 0; j < 2; j++)
		for (uint64_t i = j; i < n; i += 2) {
			a[i]++;
		}
	return 0;
}

// same but every k elements
uint64_t f3e(uint64_t a[], uint64_t n, uint64_t k) {
	uint64_t sum = 0;
	for (uint64_t j = 0; j < k; j++)
		for (uint64_t i = j; i < n; i += k) {
			a[i]++;
		}
	return 0;
}

void xor_crypt(char msg[], uint64_t len, char key) {
	for (uint64_t i = 0; i < len; i++)
	  msg[i] ^= key;
}


void dov(char msg[], uint64_t len, const char key[], int bize) {
	//TODO:
	int j = 0;
	for (uint64_t i = 0; i < len; i++){
			msg[i] ^= key[j];
		if(j == bize){
			j = 0;
		}
	}
}

void dov8(char* msg[], uint64_t len, const char key[]) {
	int keylen = strlen(key); // find out the length of the key
	uint64_t key8[32]; // big key 8 bytes at a time
	char* key_as_bytes = (char*)key8;
	const uint64_t key8end = keylen / 8 * 8 + keylen % 8 * 8;
	for (int i = 0, j = 0; i < key8end; i++) {
		key_as_bytes[i] = key[j++];
		if (j >= len)
			j = 0;
	}

	 // look at the message as though it is 64-bit integers
	uint64_t* p = (uint64_t*)msg;

	// to keep things simple, ignore the last few bytes that might not
	// be a multiple of 8
	uint64_t msglen8 = len / 8;
	for (uint64_t i = 0, j = 0; i < msglen8; i++) {
		p[i] ^= key8[j++];
		if (j > key8end)
			j = 0;
	}
}






