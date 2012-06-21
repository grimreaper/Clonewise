#include <cstdlib>
#include <cstdio>
#include <cstring>

struct Command {
	const char *name;
	int (*main)(int argc, char *argv[]);
};


int Clonewise_query(int argc, char *argv[]);
int Clonewise_query_cache(int argc, char *argv[]);
int Clonewise_make_cache(int argc, char *argv[]);

Command commands[] = {
	{ "query", Clonewise_query },
	{ "query-cache", Clonewise_query_cache },
	{ "make-cache", Clonewise_make_cache },
	{ NULL, NULL },
};

static void
Usage(const char *argv0)
{
	fprintf(stderr, "Usage: %s command [args ...]\n", argv0);
	fprintf(stderr, "Commands:\n");
	for (int i = 0; commands[i].main; i++) {
		fprintf(stderr, "\t%s\n", commands[i].name);
	}
	exit(0);
}

int
main(int argc, char *argv[])
{
	if (argc < 2) {
		Usage(argv[0]);
	}
	for (int i = 0; commands[i].main; i++) {
		if (strcmp(argv[1], commands[i].name) == 0) {
			exit(commands[i].main(argc - 1, &argv[1]));
		}
	}
	Usage(argv[0]);
}
