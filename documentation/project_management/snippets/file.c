

void csvReader(FILE *f) {
    T_structCDT c;
    int count = 0;
    c.string = malloc(1000);
    while (fscanf(f, "%d,%d,%d,%999[^,],%d\n", &c.a, &c.b, &c.vivienda, c.c, &c.d) == 5) {
        // nothing for now
        count++;
    }
    printf("%d records parsed\n");
}