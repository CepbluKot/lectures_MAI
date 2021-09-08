#include <iostream>

int strConteins(char* a, char* str) {
	int indexStr = 0;
	int indexA = 0;
	int start = 0;
	bool startFlag = false;
	bool endFlag = false;
	int size = 0;
	while (str[indexStr] != NULL) {
		if (!startFlag && str[indexStr] == a[indexA]) {
			start = indexStr;
			startFlag = true;
		}
		if (startFlag && a[indexA + 1] == NULL && a[indexA] == str[indexStr]) return start;

		else if (startFlag && str[indexStr + 1] != a[indexA + 1]) {
			startFlag = false;
			indexA = 0;
		}
		else if (a[indexA] == str[indexStr]) {
			indexA += 1;
		}
		indexStr += 1;
	}
	return -1;
}