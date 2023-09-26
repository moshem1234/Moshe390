#include <fstream>
#include "../../390Lab/Lab_7/bitmap.hh"
#include <webp/decode.h>
#include <webp/encode.h>
#include <random>
#include <cmath>

using namespace std;
/*

	AUTHOR: your name goes here
	CITE: cite any sources you used other than the ones given
	PLEDGE
*/

/*
	In order to access a particular element of this bitmap (x,y) use the
	following equation point(x,y) does this

	y*w + x

	this works because the first point is 0*w+0 = 0, the second would be 0*w+1

	one row down would be 1*w + 0
 */


int sqr(int x){
	return x*x;
}

bitmap::bitmap(uint32_t w, uint32_t h, uint32_t color) : w(w), h(h), rgb(new uint32_t[w*h]) {
	for (uint32_t i = 0; i < w*h; i++)
		rgb[i] = color;
}

bitmap::~bitmap() {
	delete [] rgb;
}

void bitmap::clear(uint32_t color) {
	for (uint32_t i = 0; i < w*h; i++)
		rgb[i] = color;
}

void bitmap::horiz_line(uint32_t x1, uint32_t x2, uint32_t y, uint32_t color) {
	//TODO: implement this
	for (uint32_t i = y * w + x1; i <= y * w + x2; i++) rgb[i] = color;
}

void bitmap::vert_line(uint32_t y1, uint32_t y2, uint32_t x, uint32_t color) {
	//TODO: implement this
	uint32_t i = y1 * w + x;
	while (i <= y2 * w + x){
		rgb[i] = color;
		y1++;
		i = y1 * w + x;
	}
}

void bitmap::fill_rect(uint32_t x0, uint32_t y0, uint32_t rw, uint32_t rh, uint32_t color) {
	//TODO: implement this  
	for (int j = y0; j <= y0+rh; j++){
		for (uint32_t i = j * w + x0; i <= j * w + x0+rw; i++) rgb[i] = color;
	}
	}

void bitmap::rect(uint32_t x0, uint32_t y0, uint32_t rw, uint32_t rh, uint32_t color) {
	//TODO: implement this  
	for (uint32_t i = y0 * w + x0; i <= y0 * w + x0+rw; i++) rgb[i] = color;
	for (uint32_t i = (y0+rh) * w + x0; i <= (y0+rh) * w + x0+rw; i++) rgb[i] = color;

	vert_line(y0, y0 + rh, x0, color);
    vert_line(y0, y0 + rh, x0 + rw, color);

	// uint32_t i = y0 * w + x0;
	// while (i <= (y0+rh) * w + x0){
	// 	rgb[i] = color;
	// 	y0++;
	// 	i = y0 * w + x0;
	// }

	// i = y0 * w + x0+rw;
	// while (i <= (y0+rh) * w + x0+rw){
	// 	rgb[i] = color;
	// 	y0++;
	// 	i = y0 * w + x0+rw;
	// }
}

void bitmap::grid(uint32_t x0, uint32_t y0, uint32_t rw, uint32_t rh,
									uint32_t divx, uint32_t divy, uint32_t color) {
	//TODO: implement this  
	for (uint32_t i = y0; i <= y0 + rh; i += (rh/divy)){
		horiz_line (x0, x0+rw, i, color);
		//for (uint32_t j = i * w + x0; j <= i * w + x0 + rw; j++) rgb[i] = color;

	}

	for (uint32_t i = x0; i <= x0 + rw; i += (rw/divx)){
		vert_line(y0, y0+rh, i, color);
	}
}


std::default_random_engine gen;

//https://stackoverflow.com/questions/22853349/how-to-generate-random-32bit-integers-in-c
void bitmap::random(uint32_t x0, uint32_t y0, uint32_t rw, uint32_t rh) {
	//TODO: implement this
	int color = 0xFFFC03B1;
	rect(x0,y0,rw,rh,color);
	for(int j = 0; j < 100; j++){
		int val;
		val = (gen()%rh+y0)*w+gen()%rw+x0;
		rgb[val] = color;
	}
}


