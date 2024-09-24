#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#define O_CREATE 0x200
#define O_TRUNC  0x400
#define O_APPEND 0x800

char buf[100];

char* my_strchr(const char *str, int c) {
  while (*str) {
    if (*str == (char)c)
      return (char*)str;
    str++;
  }
  return 0;
}

int my_strncmp(const char *s1, const char *s2, int n) {
  while (n && *s1 && (*s1 == *s2)) {
    s1++;
    s2++;
    n--;
  }
  if (n == 0)
    return 0;
  return *(unsigned char *)s1 - *(unsigned char *)s2;
}

void cat(char *input){
  input += 4;
  int fd = open(input, O_RDONLY);
  if (fd < 0) {
    printf(1, "Lo siento, no he podido abrir %s :(\n", input);
    return;
  }
  int n;
  while ((n = read(fd, buf, sizeof(buf))) > 0) {
        // Escribir el contenido leído en la consola
        write(1, buf, n);
    }
}

void echo(char *input) {
  input += 5;  // Skip "echo " (4 characters + 1 for the space)

  // Check if there's a '>' for output redirection
  char *redirect = my_strchr(input, '>');
  if (redirect) {
    *redirect = 0;  // Terminate the input string before '>'
    redirect++;  // Move to the file name
    while (*redirect == ' ') redirect++;  // Skip any spaces before the file name

    // Save the original stdout
    int saved_stdout = dup(1);

    // Open the file for writing (create if it doesn't exist, append if it does)
    int fd = open(redirect, O_WRONLY | O_CREATE | O_TRUNC);
    if (fd < 0) {
      printf(1, "Lo siento, no he podido abrir %s :(\n", redirect);
      return;
    }

    // Redirect stdout to the file
    close(1);
    dup(fd);
    close(fd);

    // Print to the file
    printf(1, "%s\n", input);   //se podría hacer con un while y un write, pero sería más largo

    // Restore the original stdout
    close(1);
    dup(saved_stdout);
    close(saved_stdout);
  } else {
    printf(1, "%s\n", input);  // No redirection, print to stdout
  }
}

void wc(char *input){
  input += 3;
  int words=0;
  int newlines=0;
  int in_word=0;
  for (int i = 0; input[i] != '\0'; i++) {
    char c = input[i];

    // Count newlines
    if (c == '\n') {
      newlines++;
    }

    // Check if it's a space or newline to end a word
    if (c == ' ' || c == '\n' || c == '\t') {
      in_word = 0;  // We're outside of a word
    } else if (!in_word) {
      // We just entered a new word
      in_word = 1;
      words++;
    }
  }
  printf(1,"Saltos de línea: %d\n",newlines);
  printf(1,"Palabras: %d\n",words);
  printf(1,"Bytes: %d\n",sizeof(input));
}

void run_command(char *command) {
  while (*command == ' ') command++;

  if (my_strncmp(command, "echo ", 5) == 0) {
    echo(command);
  }
  else if (my_strncmp(command, "cat ", 4) == 0) {
    cat(command);
  }
  else if (my_strncmp(command, "wc ", 3) == 0) {
    wc(command);
  }
  else if(fork() == 0) {
    // If not echo, execute the command using exec
    char *args[2];
    args[0] = command;
    args[1] = 0;
    exec(command, args);
    printf(1, "exec failed\n");
    exit();
  } else {
    wait();
  }
}

int main(void) {
  int exit_condition=1;
  while(exit_condition) {
    printf(1, "(: ");  // Custom prompt
    memset(buf, 0, sizeof(buf));  
    gets(buf, sizeof(buf)); 

    if(buf[0] == 0)
      continue;

    // Split commands by ';'
    char *command = buf;
    while (command != 0) {
      char *next_command = my_strchr(command, ';');
      if (next_command) {
        *next_command = 0;  // Terminate the current command
        next_command++;  // Move to the next command
      }
      if (my_strncmp(command, "exit", 4) == 0) exit_condition--;
      else run_command(command);
      command = next_command;
    }
  }
  exit();
}
