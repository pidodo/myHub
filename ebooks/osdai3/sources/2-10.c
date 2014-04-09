while (TRUE){                              while (TRUE) {
    while(turn != 0) /* loop* /;               while(turn != 1) /* loop* /;
    critical_region();                         critical_region();
    turn  = 1;                                 turn  = 0;
    noncritical_region();                      noncritical_region();
}                                          }
                 (a)                                        (b)

