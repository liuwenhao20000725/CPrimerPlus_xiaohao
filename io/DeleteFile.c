////
//// Created by xiaohao on 2021/3/12.
////
//#include<stdio.h>
//#include<string.h>
//#include<fcntl.h>
//#include<sys/stat.h>
//#include<dirent.h>
//
//int i, isr = 0, isf = 0, isv = 0;
//
//void startdel(char *name, int isv) {
//    struct stat st;
//    stat(name, &st);
//    if (S_ISDIR(st.st_mode)) {
//        DIR *fp = opendir(name);
//        if (fp != NULL) {
//            struct dirent *p;
//            char filename[256];
//            while ((p = readdir(fp)) != NULL) {
//                if (strcmp(p->d_name, ".") == 0 || strcmp(p->d_name, "..") == 0)
//                    continue;
//                sprintf(filename, "%s/%s", name, p->d_name);
//                startdel(filename, isv);
//            }
//        }
//        closedir(fp);
//        rmdir(name);
//    } else
//        unlink(name);
//    if (isv)printf("dev %s\n", name);
//}
//
//char *isenbledel(char *name) {
//    static char filename[256];
//    memset(filename, 0, 256);
//    if (name == NULL || strcmp(name, "") == 0)
//        return NULL;
//    else if (name[0] != '.')
//        sprintf(filename, "./%s", name);
//    else if (name[1] != '/') {
//        if (name[2] == '/')
//            sprintf(filename, "%s", name);
//        else
//            sprintf(filename, "./%s", name);
//    } else
//        sprintf(filename, "%s", name);
//    return filename;
//}
//
//int main(int argc, char **argv) {
//    char **ls = NULL;
//    for (i = 1; i < argc; i++) {
//        if (argv[i][0] == '-') {
//            isf = strstr(argv[i], "f") ? 1 : 0;
//            isr = strstr(argv[i], "r") ? 1 : 0;
//            isv = strstr(argv[i], "v") ? 1 : 0;
//        } else {
//            ls = &argv[i];
//            break;
//        }
//    }
//    i = 0;
//    char cmd[256];
//    while (ls[i] != NULL) {
//        char *pathname = isenbledel(ls[i++]);
//        if (pathname == NULL)
//            continue;
//        if (isf == 0) {
//            printf("delete no[yes]\n");
//            scanf("%s", cmd);
//            if (strcmp(cmd, "yes") != 0)
//                continue;
//        }
//        if (isr == 0) {
//            struct stat st;
//            stat(pathname, &st);
//            if (S_ISDIR(st.st_mode)) {
//                printf("dir isn't deleted\n");
//                continue;
//            }
//        }
//        startdel(pathname, isv);
//    }
//}
