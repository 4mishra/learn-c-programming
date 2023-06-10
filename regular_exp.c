#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage %s <pattern> <string>\n", argv[0]);
    exit(EXIT_FAILURE);

  }
    regex_t regex;
    int ret;

    char *pattern = argv[1];  // The regular expression pattern
    char *string = argv[2];     // The string to match

    // Compile the regular expression pattern
    ret = regcomp(&regex, pattern, 0);
    if (ret) {
        fprintf(stderr, "Could not compile regex\n");
        exit(EXIT_FAILURE);
    }

    // Match the regular expression against the string
    ret = regexec(&regex, string, 0, NULL, 0);
    if (!ret) {
        printf("Match found\n");
    } else if (ret == REG_NOMATCH) {
        printf("No match found\n");
    } else {
        char error_msg[100];
        regerror(ret, &regex, error_msg, sizeof(error_msg));
        fprintf(stderr, "Regex match failed: %s\n", error_msg);
        exit(EXIT_FAILURE);
    }

    // Free the compiled regular expression
    regfree(&regex);

    return 0;
}
