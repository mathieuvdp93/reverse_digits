#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int32_t validate_user_input(void);
int32_t reverse_user_input_modulo(int32_t);
void empty_input_stream(void);

int main(void) {

  int32_t user_input;
  int32_t reversed_user_input;

  user_input = validate_user_input();
  reversed_user_input = reverse_user_input_modulo(user_input);

  printf("%d\n", reversed_user_input);

  return 0;
}

int32_t validate_user_input() {

  long result;
  char buf[4];
  int success = 0;

  do {
    printf("Enter a two digit number: ");
    if (!(fgets(buf, sizeof buf, stdin))) {
      printf("Reading input failed\n");
      exit(1);
    }
    /*
int c;
if ((c = fgetc(stdin)) != EOF && c != '\n') {
printf("input not fully converted\n");
empty_input_stream();
continue;
}
    */
    if (strchr(buf, '\n') == NULL) {
      printf("input not fully converted\n");
      empty_input_stream();
      continue;
    }

    char *endptr;
    errno = 0;
    result = strtol(buf, &endptr, 10);

    if (errno == ERANGE) {
      printf("number was to big or small for type long\n");
      success = 0;
    } else if (result < INT_MIN || result > INT_MAX) {
      printf("input to big or small for int\n");
      success = 0;
    } else if (buf == endptr) {
      printf("no valid input detected\n");
      success = 0;
    } else if (*endptr && *endptr != '\n') {
      printf("input was not fully converted\n");
      success = 0;
    } else {
      success = 1;
    }
  } while (success == 0);

  return (int32_t)result;
}

void empty_input_stream() {

  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
    ;
  }
}

int32_t reverse_user_input_modulo(int32_t user_input) {

  int8_t first_digit;
  int8_t second_digit;

  first_digit = user_input % 10;
  second_digit = user_input / 10;

  int32_t result = first_digit * 10 + second_digit;

  return result;
}
