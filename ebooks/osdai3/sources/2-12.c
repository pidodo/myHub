enter_region:
TSL REGISTER,LOCK       |copy LOCK to register and set LOCK to 1
  CMP REGISTER,#0         |was LOCK zero?
  JNE ENTER_REGION        |if it was non zero, LOCK was set, so loop
  RET                     |return to caller; critical region entered


  leave_region:
MOVE LOCK,#0             |store a 0 in LOCK
       RET                      |return to caller
