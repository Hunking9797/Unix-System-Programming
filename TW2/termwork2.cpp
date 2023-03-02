#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include<unistd.h>
#include<iostream>
using namespace std;
int main(){
	#ifdef _POSIX_JOB_CONTROL
		cout << "System supports job control feature " << endl;
	#else
		cout << "System doesn't support job control" << endl;
	#endif
	#ifdef _POSIX_SAVED_IDS
		cout << "System supports saved set-UID and saved sed_GID" << endl;
	#else
		cout << "System does not support saved set-UID" << endl;
	#endif
	#ifdef _POSIX_CHOWN_RESTRICTED
		cout << "System supports change ownership feature" << endl;
	#else
		cout << "System does not support change ownership feature" << endl;
	#endif
	#ifdef _POSIX_NO_TRUNC
		cout << "System support path truncation option" << endl;
	#else 
		cout << "System doesn't support path truncation" << endl;
	#endif
	#ifdef _POSIX_VDISABLE
		cout << "System supports disable character for files" << endl;
	#else 
		cout << "System doesn't support disable character" << endl;
	#endif
	return 0;
}
