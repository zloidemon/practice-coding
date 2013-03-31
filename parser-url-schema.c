/**
 * Simple URL schema parser
 * @author Veniamin Gvozdikov <g.veniamin@googlemail.com>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Cleaner struct elemets which free memory
 * @param address pointer to element of URL struct
 * @param param pointer to name element for output
 */
#define CLEAN_struct(address, param)			\
	if (NULL != address) {				\
		printf("\t%s: %s\n", param, address);	\
		free((void *)address);			\
		address = NULL;				\
		}

/**
 * @brief Structure URL
 * <schema>://<login>:<password>@<host>:<port>/....
 */
typedef struct {
	char *schema;
	char *login;
	char *password;
	char *host;
	char *port;
} URL;

/**
 * @brief Allocation memory for parsed chunk
 * @param string pointer to parsed chunk of string
 * @return pointer to string if success or exit if fail
 */
char *
alloc_line(char *string, int size)
{
	static char *buf;
	buf = malloc(sizeof(char) * size);
	if (NULL != buf) {
		memcpy((void *)buf, (void *)string, size);
		buf[size] = '\0';
		return buf;
	} else {
		printf("Could not allocate memory.\n");
		exit(1);
//		return NULL;
	}
}

/**
 * @brief Parsing chang with ':'(colon)
 * @param string pointer to chunk of string
 * @param result1 pointer to pointer URL struct
 * @param result2 pointer to pointer URL struct
 * @param size lenght parsed string
 * @return 0 if success or 1 if fail
 */
int
parse_colon(char *string, char **result1, char **result2, int size)
{
	static char *buf;
	int counter = 0, sub_counter = 0;
	while (size > 0 && '\0' != *string) {
		if (counter > 0 && sub_counter == 0 && ':' == *string) {
			buf = alloc_line(string-counter, counter); ++string;
			*result1 = buf;
			counter = 0;
			++sub_counter;
		} else if (counter == 0 && ':' == *string) {
			return 1;
		} else {
			++string && ++counter;
		}
		--size;
	}

	buf = alloc_line(string-counter, counter); ++string;

	if (NULL == *result1) { 
		*result1 = buf;
	} else {
		*result2 = buf;
	}
	if (NULL == *result1) {
		return 1;
	} else {
		return 0;
	}
}

/**
 * @brief Parser string without schema chunk
 * @param url pointer to URL struct
 * @param string pointer to pointer string without schema 
 * @param counter number last element '/' or '@' in string
 * @return 0 if success or 1 if fail
 */
int
parse_line(URL *url, char **string, int counter)
{
	static char *buf, *left, *right;
	int left_size, right_size;
	
	if ('/' == **string)
	{
		buf = alloc_line(*string-counter, counter); ++(*string);
		if (parse_colon(buf, &url->host, &url->port, counter) != 0) {
			printf("Error parsing %s.\n", buf);
			return 1;
		} else {
			return 0;
		}
	} else {
		(*string) -= counter;
		counter = 0;
	}
	
	while ('\0' != **string) {
		if ('@' == **string) {
			buf = alloc_line(*string-counter, counter); ++(*string);
			left = buf;
			left_size = counter;
			counter = 0;
		} else if ('/' == **string) {
			buf = alloc_line(*string-counter, counter); ++(*string);
			right = buf;
			right_size = counter;
			counter = 0;
		} else {
			++(*string) && ++counter;
		}
	}

	if (parse_colon(left, &url->login, &url->password, left_size) != 0) {
		printf("Error parsing %s.\n", left);
		return 1;
	}
	if (parse_colon(right, &url->host, &url->port, right_size) != 0) {
		printf("Error parsing %s.\n", right);
		return 1;
	}
	return 0;
}

/**
 * @brief Check schema in string and save it
 * @param url pointer to pointer URL struct
 * @param string pointer to pointer string
 * @param counter nober of position in string from parse_url()
 * @return 0 if success 1 if fail
 */
int
parse_schema(URL **url, char **string, int counter)
{
	int sub_counter = 0;
	static char *buf;

	while ('\0' != **string && '@' != **string) {
		if (sub_counter == 2 && '/' == **string) {
			(*string) -= counter;
			++sub_counter;
			buf = alloc_line(*string, (counter - sub_counter + 1));

			if (NULL != buf) {
				(*url)->schema = buf;
				(*string) += (counter + 1);
				return 0;
			} else {
				return 1;
			}
		} else if ( '/' == **string || ':' == **string) {
			++sub_counter;
		} else {
			sub_counter = 0;
		}
		++counter && ++(*string);
	}
	return 1;
}

/**
 * @brief Function which split string to chunks
 * @param url pointer to URL struct
 * @param string pointer to string which will splitting
 * @return 0 if success 1 if fail
 */
int
parse_url(URL *url, char *string)
{
	int  counter = 0;
	while ('\0' != *string) {
		if (NULL == url->schema) {
			if (1 == parse_schema(&url, &string, counter)) {
				printf("Error parsing schema.\n");
				return 1;
			}
			counter = 0;
		} else {
			switch (*string) {
				case '@':
				case '/':
				{
					if (1 == parse_line(url, &string, counter)) {
						printf("Error parsing.\n");
						return 1;
					}		
					counter = 0;
					break;
				}
				default: {
					++counter && ++string;
				}
			}
		}
	}
	return 0;
}

/**
 *  @brief Function which starting parsing and cleaning url struct 
 *  @param url pointer to URL struct
 *  @param string pointer to string
 */
void
show_result(URL *url, char *string)
{
	printf("string: %s\n", string);

	if (parse_url(url, string) == 1) {
		printf("Error parsing: %s.\n", string);
	}

	CLEAN_struct(url->schema,   "schema");
	CLEAN_struct(url->login,    "login");
	CLEAN_struct(url->password, "password");
	CLEAN_struct(url->host,     "host");
	CLEAN_struct(url->port	,   "port");
}

int
main(void)
{
	static URL url;

	int   counter = 0;
	char *strings[] = {
		"tftp://ololol@mail.com/sdf",
		"ftp://example.com/sdf",
		"ftp://root:qwerty@localhost:22/sdf",
		"mtp://met@test.xxx:24/mx",
		"mtp2://ololo@tp.xxx:33/tt",
		"http://google.com/",
		"xxx://mymy.com:14/",
		NULL
	};
	while (strings[counter] != NULL) {
		show_result(&url, strings[counter]);
		++counter;
	}

	return 0;
}
