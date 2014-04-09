#define STD_INPUT0        /* file descriptor for standard input */
#define STD_OUTPUT1       /* file descriptor for standard output */
pipeline(process1, process2)
char *process1, *process2;        /* pointers to program names */
{
  int fd[2];

  pipe(&fd[0]);        /* create a pipe */
  if (fork() != 0) {
    /* The parent process executes these statements. */
    close(fd[0]);      /* process 1 does not need to read from pipe */
    close(STD_OUTPUT); /* prepare for new standard output */
    dup(fd[1]);        /* set standard output to fd[1] */
    close(fd[1]);      /* this file descriptor not needed any more */
    execl(process1, process1, 0);
  } else {
    /* The child process executes these statements. */
    close(fd[1]);      /* process 2 does not need to write to pipe */
    close(STD_INPUT);  /* prepare for new standard input */
    dup(fd[0]);        /* set standard input to fd[0] */
    close(fd[0]);      /* this file descriptor not needed any more */
    execl(process2, process2, 0);
  }
}
