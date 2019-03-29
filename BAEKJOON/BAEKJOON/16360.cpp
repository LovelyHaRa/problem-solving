#include<iostream>
#include<cstring>

using namespace std;

int main() {
	char a[100] = { '\0' };
	char b[100] = { '\0' };
	char c[100] = { '\0' };
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		memset(a, '\0', 99);
		memset(b, '\0', 99);
		memset(c, '\0', 99);
		scanf("%s", a);
		strncpy(b, a, strlen(a) - 1);
		switch (a[strlen(a) - 1]) {
		case'y':
		case'i':
			strcat(b, "ios");
			break;
		case'l':
		case'r':
		case'v':
			strcat(a, "es");
			strcpy(b, a);
			break;
		case'n':
			strcat(b, "anes");
			break;
		case'e':
			if (a[strlen(a) - 2] == 'n') {
				strncpy(c, b, strlen(b) - 1);
				strcat(c, "anes");
				strcpy(b, c);
			}
			else {
				strcat(a, "us");
				strcpy(b, a);
			}
			break;
		case 't':
		case 'w':
			strcat(a, "as");
			strcpy(b, a);
			break;
		case'a':
			strcat(b, "as");
			break;
		case'o':
			strcat(b, "os");
			break;
		case'u':
			strcat(b, "us");
			break;
		default:
			strcat(a, "us");
			strcpy(b, a);
			break;
		}
		cout << b << endl;
	}
}