/**
 * External strstr function.
 *
 * @author Veniamin Gvozdikov <g.veniamin@googlemail.com>
 */
#include <stdio.h>

/**
 * @param line Full line
 * @param chunk Chunk which need find in line
 * @return similiar strstr
 */
char * strext(char *, char *);

int main(void)
{
	printf("%s\n", strext("s", "s") ? : "NULL");
	printf("%s\n", strext("ssdf", "sd") ? : "NULL");
	printf("%s\n", strext("TExt 1123x TExt", "12") ? : "NULL");
	printf("%s\n", strext("123x", "12") ? : "NULL");
	printf("%s\n", strext("111x", "11x") ? : "NULL");
	printf("%s\n", strext("121212x", "1212x") ? : "NULL");
	printf("%s\n", strext("121212x 121212x", "12x") ? : "NULL");
	printf("%s\n", strext("1212132x 121212x", "12x") ? : "NULL");
	printf("%s\n", strext("132x 11212x 1212x", "12x") ? : "NULL");
	printf("%s\n", strext("incorrect", "12x") ? : "incorrect");
	printf("%s\n", strext("incorrect", "") ? : "incorrect");
	printf("%s\n", strext("", "test") ? : "incorrect");
	printf("%s\n", strext(NULL, "test") ? : "incorrect");

	return 0;
}

char *
strext(char *line, char *chunk)
{
	if ((chunk == NULL) || (*chunk == '\0')) {
		return line;
	} else if ((line == NULL) || (*line == '\0')) {
		return NULL;
	}

	int iter = 0;
	while(*line != '\0') {
		if (chunk[iter] == '\0') {
			return (line -= iter);
		} else {
			if (*line == chunk[iter]) { 
				++iter;
			} else {
				line -= iter; iter = 0;
			}
		}
		++line;
	}

	if (iter > 0) {
		return (line -= iter);
	} else {
		return NULL;
	}
}
