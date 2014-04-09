struct stat{
  short st_dev;            /* device where i-node belongs */
  unsigned short st_ino;   /* i-node number */
  unsigned short st_mode;  /* mode word */
  short st_nlink;          /* number of links */
  short st_uid;            /* user id */
  short st_gid;            /* group id */
  short st_rdev;           /* major/minor device for special files */
  long st_size;            /* file size */
  long st_atime;           /* time of last access */
  long st_mtime;           /* time of last modification */
  long st_ctime;           /* time of last change to i-node */
};