void bitmap::circle(uint32_t x, uint32_t y, uint32_t d, uint32_t color) {
	//TODO: implement this

	// uint32_t valx,valy;
	// double testcal = 0;
    // uint32_t r = d/2;
	// double r_out = (r + 0.5) * (r + 0.5);
	// double r_in = (r - 0.5) * (r - 0.5);
	// for (int i = x - r; i <= x + r; i++) {
	// 	for (int j = y - r; j <= y + r; j++) {
	// 		testcal = ((i - x) * (i - x)) + ((j - y)* (j - y));
	// 		if (testcal < r_out && testcal > r_in) {
	// 			rgb[j * w + i] = color;
	// 		}
	// 	}
	// }

	// double r = d/2;
	// for (int i = x - r; i <= x + r; i++) {
	// 	for (int j = y - r; j <= y + r; j++) {
	// 		if (((i - x) * (i - x)) + ((j - y) * (j - y)) < (r+1) * (r+1) && ((i - x) * (i - x)) + ((j - y)* (j - y)) > (r - 1) * (r - 1)) {
	// 			rgb[j * w + i] = color;
	// 		}
	// 	}
	// }

	double r = d/2;
	for (int i = - r; i <= r; i++) {
		for (int j = -r; j <= r; j++) {
			if (sqr(i) + sqr(j) < sqr(r+1) && sqr(i) + sqr(j) > sqr(r-1)) {
				rgb[(y+j) * w + (i+x)] = color;
			}
		}
	}

    // for(uint32_t i = x-r; i<= x+r; i++)
    // {
    //     valx = i;
    //     valy = y + sqrt((r*r)-((x-i)*(x-i)));
    //     rgb[valy*w+valx] = color;
    // }
    // for(uint32_t i = x-r; i<= x+r; i++)
    // {
    //     valx = i;
    //     valy = y - sqrt((r*r)-((x-i)*(x-i)));
    //     rgb[valy*w+valx] = color;
    // }
    // for(uint32_t i = y-r; i<= y+r; i++)
    // {
    //     valx = i + sqrt((r*r)-((y-i)*(y-i)));
    //     valy = y;
    //     rgb[valy*w+valx] = color;
    // }
    // for(uint32_t i = y-r; i<= y+r; i++)
    // {
    //     valx = i - sqrt((r*r)-((y-i)*(y-i)));
    //     valy = y;
    //     rgb[valy*w+valx] = color;
    // }

	// for (int i = 0; i < d; i++){
	// 	for (int j = 0; j < d; j++){
	// 		if (sqrt(i*i+j*j)*2 == d){
	// 			int val = (int)((j+y)*w+(i+x));
	// 			rgb[val] = color;
	// 		}
	// 	}
	// }

	// for (int i = -d; i < 0; i++){
	// 	for (int j = 0; j < d; j++){
	// 		if (sqrt(i*i+j*j)*2 == d){
	// 			rgb[(j+y)*w+(i+x)] = color;
	// 		}
	// 	}
	// }

	// for (int i = -d; i < 0; i++){
	// 	for (int j = -d; j < 0; j++){
	// 		if (sqrt(i*i+j*j)*2 == d){
	// 			rgb[(j+y)*w+(i+x)] = color;
	// 		}
	// 	}
	// }

	// for (int i = 0; i < d; i++){
	// 	for (int j = -d; j < 0; j++){
	// 		if (sqrt(i*i+j*j)*2 == d){
	// 			rgb[(j+y)*w+(i+x)] = color;
	// 		}
	// 	}
	// }*/
}

//https://stackoverflow.com/questions/1201200/fast-algorithm-for-drawing-filled-circles
void bitmap::fill_circle(uint32_t x0, uint32_t y0, uint32_t d, uint32_t color) {
	//TODO: implement this 
	for (int i = d; i > 0; i--){
		circle(x0,y0,i,color);
		rgb[y0*w+x0] = color;
	} 
}


void bitmap::save(const char filename[]) {
	uint8_t*out;
	size_t s = WebPEncodeRGBA((uint8_t*)rgb, w, h, 4*w, 100, &out);
	ofstream f(filename, ios::binary);
	f.write((char*)out, s);
	WebPFree(out);
}

