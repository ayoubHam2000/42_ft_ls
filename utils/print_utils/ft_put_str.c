#include <unistd.h>

void  ft_put_str(int fd, const char *str)
{
  while (*str != 0)
  {
    write(fd, str, 1);
    str++;
  }
}
