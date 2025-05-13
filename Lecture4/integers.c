#include <stdio.h>
#include <stdlib.h>

// RPC structure for a request
struct request
{
	int	req_seq;	/* sequence number */
	int	req_command;	/* command to execute */
	int	req_nargs;	/* number of RPC arguments */
	int	req_args[];	/* RPC argument values */
};

void handle_request(struct request*);

void handle_rpcs(FILE *input, int n)
{
	struct request *buffer = malloc(n * sizeof(struct request));

	// First read the full batch of requests from the remote end
	for (int i = 0; i < n; i++)
	{
		fread(buffer, sizeof(struct request), n, input);
	}

	printf("received %d requests", n);

	// Then handle the individual commands
	for (int i = 0; i < n; i++)
	{
		printf("handling request %d...", i);
		handle_request(buffer + i);
	}
}