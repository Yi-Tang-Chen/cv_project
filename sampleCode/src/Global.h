#pragma once
#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <windows.h>
#include <string>
#include <iostream>
#include <vector>
#include <filesystem>

using namespace std;

class Global {
public:
	Global();
	~Global();

	static string PathExeFile;
	static string PathImage;
	static vector<string> PathDll;

	int initialDll();

private:
	struct debugMsg {
	public:
		debugMsg() {
			string s = typeid(*this).name();
			size_t start = s.find(' ');
			size_t stop = s.find(':');
			std::cout << "[" << s.substr(start + 1, stop - start - 1) << "]";
		}
		~debugMsg() {
			std::cout << std::endl;
		}
		template<class T>
		debugMsg& operator<<(T t) {
			std::cout << t;
			return *this;
		}
		debugMsg& operator<<(ostream& (*f)(ostream& o)) {
			std::cout << f;
			return *this;
		};
	};
};


#endif