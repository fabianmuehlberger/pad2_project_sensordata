#include <stdio.h>
#include <stdlib.h>

static inline unsigned int getuint(const char *p, const char **pp) {
    unsigned int d, n = 0;
    while ((d = *p - '0') <= 9) {
        n = n * 10 + d;
        p++;
    }
    *pp = p;
    return n;
}

int csvgrep(FILE *f, int method) {
    struct {
        int a, b, c, d;
        int spos, slen;
        char s[1000];
    } c;
    int count = 0, line = 0;

    // select 500 out of 43M
#define select(c)  ((c).a == 100 && (c).b == 100 && (c).c > 74 && (c).d > 50)

    if (method == 0) {
        // default method: fscanf
        while (fscanf(f, "%d,%d,%d,%999[^,],%d\n", &c.a, &c.b, &c.c, c.s, &c.d) == 5) {
            line++;
            if (select(c)) {
                count++;
                printf("%d,%d,%d,%s,%d\n", c.a, c.b, c.c, c.s, c.d);
            }
        }
    } else
    if (method == 1) {
        // use fgets and simple parser
        char buf[1024];
        while (fgets(buf, sizeof(buf), f)) {
            char *p = buf;
            int i;
            line++;
            c.a = strtol(p, &p, 10);
            p += (*p == ',');
            c.b = strtol(p, &p, 10);
            p += (*p == ',');
            c.c = strtol(p, &p, 10);
            p += (*p == ',');
            for (i = 0; *p && *p != ','; p++) {
                c.s[i++] = *p;
            }
            c.s[i] = '\0';
            p += (*p == ',');
            c.d = strtol(p, &p, 10);
            if (*p != '\n') {
                fprintf(stderr, "csvgrep: invalid format at line %d\n", line);
                continue;
            }
            if (select(c)) {
                count++;
                printf("%d,%d,%d,%s,%d\n", c.a, c.b, c.c, c.s, c.d);
            }
        }
    } else
    if (method == 2) {
        // use fgets and hand coded parser, positive numbers only, no string copy
        char buf[1024];
        while (fgets(buf, sizeof(buf), f)) {
            const char *p = buf;
            line++;
            c.a = getuint(p, &p);
            p += (*p == ',');
            c.b = getuint(p, &p);
            p += (*p == ',');
            c.c = getuint(p, &p);
            p += (*p == ',');
            c.spos = p - buf;
            while (*p && *p != ',') p++;
            c.slen = p - buf - c.spos;
            p += (*p == ',');
            c.d = getuint(p, &p);
            if (*p != '\n') {
                fprintf(stderr, "csvgrep: invalid format at line %d\n", line);
                continue;
            }
            if (select(c)) {
                count++;
                printf("%d,%d,%d,%.*s,%d\n", c.a, c.b, c.c, c.slen, buf + c.spos, c.d);
            }
        }
    } else {
        fprintf(stderr, "csvgrep: unknown method: %d\n", method);
        return 1;
    }
    fprintf(stderr, "csvgrep: %d records selected from %d lines\n", count, line);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc > 2 && strtol(argv[2], NULL, 0)) {
        // non zero second argument -> set a 1M I/O buffer
        setvbuf(stdin, NULL, _IOFBF, 1024 * 1024);
    }
    return csvgrep(stdin, argc > 1 ? strtol(argv[1], NULL, 0) : 0);
}