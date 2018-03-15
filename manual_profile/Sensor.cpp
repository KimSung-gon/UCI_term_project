#include "Sensor.h"

void Sensor::set_name(string name) {
	this->name = name;
}

void Sensor::set_current(int current) {
	this->current = current;
}

void Sensor::set_voltage(int voltage) {
	this->voltage = voltage;
}

void Sensor::set_power(int power) {
	this->power = power;
}

string Sensor::get_name() {
	return this->name;
}

int Sensor::get_current() {
	return this->current;
}

int Sensor::get_voltage() {
	return this->voltage;
}

int Sensor::get_power() {
	return this->power;
}
