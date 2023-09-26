#include <iostream>
#include <iomanip>
#include <cmath>
#include <bitset>
using namespace std;


uint64_t compress(const uint32_t in[], uint32_t len, uint64_t out[]){
    int m = len/32;
    for (int i = 0; i < m; i++){
        uint64_t ret = 0;
        for (int j = 32*i; j < 32*(i+1); j++){
            if (j <= len){
            ret <<= 2;
            ret |= in[j];
            }
            if (j == len){
                ret >>=2;
            }
        }
        out[i] = ret;
    }
    uint64_t ret = 0;
    for (int k = m*32; k < len; k++){
            if (k <= len){
            ret <<= 2;
            ret |= in[k];
            }
            if (k == len){
                ret >>=2;
            }
        }
    out[m] = ret;  
    return 1+m;
}

uint64_t arithmeticCompress(const uint32_t in[], uint32_t len, uint32_t base){
    uint64_t ret = in[0];
    for (int i = 1; i < len; i++){
        ret *= base;
        ret += in[i];
    }
    return ret;
}

int main(){
    cout << "Question 1-----------------------------------" << endl;
    uint32_t a[65];
    uint64_t out[3] = {0,0,0};
    for (int i = 0; i < 65; i++) {
        a[i] = i % 4;
    }
							
	uint64_t out_len = compress(a, 65, out);
	for (uint32_t i = 0; i < out_len; i++) {
		cout << bitset<64>(out[i]) << '\t';
		cout << '\n';
	}
	

    cout << "Question 2-----------------------------------" << endl;
    uint32_t in[] = {22, 5, 19, 12, 6, 18, 2, 14, 10, 0, 9, 15, 17, 20};
    uint64_t ans = arithmeticCompress(in, 14, 23);
    cout << ans << '\n' << endl;

    return 0;
}
