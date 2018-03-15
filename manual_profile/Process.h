#ifndef PROCESS_H
#define PROCESS_H

#include "Sensor.h"
#include <vector>
#include <time.h>
#include <sys/timeb.h>
#include <unistd.h>
#include <stdio.h>

using namespace std;

class Process {

private:
	char* csv_file_name;
	FILE *csv_file;
	vector<Sensor> vSensor;
	int num_of_profile;

	time_t time1;
	struct tm *now;
	struct timeb timebuffer;
	int millisec;
public:
	void set_csv_file_name(char* csv_file_name);
	void open_csv_file();
	void make_sensor_to_vSensor();
	void set_vSensor_name();
	void close_csv_file();
	void write_to_csv();
	void repeat_read_write();
	void set_num_of_profile(int num_of_profile);
	int get_num_of_profile();
	void set_vSensor_make_name();
	void read_data_from_sensor();
	void main_process();
};

#endif
