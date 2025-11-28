#include <stdio.h>

typedef struct {
    int id, arr, bur, pri, sta, end, wai, tat;
} P;

int main() {
    int n, t = 0, done[10] = {0};
    printf("Processes: "); 
    scanf("%d", &n);
    
    P p[n];
    int seq[n], idx = 0;  // To store execution order
    
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("P%d arr bur pri: ", i+1);
        scanf("%d %d %d", &p[i].arr, &p[i].bur, &p[i].pri);
    }
    
    for (int c = 0; c < n; c++) {
        int next = -1, best = 999;
        for (int i = 0; i < n; i++) {
            if (p[i].arr <= t && !done[i] && p[i].pri < best) {
                best = p[i].pri;
                next = i;
            }
        }
        
        if (next == -1) { 
            t++; 
            c--; 
            continue; 
        }
        
        p[next].sta = t;
        t += p[next].bur;
        p[next].end = t;
        done[next] = 1;
        seq[idx++] = p[next].id;  // record execution order
    }
    
    float tw = 0, tt = 0;
    printf("\nExecution sequence: ");
    for (int i = 0; i < n; i++) printf("P%d ", seq[i]);
    printf("\n\nP  Arr Bur Pri Sta End Wai Tat\n");
    
    for (int i = 0; i < n; i++) {
        p[i].wai = p[i].sta - p[i].arr;
        p[i].tat = p[i].end - p[i].arr;
        tw += p[i].wai; 
        tt += p[i].tat;
        printf("%d  %3d %3d %3d %3d %3d %3d %3d\n", 
               p[i].id, p[i].arr, p[i].bur, p[i].pri,
               p[i].sta, p[i].end, p[i].wai, p[i].tat);
    }
    
    printf("\nAvg WT=%.2f  Avg TAT=%.2f\n", tw/n, tt/n);
}
