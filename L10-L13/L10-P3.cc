#include <iostream>
#include <immintrin.h>
#include <time.h>
// ?#include <nmmintrin.h>

using namespace std;
/*
	write code to traverse the array and count all the 1 bits
	00000000000001   0000000000000010    00000000000011  000000000000100 0000000000101
               1 +               1 +               2 +             1 +           2 + ...
 */
uint32_t countBits(uint32_t x[], uint32_t n){
	int a = 0;
	int b;
	int c;
	for(int i = 0; i < n; i++){
		c = x[i];
		while(c > 0){
			b = c;
			a += b%2;
			c /= 2;
		}
	}
	return a;
}

/*
  now, do it using intel intrinsics
	https://www.intel.com/content/www/us/en/docs/intrinsics-guide/index.html
  the intel instruction to count bits is called _mm_popcnt_u32
*/
uint32_t countBits2(uint32_t x[], uint32_t n){
	int ret = 0;
	for(int i = 0; i < n; i++){
		ret += _mm_popcnt_u32(x[i]);
	}
	return ret;
}

//Extra credit: do it 64 bits at a time for higher speed
uint32_t countBits3(uint32_t x[], uint32_t n){
	int ret = 0;
	uint64_t val1,val2,val3;
	for(int i = 0; i < n; i+=2){
		val1 = x[i];
		val2= x[i+1];
		val3 = (val1<<32)|(val2);
		ret += _mm_popcnt_u64(val3);
	}
	return ret;
}

/*
Extra, extra credit. Do it 256 bits at a time
__m256i _mm256_maskz_popcnt_epi64 (__mmask8 k, __m256i a)

Using the avx2 vector registers is signfiicantly harder but if you can do it, just cite where you got the information. Copying is not bad, it's smart (just cite your sources)
*/

int main() {
  const int n = 1000000000;
  uint32_t* p = new uint32_t[n];
  for (int i = 0; i < n; i++)
    p[i] = i;

	clock_t t0 = clock();
	uint32_t ans = countBits(p, n);

	clock_t t1 = clock();
	cout << "Elapsed (1): " << (t1-t0) << '\n';
	cout << "Answer (1): " << ans << '\n';

	cout << endl;

	clock_t t2 = clock();
	uint32_t ans2 = countBits2(p, n);

	clock_t t3 = clock();
	cout << "Elapsed (2): " << (t3-t2) << '\n';
	cout << "Answer (2): " << ans2 << '\n';

	int diff = (t1-t0)/(t3-t2);
	cout << "Due to Intel intrinsics with 32 bits, the same code ran over " << diff << " times faster!!!" << endl;

	cout << endl;

	clock_t t4 = clock();
	uint32_t ans3 = countBits3(p, n);

	clock_t t5 = clock();
	cout << "Elapsed (3): " << (t5-t4) << '\n';
	cout << "Answer (3): " << ans3 << '\n';
  	delete [] p;

	int diff2 = (t1-t0)/(t5-t4);
	cout << "Due to Intel intrinsics using 64 bits, the same code ran over " << diff2 << " times faster!!!" << endl;

}
