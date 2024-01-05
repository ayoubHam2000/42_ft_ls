#include <ft_ls.h>
#include <linked_list.h>
#include <string.h>

void list_sort_time(t_list *list) {
    if (list->len < 2) {
        return;
    }

    int swapped;
    t_node *ptr;
    t_node *last_ptr = NULL;

    do {
        swapped = 0;
        ptr = list->head;

        while (ptr->next != last_ptr) {
            t_content *data1 = (t_content *)ptr->p;
            t_content *data2 = (t_content *)ptr->next->p;

            if (data1->m_time < data2->m_time) {
                void *temp = ptr->p;
                ptr->p = ptr->next->p;
                ptr->next->p = temp;

                swapped = 1;
            }
            ptr = ptr->next;
        }
        last_ptr = ptr;

    } while (swapped);
}

void list_reverse(t_list *list) {
    if (list->head == NULL || list->len < 2) {
        return;
    }

    t_node *prev = NULL;
    t_node *current = list->head;
    t_node *next = NULL;
    list->last = list->head;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;    
        current = next;
    }

    list->head = prev;
}

char* pathJoin(const char *path, const char *name){
  size_t pathLen = strlen(path);
  size_t nameLen = strlen(name);
  char *newPath = malloc(pathLen + nameLen + 2);
  if (newPath == NULL) {
    exit(1);
  }
  strcpy(newPath, path);
  strncat(newPath, "/", 1);
  strncat(newPath, name, nameLen);
  return (newPath);
}



t_list  *list_directory(char *path, t_config *config)
{
  t_list    *res;
  t_content *content;
  struct dirent *de;
  struct stat file_stat;
  struct passwd *pw;
  struct group *gr;

  DIR *dr = opendir(path);
  if (dr == NULL)
  {
    printf("Could not open directory: %s\n", path);
    return (NULL);
  }
  
  res = l_init();
  if (res == NULL)
    exit(1);
  
  while ((de = readdir(dr)) != NULL) {
    if (config->show_hidden == 0 && de->d_name[0] == '.')
    {
      continue;
    }

    char *file_path = pathJoin(path, de->d_name);
    if (lstat(file_path, &file_stat) == -1) {
      printf("%s ->\n", file_path);
      perror("stat: ");
      continue;
    }

    pw = getpwuid(file_stat.st_uid);
    if (pw == NULL) {
      perror("pwuid: ");
      continue;
    }
    gr = getgrgid(file_stat.st_gid);
    if (gr == NULL) {
      perror("grgid: ");
      continue;
    }
      
    

    content = malloc(sizeof(t_content));
    if (content == NULL)
    {
      printf("Memory\n");
      exit(1);
    }
    content->name = strdup(de->d_name);
    content->st_size = file_stat.st_size;
    content->st_nlink = file_stat.st_nlink;
    content->pw_name = strdup(pw->pw_name);
    content->gr_name = strdup(gr->gr_name);
    content->m_time = file_stat.st_mtime;
    content->st_mode = file_stat.st_mode;
    res->nb_blocks += file_stat.st_blocks;


    if (l_append_end(res, content) == 0)
      exit(1);
  }

  if (config->sort_time == 1)
    list_sort_time(res);
  if (config->reverse == 1)
    list_reverse(res);
  

  closedir(dr);

  return (res);
}

void print_permissions(mode_t mode) {
    char permissions[11] = "----------";
    
    // File type
    if (S_ISREG(mode)) permissions[0] = '-';
    else if (S_ISDIR(mode)) permissions[0] = 'd';
    else if (S_ISLNK(mode)) permissions[0] = 'l';
    else if (S_ISBLK(mode)) permissions[0] = 'b';
    else if (S_ISCHR(mode)) permissions[0] = 'c';
    else if (S_ISFIFO(mode)) permissions[0] = 'p';
    else if (S_ISSOCK(mode)) permissions[0] = 's';
    
    // Owner permissions
    if (mode & S_IRUSR) permissions[1] = 'r';
    if (mode & S_IWUSR) permissions[2] = 'w';
    if (mode & S_IXUSR) permissions[3] = 'x';
    
    // Group permissions
    if (mode & S_IRGRP) permissions[4] = 'r';
    if (mode & S_IWGRP) permissions[5] = 'w';
    if (mode & S_IXGRP) permissions[6] = 'x';
    
    // Other permissions
    if (mode & S_IROTH) permissions[7] = 'r';
    if (mode & S_IWOTH) permissions[8] = 'w';
    if (mode & S_IXOTH) permissions[9] = 'x';
    
    printf("%s ", permissions);
}

