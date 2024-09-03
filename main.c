#include <ft_ls.h>
#include <linked_list.h>
#include <string.h>
#include <unistd.h>

int main(int ac, char **av)
{
  t_list    *paths;
  t_config  config;

  paths = l_init();
  set_config(paths, &config, ac, av);
  ft_ls(paths, &config);
  l_clear(paths, NULL);
  free(paths);
  return 0;
}
