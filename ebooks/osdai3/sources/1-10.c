#define TRUE 1

while (TRUE){         /* repeat forever */
  type_prompt();      /* display prompt on the screen */
  read_command(command, parameters);  /* read input from terminal */

  if (fork() != 0){   /* fork off child process */
    /* Parent code. */
    waitpid(1, &status, 0);  /* wait for child to exit */
  } else {
    /* Child code. */
    execve(command, parameters, 0);  /* execute command */
  }
 }
