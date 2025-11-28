#include <stdio.h>

typedef struct {
    int id, arr, bur, sta, end, wai, tat;
} P;

int main() {
    int n, t = 0, done[10] = {0};
    scanf("%d", &n);
    P p[n];
    
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        scanf("%d%d", &p[i].arr, &p[i].bur);
    }
    
    for (int c = 0; c < n; c++) {
        int next = -1, min = 999;
        
        for (int i = 0; i < n; i++)
            if (p[i].arr <= t && !done[i] && p[i].bur < min)
                min = p[i].bur, next = i;
        
        if (next == -1) { t++; c--; continue; }

        p[next].sta = t;
        p[next].end = t + p[next].bur;
        printf("Run P%d from %d to %d\n", p[next].id, t, p[next].end);

        t = p[next].end;
        done[next] = 1;
    }

    float tw = 0, tt = 0;
    printf("\nP Arr Bur Sta End Wai Tat\n");
    
    for (int i = 0; i < n; i++) {
        p[i].wai = p[i].sta - p[i].arr;
        p[i].tat = p[i].end - p[i].arr;
        tw += p[i].wai; tt += p[i].tat;
        printf("P%d %3d %3d %3d %3d %3d %3d\n",
               p[i].id,p[i].arr,p[i].bur,
               p[i].sta,p[i].end,p[i].wai,p[i].tat);
    }
    
    printf("Avg WT=%.2f TAT=%.2f\n", tw/n, tt/n);
}
