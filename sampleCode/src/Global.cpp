#include "Global.h"
string Global::PathExeFile = "";
string Global::PathImage = "";
vector<string> Global::PathDll(0);

Global::Global() {
	char buffer[MAX_PATH];
	GetModuleFileNameA(NULL, buffer, MAX_PATH);
	GetLongPathNameA(buffer, buffer, MAX_PATH);
	string temp = std::string(buffer);
	std::size_t found = temp.find('\\');
	while (found != std::string::npos) {
		temp.replace(found, 1, "/");
		found = temp.find('\\', found + 1);
	}
	PathExeFile = temp.substr(0, temp.find_last_of("/") + 1);
	debugMsg() << "PathExeFile = " << PathExeFile;

	string pathBase = string(CMAKE_CURRENT_SOURCE_DIR);
	if (PathExeFile.find(string(CMAKE_CURRENT_SOURCE_DIR)) == std::string::npos) {
		pathBase = PathExeFile;
	}
	PathImage = pathBase + "img/";
	debugMsg() << "PathImage = " << PathImage;

	PathDll.push_back(pathBase + "lib/opencv-4.10.0/x64/vc17/bin");
	PathDll.push_back(pathBase + "lib/Spinnaker_x64/bin64/vs2015");
	for (int i = 0; i < PathDll.size(); i++) {
		debugMsg() << "PathDll = " << PathDll.at(i);
	}
}

Global::~Global() {
}

int Global::initialDll() {
	SetDefaultDllDirectories(LOAD_LIBRARY_SEARCH_APPLICATION_DIR | LOAD_LIBRARY_SEARCH_DEFAULT_DIRS | LOAD_LIBRARY_SEARCH_SYSTEM32 | LOAD_LIBRARY_SEARCH_USER_DIRS);
	for (int i = 0; i < PathDll.size(); i++) {
		while (AddDllDirectory(wstring(PathDll.at(i).begin(), PathDll.at(i).end()).c_str()) == 0) {
			debugMsg() << "load Dll failed, try again after 3s....";
			debugMsg() << "failed path: " << PathDll.at(i);
			Sleep(3000);
		}
	}
	return 0;
}

