/*
* sebastien GEIGER IPHC CNRS
* le 26/10/2018
* Copyright (C) 2018 CNRS
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License
*
*/

#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fstream>
#include <string>
using namespace std;

void usage() {
	cout <<
	  "usage:\n"
		"  -i fname : csv wacu acl file read\n"
		"  -o fname : csv wacu acl file out\n"
		"  -n int   : max line read\n"
		"  -h       : Show this help\n";	
	exit(1);
}

int main(int argc, char **argv) {
string fin = "World";
string fou = "";
int c=0;
int tvalue = -1;

if(argc<2) usage();

while ((c = getopt (argc, argv, "hi:o:n:")) != -1)
switch(c) {
	case 'h': usage(); break;
	case 'i': fin = optarg; break;
	case 'o': fou = optarg; break;
	case 'n': tvalue = atoi(optarg);break;
}

string line;
ifstream finstream(fin.c_str());
ofstream foustream(fou.c_str());
if  (!foustream.is_open()) {
  cout<<"Unable to open output file"<<endl;
}
if (finstream.is_open()) {
	//read head
	getline(finstream,line);
	//read next line
	getline(finstream,line);	
	while ( getline (finstream,line) ) {
	  if (line.find(" ")!=0) {
      foustream << line << '\n';  
	  }
	  if(tvalue>0) {
		  if(c>tvalue) {
			  break;
		  }
	  }
	  c++;
	}
	finstream.close();
  foustream.close();
} else cout << "Unable to open input file\n"; 

return 0;
}

