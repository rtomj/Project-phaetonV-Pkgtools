/*
 * pkg: front end for SVR4 packaging tools
 *
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
//#include "pkg.h"

/* could move to a 'pkg.conf' */
#define PKG_ADD "/usr/5bin/pkgadd -d"
#define PKG_RM "/usr/5bin/pkgrm"
#define PKG_PROTO "/usr/5bin/pkgproto"
#define PKG_TRANS "/usr/5bin/pkgtrans"
#define PKG_LOC "/var/spool/pkg/"
#define PKG_INFO "/usr/5bin/pkginfo"

int num(void) {
    int n;
    n = system("ls "PKG_LOC" | grep pkg | wc -l");
    return n;
}

void usage(void) {
    printf("\nusage: pkg search|install|update|remove|delete|sync|list|env|cache|help \n\n"
            "\tsearch  - searches the repository for an SVR4 package install - installs SVR4 package \n"
            "\t\t How to implement search function?\n"
            "\tbuild   - build a package in /usr/ports and create an SVR4 package in cache\n"
            "\t\t write pkgbuild (an sh scipt) instead...\n"
            "\tinstall - installs a package from repo or cache\n"
            "\tupdate  - update packages \n"
            "\tremove  - uninstalls a package but does not delete it from cache \n"
            "\tdelete  - clears the cache \n"
            "\tverify  - gets sha256 of pkg\n"
            "\tsync    - sync with repository \n"
            "\tlist    - list all installed packages \n"
            "\tcache   - list all contents of cache \n"
            "\tenv     - outputs pkg environment, package cache location \n"
            "\thelp    - outputs this message \n\n");
}

void envir(void) {
    printf("\nNo. of Stream Packages (*.pkg) in cache: \n"
            "Package cache:                     "PKG_LOC"\n"
            "SVR4 package tools:                "PKG_ADD"\n"
            "                                   "PKG_RM"\n"
            "                                   "PKG_PROTO"\n"
            "                                   "PKG_TRANS"\n");
}

void list(void) {
    DIR *d;
    struct dirent *dir;
    d = opendir(""PKG_LOC"");
    if (d) {
        while ((dir= readdir(d)) != NULL) {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    }
}

int main(int argc, char **argv)
{
    char* cmd;
    char* str;
    size_t len;

    if (argc < 2) {
        usage();
        exit(1);
    }
    if (argc >= 2) {
        if (strcmp (argv[1], "install") == 0) {
            str = argv[2];
            len = ((size_t)snprintf(NULL, 0, ""PKG_ADD" "PKG_LOC"%s-*.pkg", str) + 1);
            cmd = malloc(len);

            snprintf(cmd, len, ""PKG_ADD" "PKG_LOC"%s-*.pkg", str);
            system(cmd);
            free(cmd);
        } else if (strcmp (argv[1], "remove") == 0) {
            str = argv[2];
            len = ((size_t)snprintf(NULL, 0, ""PKG_RM" %s", str) + 1);
            cmd = malloc(len);

            snprintf(cmd, len, ""PKG_RM" %s", str);
            system(cmd);
            free(cmd);
        } else if (strcmp (argv[1], "list") == 0) {
            system(""PKG_INFO"");
        } else if (strcmp (argv[1], "cache") == 0) {
            list();
        } else {
            printf("pkg: %s: command not found\n", argv[1]);
        }
    }
    return 0;
}
