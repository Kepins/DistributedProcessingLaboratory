#include <iostream>
#include <string>
#include "getFiles.h"
#include <filesystem>


void writeFiles(const Folder* root) {
	//indentation is used to represent tree structure of folders
	static std::string indentation = "";

	//print current folder name
	std::cout << indentation << (Finfo*)root << std::endl;

	//every call adds one '-' to indentation
	indentation += "-";

	//print information of every child
	for (Finfo* child : root->children) {

		if (child->folder) {
			writeFiles((Folder*)child);
		}

		else {
			std::cout << indentation << child << std::endl;
		}
	}

	//removes one '-' from indentation
	indentation.pop_back();
}


int wmain(int argc, wchar_t *argv[]) {
	namespace fs = std::filesystem;
	if (argc > 1) {

		const std::wstring path = argv[1];
		Folder* root;
		fs::path name(argv[0]);
		if (argc == 2) {
			root = getFiles(path, name.c_str(), true);
		}
		else{
			root = getFiles(path, name.c_str(), false);
		}
		writeFiles(root);

		delete root;
	}
	system("pause");
	return 0;
}
