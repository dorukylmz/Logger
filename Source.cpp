#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <thread>
#include <cstdlib>
#pragma warning(disable : 4996)

using namespace std;

int main(int argc,char * argv[])
{
	int x;
	if (argv[1])
	{   
		x = atoi(argv[1]);
	}
	else {
		x = 30;
	}

	while (true){
	fstream myFile;
	auto time = std::chrono::system_clock::now();
	myFile.open("logs.txt", ios::out);
	std::time_t end_time = std::chrono::system_clock::to_time_t(time);
	if (myFile.is_open()){
		myFile << "\nlogtime:" << std::ctime(&end_time);
		myFile.close();
		this_thread::sleep_for(chrono::minutes(x));
		
	}
	}
}