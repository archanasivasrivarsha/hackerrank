#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct package {
    char* id;
    int weight;
} package;

typedef struct post_office {
    int packages_count;
    package* packages;
    int min_weight;
    int max_weight;
} post_office;

typedef struct town {
    char* name;
    int offices_count;
    post_office* offices;
} town;

// Function declarations
void print_all_packages(town t);
town* find_town(town* towns, int towns_count, char* name);
town* town_with_most_packages(town* towns, int towns_count);
void send_all_acceptable_packages(town* towns, int sourceTownIndex, int targetTownIndex, int sourceOfficeIndex, int targetOfficeIndex);

void print_all_packages(town t) {
    printf("%s:\n", t.name);
    for (int i = 0; i < t.offices_count; i++) {
        printf("\t%d:\n", i);
        for (int j = 0; j < t.offices[i].packages_count; j++) {
            printf("\t\t%s\n", t.offices[i].packages[j].id);
        }
    }
}

town* find_town(town* towns, int towns_count, char* name) {
    for (int i = 0; i < towns_count; i++) {
        if (strcmp(towns[i].name, name) == 0) {
            return &towns[i];
        }
    }
    return NULL;
}

town* town_with_most_packages(town* towns, int towns_count) {
    int maxPackages = -1;
    town* bestTown = NULL;

    for (int i = 0; i < towns_count; i++) {
        int total = 0;
        for (int j = 0; j < towns[i].offices_count; j++) {
            total += towns[i].offices[j].packages_count;
        }
        if (total > maxPackages) {
            maxPackages = total;
            bestTown = &towns[i];
        }
    }

    return bestTown;
}

void send_all_acceptable_packages(town* towns, int sourceTownIndex, int targetTownIndex, int sourceOfficeIndex, int targetOfficeIndex) {

    post_office* src = &towns[sourceTownIndex].offices[sourceOfficeIndex];
    post_office* dst = &towns[targetTownIndex].offices[targetOfficeIndex];

    package* accepted = malloc(src->packages_count * sizeof(package));
    package* rejected = malloc(src->packages_count * sizeof(package));
    int accIndex = 0, rejIndex = 0;

    for (int i = 0; i < src->packages_count; i++) {
        if (src->packages[i].weight >= dst->min_weight && src->packages[i].weight <= dst->max_weight) {
            accepted[accIndex++] = src->packages[i];
        } else {
            rejected[rejIndex++] = src->packages[i];
        }
    }

    // Move rejected back to source (same order)
    for (int i = 0; i < rejIndex; i++) {
        src->packages[i] = rejected[i];
    }
    src->packages_count = rejIndex;

    // Move accepted to destination
    dst->packages = realloc(dst->packages, (dst->packages_count + accIndex) * sizeof(package));
    for (int i = 0; i < accIndex; i++) {
        dst->packages[dst->packages_count + i] = accepted[i];
    }
    dst->packages_count += accIndex;

    free(accepted);
    free(rejected);
}

int main() {
    int towns_count;
    scanf("%d", &towns_count);

    town* towns = malloc(towns_count * sizeof(town));

    for (int i = 0; i < towns_count; i++) {
        towns[i].name = malloc(100 * sizeof(char));
        scanf("%s", towns[i].name);

        scanf("%d", &towns[i].offices_count);
        towns[i].offices = malloc(towns[i].offices_count * sizeof(post_office));

        for (int j = 0; j < towns[i].offices_count; j++) {
            scanf("%d %d %d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);

            towns[i].offices[j].packages = malloc(towns[i].offices[j].packages_count * sizeof(package));

            for (int k = 0; k < towns[i].offices_count; k++);

            for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
                towns[i].offices[j].packages[k].id = malloc(100 * sizeof(char));
                scanf("%s", towns[i].offices[j].packages[k].id);
                scanf("%d", &towns[i].offices[j].packages[k].weight);
            }
        }
    }

    int queries;
    scanf("%d", &queries);

    while (queries--) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            char name[100];
            scanf("%s", name);
            town* t = find_town(towns, towns_count, name);
            print_all_packages(*t);
        }

        else if (type == 2) {
            char town1[100], town2[100];
            int off1, off2;
            scanf("%s %d %s %d", town1, &off1, town2, &off2);
            send_all_acceptable_packages(towns, find_town(towns, towns_count, town1) - towns,
                                        find_town(towns, towns_count, town2) - towns, off1, off2);
        }

        else if (type == 3) {
            town* result = town_with_most_packages(towns, towns_count);
            printf("Town with the most number of packages is %s\n", result->name);
        }
    }

    return 0;
}


