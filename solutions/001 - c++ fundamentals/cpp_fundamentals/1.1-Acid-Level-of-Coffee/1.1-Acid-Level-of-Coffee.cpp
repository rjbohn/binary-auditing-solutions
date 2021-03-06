// 1.1-Acid-Level-of-Coffee.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
                                                                                     

float find_farthest(float *data, unsigned int size, float average) {

	float farthest = 0.0;
	float max_diff = 0.0;
	int index_farthest = 0;

	for (unsigned int i = 0; i < size; i++) {
		if (data[i] >= average && data[i] - average > max_diff) {
			max_diff = data[i] - average;
			farthest = data[i];
			index_farthest = i;

		}

		else if (data[i] < average && average - data[i] > max_diff) {
			max_diff = average - data[i];
			farthest = data[i];
			index_farthest = i;
		}
	}

	// Set the farthest value in the array to -1
	data[index_farthest] = -1;

	return farthest;
}

float average(float *data, unsigned int size) {
	float sum = 0.0;

	for (unsigned int i = 0; i < size; i++) {
		if (data[i] == -1) {
			continue;
		}
		sum += data[i];
	}

	return  sum / size;
}

int main(int argc, char **argv) {

	const char* filename = "CoffeeData.txt";
	float a = 0.0;
	float *data = NULL;
	int i = -1;
	unsigned int size = 0;

	std::ifstream ifs(filename);
	if (!ifs.is_open()) {
		std::cout << "Failed to open the file :" << filename;
	}

	while (ifs >> a) {

		// Init our array of init during first read
		if (i == -1) {
			size = (unsigned int)a;
			data = new float[size];
		}

		// Fill out arrays otherwise
		else {
			data[i] = a;
			std::cout << "data [ " << i << " ] = " << data[i] << std::endl;
		}

		i++;
	}

	// Print the average
	float avg = average(data, size);
	std::cout << "average: " << avg << std::endl;

	// Find the farthest
	float farthest = find_farthest(data, size, avg);
	std::cout << "most distant value: " << farthest << std::endl;

	// Calculate the new average
	float new_avg = average(data, size);
	std::cout << "new average: " << new_avg << std::endl;

	return 0;
}