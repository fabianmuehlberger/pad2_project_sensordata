

    struct dirent *de;

    DIR *pDir = opendir("..\\..\\ressources");
    if (pDir == NULL)
    {
        puts("Error, unable to read directory");
        exit(-1);
    }
    while ((de = readdir(pDir)) != NULL)
    {
        printf("Dir name %s\n", de->d_name);
    }
    closedir(pDir);
