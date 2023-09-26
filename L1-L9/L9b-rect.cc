#include "L9c-rect.hh"
#include <numbers>
#include <cmath>
using namespace std;
using namespace std::numbers;

void rect::draw_layer(ostream& gc,
											double x, double y,
											double layer_thickness, double z) const {
	//TODO: jump from current point to nearest angle on circle. For now angle = 0
	double ang = 0;
	double da = 2 * pi / 4;
	double r = this->r;
	for (uint32_t concentric = 0; concentric < num_concentric_layers; concentric++) {
		for (uint32_t f = 0; f < facets; f++, ang += da)
			squirt_toxy(gc, x + r * cos(ang), y + r * sin(ang)); // first time (r,0)
		r += 0.000001;
	}
}

double rect::height() const {
	return H;
}
