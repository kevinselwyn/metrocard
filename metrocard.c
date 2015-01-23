#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static double fare = 2.75;
static double bonus = 0.11;
static double minimum = 5.50;
static double maximum = 20.00;
static double threshold = 0.05;
static double increment = 0.05;

static void usage(char *exec) {
	int length = 0;

	length = (int)strlen(exec);

	printf("%s [-o|--old] [-f|--fare <fare>] [-b|--bonus <bonus>]\n", exec);
	printf("%*s [-m|--minimum <minimum>] [-M|--maximum <maximum>]\n", length, " ");
	printf("%*s [-t|--threshold <threshold>] [-i|--increment <increment>]\n", length, " ");
	printf("%*s [-h|--help]\n", length, " ");

	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
	int i = 0, j = 0;
	double k = 0.0, l = 0.0;
	double rides = 0.0, you_pay = 0.0, on_card = 0.0, remainder = 0.0;
	char *exec = NULL, *action = NULL;

	exec = argv[0];

	for (i = 1, j = argc; i < j; i++) {
		action = argv[i];

		if (strcmp(action, "-o") == 0 || strcmp(action, "--old") == 0) {
			fare = 2.50;
			bonus = 0.05;
			minimum = fare;
		} else if (strcmp(action, "-f") == 0 || strcmp(action, "--fare") == 0) {
			fare = atof(argv[++i]);
		} else if (strcmp(action, "-b") == 0 || strcmp(action, "--bonus") == 0) {
			bonus = atof(argv[++i]);
		} else if (strcmp(action, "-m") == 0 || strcmp(action, "--minimum") == 0) {
			minimum = atof(argv[++i]);
		} else if (strcmp(action, "-M") == 0 || strcmp(action, "--maximum") == 0) {
			maximum = atof(argv[++i]);
		} else if (strcmp(action, "-t") == 0 || strcmp(action, "--threshold") == 0) {
			threshold = atof(argv[++i]);
		} else if (strcmp(action, "-i") == 0 || strcmp(action, "--increment") == 0) {
			increment = atof(argv[++i]);
		} else if (strcmp(action, "-h") == 0 || strcmp(action, "--help") == 0) {
			usage(exec);
		} else {
			printf("Invalid action: %s\n", action);
			break;
		}
	}

	printf("# Rides | You Pay | On Card | Remainder\n");
	printf("--------+---------+---------+----------\n");

	for (k = minimum, l = maximum; k <= l; k += increment) {
		you_pay = k;
		on_card = k * (bonus + 1.0);
		rides = floor(on_card / fare);
		remainder = on_card - (rides * fare);

		if (remainder <= threshold) {
			printf("%7.0f |  $%5.2f |  $%5.2f | $%5.2f\n", rides, you_pay, on_card, remainder);
		}
	}

	return 0;
}