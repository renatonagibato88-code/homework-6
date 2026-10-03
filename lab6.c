#include <stdio.h>
#include <math.h>

int main() 
{
    int H, M;
    
    printf("Введите количество часов (0-12) и минут: ");
    scanf("%d %d", &H, &M);

    int h_norm = H % 12;
    int current_total_minutes = h_norm * 60 + M;

    int interval_index = (int)(current_total_minutes * 11.0 / 360.0);
    
    double target_exact = (interval_index * 360.0) / 11.0;
    
    if (target_exact < current_total_minutes) 
    {
        
        target_exact = ((interval_index + 1) * 360.0) / 11.0;
    }
    else 
    {
        
        target_exact = target_exact; 
    }

    
    int result_minutes = (int)round(target_exact);

    printf("Время в минутах, когда стрелки будут на одной линии: %d\n", result_minutes);

    return 0;
}

