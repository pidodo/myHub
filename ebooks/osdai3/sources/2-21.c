typedef int semaphore;           /* use your imagination */
semaphore mutex = 1;             /* controls access to 'rc' */
semaphore db = 1;                /* controls access to the database */
int rc = 0;                      /* # of processes reading or wanting to */

void reader(void)
{
  while (TRUE){                      /* repeat forever */
    down(&mutex);                /* get exclusive access to 'rc' */
    rc = rc + 1;                 /* one reader more now */
    if (rc == 1) down(&db);      /* if this is the first reader ... */
    up(&mutex);                  /* release exclusive access to 'rc' */
    read_data_base();            /* access the data */
    down(&mutex);                /* get exclusive access to 'rc' */
    rc = rc  1;                  /* one reader fewer now */
    if (rc == 0) up(&db);        /* if this is the last reader ... */
    up(&mutex);                  /* release exclusive access to 'rc' */
    use_data_read();             /* noncritical region */
  }
}


void writer(void)
{
  while (TRUE){                      /* repeat forever */
    think_up_data();              /* noncritical region */
    down(&db);                    /* get exclusive access */
    write_data_base();            /* update the data */
    up(&db);                      /* release exclusive access */
  }
}