// 1725030160
// 1725051040

// 1725051096

void  print_list(t_list *list, t_config *config)
{
  t_node  *node;
  char *formatted_time;

  node = list->head;
  while (node != NULL)
  {
    t_content *content = (t_content *)(node->p);
    if (config->show_hidden != 0 || content->name[0] != '.')
    {
      if (config->list == 1)
      {
        print_permissions(content->st_mode);
        printf("%3d ", content->st_nlink);
        printf("%-8s %-8s ", content->pw_name, content->gr_name);
        printf("%8ld ", content->st_size);

        //printf("->%ld ", content->m_time);
        //time(&content->m_time);
        //printf("->%ld ", content->m_time);
        formatted_time = ctime(&(content->m_time));


        printf("%.6s %.5s\t", formatted_time + 4, formatted_time + 11);
        printf("%s\n", content->name);
      }
      else
      {
        printf("%s", content->name);
        if (node->next != NULL)
          printf(" ");
        else
          printf("\n");
      }
    }
    node = node->next;
  }
}



void	recursive_listing(const char *path, t_config *config){
  DIR* dir = opendir(path);

  if (dir == NULL)
  {
    printf("Can't open\n");
  }
  else
  {
    struct dirent* entry;
    entry = readdir(dir);
    while (entry)
    {
      char *filePath = pathJoin(path, entry->d_name);
      if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
      {
        if (config->show_hidden != 0 || entry->d_name[0] != '.')
        {
          t_list *list_dir = list_directory(filePath, config);
          if (list_dir != NULL)
          {
            printf("%s:\n", filePath);
            print_list(list_dir, config);
            recursive_listing(filePath, config);
          }
        }
      }
      entry = readdir(dir);
    }
    closedir(dir);
  }
}


int main(int ac, char **av)
{
  t_list    *paths;
  char      *path;
  t_config  config;
  int i;
  int j;

  paths = l_init();
  if (paths == NULL)
    exit(1);

  config.list = 0;
  config.show_hidden = 0;
  config.reverse = 0;
  config.sort_time = 0;
  config.recursive = 0;

  i = 1;
  while (i < ac)
  {
    if (av[i][0] == '-')
    {
      j = 1;
      while (av[i][j] != 0)
      {
        if (av[i][j] == 'l')
          config.list = 1;
        else if (av[i][j] == 'a')
          config.show_hidden = 1;
        else if (av[i][j] == 'r')
          config.reverse = 1;
        else if (av[i][j] == 't')
          config.sort_time = 1;
        else if (av[i][j] == 'R')
          config.recursive = 1;
        else {
          printf("ls: invalid option -- '%c'\n", av[i][j]);
          exit(1);
        }
        j++;
      }
    }
    else
    {
      DIR* dir = opendir(av[i]);
      if (dir == NULL)
      {
        printf("ls: cannot open directory %s\n", av[i]);
      }
      else 
      {
        if (l_append_end(paths, av[i]) == 0)
          exit(1);
      }
    }
    i++;
  }

  // printf("config.list = %d\n", config.list);
  // printf("config.show_hidden = %d\n", config.show_hidden);
  // printf("config.reverse = %d\n", config.reverse);
  // printf("config.sort_time = %d\n", config.sort_time);
  // printf("config.recursive = %d\n", config.recursive);


  if (paths->len == 0) {
    if (l_append_end(paths, ".") == 0)
      exit(1);
  }


  t_node  *node = paths->head;
  while (node != NULL)
  {
    path = (char *)(node->p);
    //printf("%s\n", path);
    if (config.recursive == 1)
    {
      printf("%s:\n", path);
      t_list *list_dir = list_directory(path, &config);
      if (list_dir != NULL)
      {
        print_list(list_dir, &config);
      }
      recursive_listing(path, &config);
    } else if (paths->len > 1) {
      printf("%s:\n", path);
      t_list *list_dir = list_directory(path, &config);
      if (list_dir != NULL)
      {
        print_list(list_dir, &config);
      }
    }
    else {
      t_list *list_dir = list_directory(path, &config);
      if (list_dir != NULL)
      {
        if (config.list == 1)
          printf("total: %ld\n", list_dir->nb_blocks / 2);
        print_list(list_dir, &config);
      }
    }
    node = node->next;
  }

  return 0;
}
