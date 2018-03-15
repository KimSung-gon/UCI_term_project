#include "Process.h"

void Process::set_csv_file_name(char* csv_file_name) {
	this->csv_file_name = csv_file_name;
}

void Process::open_csv_file() {
	this->csv_file = fopen(this->csv_file_name, "w+");
}

void Process::make_sensor_to_vSensor() {

	for(int i=0; i<12; i++) {
		Sensor sensor;
		this->vSensor.push_back(sensor);
	}
}

void Process::set_vSensor_name() {
	vSensor.at(0).set_name("VDD_SYS_GPU");
	vSensor.at(1).set_name("VDD_SYS_SOC");
	vSensor.at(2).set_name("VDD_4VO_WIFI");
	vSensor.at(3).set_name("VDD_IN");
	vSensor.at(4).set_name("VDD_SYS_CPU");
	vSensor.at(5).set_name("VDD_SYS_DDR");
	vSensor.at(6).set_name("VDD_MUX");
	vSensor.at(7).set_name("VDD_5VO_IO_SYS");
	vSensor.at(8).set_name("VDD_3V3_SYS");
	vSensor.at(9).set_name("VDD_3V3_IO_SLP");
	vSensor.at(10).set_name("VDD_1V8_IO");
	vSensor.at(11).set_name("VDD_3V3_SYSi_M2");
}

void Process::close_csv_file() {
	fclose(this->csv_file);
}

void Process::write_to_csv() {
	
	this->read_data_from_sensor();
	
	ftime(&timebuffer);
	time1 = timebuffer.time;
	millisec = timebuffer.millitm;
	now = localtime(&time1);
	fprintf(this->csv_file, "%dm %ds %d;", now->tm_min, now->tm_sec, millisec);

	for(int i=0; i<12; i++) {
		fprintf(this->csv_file, "%d;", this->vSensor.at(i).get_current());
		fprintf(this->csv_file, "%d;", this->vSensor.at(i).get_voltage());
		fprintf(this->csv_file, "%d;", this->vSensor.at(i).get_power());
	}
 	fprintf(this->csv_file, "\n", NULL);
}

void Process::repeat_read_write() {
	this->open_csv_file();
	fprintf(this->csv_file, "%s;", "TIME");
	for(int i=0; i<12; i++) {
		fprintf(this->csv_file, "%s;", this->vSensor.at(i).get_name().append("_CURRENT").c_str());
		fprintf(this->csv_file, "%s;", this->vSensor.at(i).get_name().append("_VOLTAGE").c_str());
		fprintf(this->csv_file, "%s;", this->vSensor.at(i).get_name().append("_POWER").c_str());
	}	
	fprintf(this->csv_file, "\n", NULL);
	for(int i=0; i<this->num_of_profile; i++) {
		this->write_to_csv();	
		usleep(100000);
	}	
	this->close_csv_file();
}

void Process::set_num_of_profile(int num_of_profile) {
	this->num_of_profile = num_of_profile;
}

int Process::get_num_of_profile() {
	return this->num_of_profile;
}

void Process::set_vSensor_make_name() {
	this->make_sensor_to_vSensor();
	this->set_vSensor_name();
}

