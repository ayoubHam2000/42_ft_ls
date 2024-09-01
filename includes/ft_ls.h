#ifndef FT_LS
#define FT_LS

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <dirent.h>

#include <grp.h>
#include <time.h>
#include <errno.h>
#include <sys/time.h>

typedef struct s_config
{
  int list;
  int show_hidden;
  int reverse;
  int sort_time;
  int recursive;
} t_config;

typedef struct s_content
{
  time_t  m_time;
  char    *name;
  size_t  st_size;
  int     st_nlink;
  mode_t  st_mode;
  char    *pw_name;
  char    *gr_name;
} t_content;

#endif
