#include "L13.hh"
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <random>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

std::ostream& operator<<(std::ostream& s, const Vec3d& v) {
  return s << v.x << ',' << v.y << ',' << v.z;
}

Body::Body(const char name[16], const char orbits[16], double m, double x,
           double y, double z, double vx, double vy, double vz)
    : m(m), pos(x, y, z), v(vx, vy, vz), a() {
  strncpy(this->name, name, 16);
  this->Gm = G * m;
}

ostream& operator<<(ostream& s, const Body& b) {
  return s << b.name << "\t\t" << b.pos << "\t\t" << b.v << "\t\t" << b.a;
}

default_random_engine gen(0);
uniform_int_distribution<int> dist(1, 6);
normal_distribution<double> angle(0, 2 * M_PI);
unordered_map<string, Body*> bodiesByName;

GravSim::GravSim(const char filename[]) {
  t = 0;
  ifstream f(filename);
  char buf[4096];
  f.getline(buf, sizeof(buf));
  char name[16];
  char orbits[16];
  double m, diam, perihelion, aphelion, x, y, z, vx, vy, vz;
  double orbPeriod, rotPeriod;
  cout << "Name\tPosition\t\tVelocity\t\tAcceleration\n" << setprecision(15);
  while (!f.eof()) {
    f.getline(buf, sizeof(buf));
    istringstream line(buf);
    line >> name >> m >> diam >> perihelion >> aphelion >> orbPeriod, rotPeriod;
    const double theta = 0;
    double r = (perihelion + aphelion) / 2;
    double x = r, y = 0, z = 0;
    double aphelionINV = 1 / aphelion;
    double val = G * m * (2 / r - aphelionINV);
    double v = r == 0 ? 0 : sqrt(val);
    double vx = 0, vy = v, vz = 0;
    bodies.push_back(Body(name, orbits, m, x, y, z, vx, vy, vz));
    bodiesByName[orbits] = &bodies.back();
    cout << bodies.back() << '\n';
  }
}

inline Vec3d Body::gravAccel(const Body& b)
    const {
  Vec3d dpos = pos - b.pos;
  double r = sqrt(dpos.x*dpos.x+dpos.y*dpos.y+dpos.z*dpos.z);
  double Gm = G * b.m;// b.Gm
  double rINV = 1 / r;
  double r1 = rINV * rINV;
  double amag = Gm * r1;
  double amag2 = amag / r;
  return Vec3d(dpos.x * amag2, dpos.y * amag2, dpos.z * amag2);
}

void GravSim::timestep(double dt) {
  for (int i = 0; i < bodies.size(); i++) {
    Vec3d a;
    for (int j = 0; j < bodies.size(); j++)
      if (i != j)
        a = a + bodies[i].gravAccel(bodies[j]);
        bodies[i].a = a;
  }

  for (int i = 0; i < bodies.size(); i++) {
    bodies[i].pos = bodies[i].pos + dt * (0.5*bodies[i].a * dt + bodies[i].v);
    bodies[i].v += bodies[i].a * dt;
  }
  t += dt;
}

void GravSim::forward(uint32_t n, double dt) {
  for (uint32_t i = 0; i < n; i++) {
    timestep(dt);
  }
  cout << *this;
}

std::ostream& operator<<(std::ostream& s, const GravSim& sim) {
  s << "GravSim t=" << sim.t << '\n';
  for (auto b : sim.bodies) s << b << '\n';
  return s;
}

int main(int argc, char* argv[]) {
	GravSim sim("../390Lab/Lab_13/solarsys.dat");
	const double secondsInYear = 31556952;
	//const double dt = 10;
	const uint32_t numTimeSteps = uint32_t(3155695);
	const uint32_t numStepsPerPrint = numTimeSteps;
	for (uint32_t i = 0; i < numTimeSteps; i+= numStepsPerPrint) {
		sim.forward(numStepsPerPrint, 10);
	}
}