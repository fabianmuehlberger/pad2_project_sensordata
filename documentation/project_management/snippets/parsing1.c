#include <stdio.h>
#include <stdlib.h>

const char *dict[] = {
    "Lorem", "ipsum", "dolor", "sit", "amet;", "consectetur", "adipiscing", "elit;",
    "sed", "do", "eiusmod", "tempor", "incididunt", "ut", "labore", "et",
    "dolore", "magna", "aliqua.", "Ut", "enim", "ad", "minim", "veniam;",
    "quis", "nostrud", "exercitation", "ullamco", "laboris", "nisi", "ut", "aliquip",
    "ex", "ea", "commodo", "consequat.", "Duis", "aute", "irure", "dolor",
    "in", "reprehenderit", "in", "voluptate", "velit", "esse", "cillum", "dolore",
    "eu", "fugiat", "nulla", "pariatur.", "Excepteur", "sint", "occaecat", "cupidatat",
    "non", "proident;", "sunt", "in", "culpa", "qui", "officia", "deserunt",
    "mollit", "anim", "id", "est", "laborum.",
};

int csvgen(const char *fmt, long lines) {
    char buf[1024];

    if (*fmt == '\0')
        return 1;

    while (lines > 0) {
        size_t pos = 0;
        int count = 0;
        for (const char *p = fmt; *p && pos < sizeof(buf); p++) {
            switch (*p) {
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                count = count * 10 + *p - '0';
                continue;
            case 'd':
                if (!count) count = 101;
                pos += snprintf(buf + pos, sizeof(buf) - pos, "%d",
                                rand() % (2 + count - 1) - count + 1);
                count = 0;
                continue;
            case 'u':
                if (!count) count = 101;
                pos += snprintf(buf + pos, sizeof(buf) - pos, "%u",
                                rand() % count);
                count = 0;
                continue;
            case 's':
                if (!count) count = 4;
                count = rand() % count + 1;
                while (count-- > 0 && pos < sizeof(buf)) {
                    pos += snprintf(buf + pos, sizeof(buf) - pos, "%s ",
                                    dict[rand() % (sizeof(dict) / sizeof(*dict))]);
                }
                if (pos < sizeof(buf)) {
                    pos--;
                }
                count = 0;
                continue;
            default:
                buf[pos++] = *p;
                count = 0;
                continue;
            }
        }
        if (pos < sizeof(buf)) {
            buf[pos++] = '\n';
            fwrite(buf, 1, pos, stdout);
            lines--;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "usage: csvgen format number\n");
        return 2;
    }
    return csvgen(argv[1], strtol(argv[2], NULL, 0));
}