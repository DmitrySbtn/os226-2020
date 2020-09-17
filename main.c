#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int rcode;

int echo(int argc, char *argv[])
{
	for (int i = 1; i < argc; ++i)
    {
printf("%s%c", argv[i], i == argc - 1 ? '\n' : ' ');
	}
	return argc - 1;
}

int retcode(int argc, char *argv[])
{
	printf("%d\n", rcode);
	return 0;
}

int main(int argc, char* argv[]) {
	rcode = 0;
	char in[1000000];
	char* str = NULL;
	char* str2 = NULL;

	while (fgets(in, sizeof in, stdin)) {
        char* mark1 = strtok(in, "\n;");
		while (mark1 != NULL) {
            argc = 0;
			char* mark2 = strtok(mark1, " ");
			while (mark2 != NULL) {
				argv[argc++] = mark2;
				mark2 = strtok(NULL, " ");
			}

			if (!strcmp(argv[0], "retcode"))
				retcode(argc, argv);
			else if (!strcmp(argv[0], "echo"))
				rcode = echo(argc, argv);
			else
				printf("%s", "\nUnknown command\n");

			mark1 = strtok(NULL, "\n;");
		}
	}
	return 0;
}
