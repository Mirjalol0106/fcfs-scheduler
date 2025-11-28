#include <stdio.h>

typedef struct {
    int id, arr, bur, rem, sta, end, wai, tat;
} P;

int main() {
    int n, q;
    printf("Processes: ");
    scanf("%d", &n);
    printf("Quantum: ");
    scanf("%d", &q);

    P p[n];
    int Q[100], f = 0, r = 0, t = 0, done = 0;
    int inQ[50] = {0};

    // input
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("P%d arr bur: ", i + 1);
        scanf("%d %d", &p[i].arr, &p[i].bur);
        p[i].rem = p[i].bur;
        p[i].sta = -1;

        if (p[i].arr == 0) {
            Q[r++] = i;
            inQ[i] = 1;
        }
    }

    printf("\n--- Execution Order ---\n");

    while (done < n) {

        // If queue empty → CPU idle
        if (f == r) {
            t++;
            for (int i = 0; i < n; i++)
                if (p[i].arr <= t && !inQ[i] && p[i].rem > 0)
                    Q[r++] = i, inQ[i] = 1;
            continue;
        }

        int i = Q[f++];     // get process index
        inQ[i] = 0;

        if (p[i].sta == -1) p[i].sta = t;

        int run = (p[i].rem < q) ? p[i].rem : q;

        printf("P%d runs from %d to %d\n", p[i].id, t, t + run);

        t += run;
        p[i].rem -= run;

        // Add newly arrived processes
        for (int j = 0; j < n; j++)
            if (p[j].arr <= t && !inQ[j] && p[j].rem > 0)
                Q[r++] = j, inQ[j] = 1;

        // If not finished → back to queue
        if (p[i].rem > 0)
            Q[r++] = i, inQ[i] = 1;
        else {
            p[i].end = t;
            done++;
        }
    }

    // Final table
    printf("\nP  Arr Bur Sta End Wai Tat\n");

    float tw = 0, tt = 0;
    for (int i = 0; i < n; i++) {
        p[i].tat = p[i].end - p[i].arr;
        p[i].wai = p[i].tat - p[i].bur;
        tw += p[i].wai;
        tt += p[i].tat;

        printf("P%d %3d %3d %3d %3d %3d %3d\n",
               p[i].id, p[i].arr, p[i].bur,
               p[i].sta, p[i].end, p[i].wai, p[i].tat);
    }

    printf("Avg WT=%.2f  Avg TAT=%.2f\n", tw / n, tt / n);
    return 0;
}
