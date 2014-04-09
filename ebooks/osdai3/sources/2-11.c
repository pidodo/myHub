#define FALSE 0
#define TRUE  1
#define N     2                /* number of processes */

int turn;                      /* whose turn is it? */
int interested[N];             /* all values initially 0 (FALSE)*/
void enter_region(int process) /* process is 0 or 1 */
{
  int other;                   /* number of the other process */
  other = 1 - process;         /* the opposite of process */
  interested[process] = TRUE;  /* show that you are interested */
  turn = process;              /* set flag */
  while (turn == process && interested[other] == TRUE) /* null statement */;
}
void leave_region(int process)  /* process: who is leaving */
{
  interested[process] = FALSE;  /* indicate departure from critical region */
}