void Process::read_data_from_sensor() {
	FILE* fp;
	int data;

	//	/sys/devices/3160000.i2c/i2c-0/0-0040/iio_device
	fp = fopen("/sys/devices/3160000.i2c/i2c-0/0-0040/iio_device/in_current0_input", "r");
	fscanf(fp, "%d", &data);
	this->vSensor.at(0).set_current(data);
	fclose(fp);	
	fp = fopen("/sys/devices/3160000.i2c/i2c-0/0-0040/iio_device/in_voltage0_input", "r");
	fscanf(fp, "%d", &data);
	this->vSensor.at(0).set_voltage(data);
	fclose(fp);	
	fp = fopen("/sys/devices/3160000.i2c/i2c-0/0-0040/iio_device/in_power0_input", "r");
	fscanf(fp, "%d", &data);
	this->vSensor.at(0).set_power(data);
	fclose(fp);	

	fp = fopen("/sys/devices/3160000.i2c/i2c-0/0-0040/iio_device/in_current1_input", "r");
	fscanf(fp, "%d", &data);
	this->vSensor.at(1).set_current(data);
	fclose(fp);	
	fp = fopen("/sys/devices/3160000.i2c/i2c-0/0-0040/iio_device/in_voltage1_input", "r");
	fscanf(fp, "%d", &data);
	this->vSensor.at(1).set_voltage(data);
	fclose(fp);	
	fp = fopen("/sys/devices/3160000.i2c/i2c-0/0-0040/iio_device/in_power1_input", "r");
	fscanf(fp, "%d", &data);
	this->vSensor.at(1).set_power(data);
	fclose(fp);	

	fp = fopen("/sys/devices/3160000.i2c/i2c-0/0-0040/iio_device/in_current2_input", "r");
	fscanf(fp, "%d", &data);
	this->vSensor.at(2).set_current(data);
	fclose(fp);	
	fp = fopen("/sys/devices/3160000.i2c/i2c-0/0-0040/iio_device/in_voltage2_input", "r");
	fscanf(fp, "%d", &data);
	this->vSensor.at(2).set_voltage(data);
	fclose(fp);	
	fp = fopen("/sys/devices/3160000.i2c/i2c-0/0-0040/iio_device/in_power2_input", "r");
	fscanf(fp, "%d", &data);
	this->vSensor.at(2).set_power(data);
	fclose(fp);

	
	//	/sys/devices/3160000.i2c/i2c-0/0-0041/iio_device
	fp = fopen("/sys/devices/3160000.i2c/i2c-0/0-0041/iio_device/in_current0_input", "r");
	fscanf(fp, "%d", &data);
	this->vSensor.at(3).set_current(data);
	fclose(fp);	
	fp = fopen("/sys/devices/3160000.i2c/i2c-0/0-0041/iio_device/in_voltage0_input", "r");
	fscanf(fp, "%d", &data);
	this->vSensor.at(3).set_voltage(data);
	fclose(fp);	
	fp = fopen("/sys/devices/3160000.i2c/i2c-0/0-0041/iio_device/in_power0_input", "r");
	fscanf(fp, "%d", &data);
	this->vSensor.at(3).set_power(data);
	fclose(fp);	

	fp = fopen("/sys/devices/3160000.i2c/i2c-0/0-0041/iio_device/in_current1_input", "r");
	fscanf(fp, "%d", &data);
	this->vSensor.at(4).set_current(data);
	fclose(fp);	
	fp = fopen("/sys/devices/3160000.i2c/i2c-0/0-0041/iio_device/in_voltage1_input", "r");
	fscanf(fp, "%d", &data);
	this->vSensor.at(4).set_voltage(data);
	fclose(fp);	
	fp = fopen("/sys/devices/3160000.i2c/i2c-0/0-0041/iio_device/in_power1_input", "r");
	fscanf(fp, "%d", &data);
	this->vSensor.at(4).set_power(data);
	fclose(fp);	

	fp = fopen("/sys/devices/3160000.i2c/i2c-0/0-0041/iio_device/in_current2_input", "r");
	fscanf(fp, "%d", &data);
	this->vSensor.at(5).set_current(data);
	fclose(fp);	
	fp = fopen("/sys/devices/3160000.i2c/i2c-0/0-0041/iio_device/in_voltage2_input", "r");
	fscanf(fp, "%d", &data);
	this->vSensor.at(5).set_voltage(data);
	fclose(fp);	
	fp = fopen("/sys/devices/3160000.i2c/i2c-0/0-0041/iio_device/in_power2_input", "r");
	fscanf(fp, "%d", &data);
	this->vSensor.at(5).set_power(data);
	fclose(fp);	


	//	/sys/devices/3160000.i2c/i2c-0/0-0042/iio_device
	fp = fopen("/sys/devices/3160000.i2c/i2c-0/0-0042/iio_device/in_current0_input", "r");
	fscanf(fp, "%d", &data);
	this->vSensor.at(6).set_current(data);
	fclose(fp);	
	fp = fopen("/sys/devices/3160000.i2c/i2c-0/0-0042/iio_device/in_voltage0_input", "r");
	fscanf(fp, "%d", &data);
	this->vSensor.at(6).set_voltage(data);
	fclose(fp);	
	fp = fopen("/sys/devices/3160000.i2c/i2c-0/0-0042/iio_device/in_power0_input", "r");
	fscanf(fp, "%d", &data);
	this->vSensor.at(6).set_power(data);
	fclose(fp);	

	fp = fopen("/sys/devices/3160000.i2c/i2c-0/0-0042/iio_device/in_current1_input", "r");
	fscanf(fp, "%d", &data);
	this->vSensor.at(7).set_current(data);
	fclose(fp);	
	fp = fopen("/sys/devices/3160000.i2c/i2c-0/0-0042/iio_device/in_voltage1_input", "r");
	fscanf(fp, "%d", &data);
	this->vSensor.at(7).set_voltage(data);
	fclose(fp);	
	fp = fopen("/sys/devices/3160000.i2c/i2c-0/0-0042/iio_device/in_power1_input", "r");
	fscanf(fp, "%d", &data);
	this->vSensor.at(7).set_power(data);
	fclose(fp);	

	fp = fopen("/sys/devices/3160000.i2c/i2c-0/0-0042/iio_device/in_current2_input", "r");
	fscanf(fp, "%d", &data);
	this->vSensor.at(8).set_current(data);
	fclose(fp);	
	fp = fopen("/sys/devices/3160000.i2c/i2c-0/0-0042/iio_device/in_voltage2_input", "r");
	fscanf(fp, "%d", &data);
	this->vSensor.at(8).set_voltage(data);
	fclose(fp);	
	fp = fopen("/sys/devices/3160000.i2c/i2c-0/0-0042/iio_device/in_power2_input", "r");
	fscanf(fp, "%d", &data);
	this->vSensor.at(8).set_power(data);
	fclose(fp);	


	//	/sys/devices/3160000.i2c/i2c-0/0-0043/iio_device
	fp = fopen("/sys/devices/3160000.i2c/i2c-0/0-0043/iio_device/in_current0_input", "r");
	fscanf(fp, "%d", &data);
	this->vSensor.at(9).set_current(data);
	fclose(fp);	
	fp = fopen("/sys/devices/3160000.i2c/i2c-0/0-0043/iio_device/in_voltage0_input", "r");
	fscanf(fp, "%d", &data);
	this->vSensor.at(9).set_voltage(data);
	fclose(fp);	
	fp = fopen("/sys/devices/3160000.i2c/i2c-0/0-0043/iio_device/in_power0_input", "r");
	fscanf(fp, "%d", &data);
	this->vSensor.at(9).set_power(data);
	fclose(fp);	

	fp = fopen("/sys/devices/3160000.i2c/i2c-0/0-0043/iio_device/in_current1_input", "r");
	fscanf(fp, "%d", &data);
	this->vSensor.at(10).set_current(data);
	fclose(fp);	
	fp = fopen("/sys/devices/3160000.i2c/i2c-0/0-0043/iio_device/in_voltage1_input", "r");
	fscanf(fp, "%d", &data);
	this->vSensor.at(10).set_voltage(data);
	fclose(fp);	
	fp = fopen("/sys/devices/3160000.i2c/i2c-0/0-0043/iio_device/in_power1_input", "r");
	fscanf(fp, "%d", &data);
	this->vSensor.at(10).set_power(data);
	fclose(fp);	

	fp = fopen("/sys/devices/3160000.i2c/i2c-0/0-0043/iio_device/in_current2_input", "r");
	fscanf(fp, "%d", &data);
	this->vSensor.at(11).set_current(data);
	fclose(fp);	
	fp = fopen("/sys/devices/3160000.i2c/i2c-0/0-0043/iio_device/in_voltage2_input", "r");
	fscanf(fp, "%d", &data);
	this->vSensor.at(11).set_voltage(data);
	fclose(fp);	
	fp = fopen("/sys/devices/3160000.i2c/i2c-0/0-0043/iio_device/in_power2_input", "r");
	fscanf(fp, "%d", &data);
	this->vSensor.at(11).set_power(data);
	fclose(fp);	
}

void Process::main_process() {
	this->set_vSensor_make_name();
	this->repeat_read_write();	
}
