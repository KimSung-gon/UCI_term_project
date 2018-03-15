#include "Process.h"
#include <iostream>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	
	if(argc != 3) {
		cout << "Format : ./manual_profile <csv file name> <num of profile>\ncsv file name : This is the file you want to write to\nnum of profile : This is num of profiling and each iteration spend 0.1 second" << endl;
		return -1;
	}

	Process process1;
	process1.set_csv_file_name(argv[1]);
	process1.set_num_of_profile(atoi(argv[2]));
	process1.main_process();
}
