#include <stdio.h>
#include <math.h>

int main() 
{
    int H, M;
    
    printf("Введите количество часов (0-12) и минут: ");
    scanf("%d %d", &H, &M);

    // Приводим 12 часов к 0 и считаем текущее время в минутах
    int h_norm = H % 12;
    int current_total_minutes = h_norm * 60 + M;

    // Стрелки выстраиваются на одну линию каждые 360 / 11 минут.
    // Находим индекс текущего интервала
    int interval_index = (int)(current_total_minutes * 11.0 / 360.0);
    
    // Вычисляем точную координату времени в минутах для этого интервала
    double target_exact = (interval_index * 360.0) / 11.0;
    
    // Проверка условий через if-else без использования циклов
    if (target_exact < current_total_minutes) 
    {
        // Если расчетная точка уже в прошлом, берем следующий интервал
        target_exact = ((interval_index + 1) * 360.0) / 11.0;
    }
    else 
    {
        // Иначе оставляем текущую найденную точку
        target_exact = target_exact; 
    }

    // Округляем до ближайшей целой минуты
    int result_minutes = (int)round(target_exact);

    printf("Время в минутах, когда стрелки будут на одной линии: %d\n", result_minutes);

    return 0;
}

