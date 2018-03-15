#ifndef SENSOR_H
#define SENSOR_H

#include <string>

using namespace std;

class Sensor {

private:
	string name;
	int current;
	int voltage;
	int power;

public:
	void set_name(string name);
	void set_current(int current);
	void set_voltage(int voltage);
	void set_power(int power);

	string get_name();
	int get_current();
	int get_voltage();
	int get_power();
};

#endif
