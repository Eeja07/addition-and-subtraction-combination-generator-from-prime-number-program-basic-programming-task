#include <stdio.h>
#include <stdlib.h>

int totalof10;
void kombinasi(int *operand, int index, int *number, int n, int x, int y)
{
    int jumlah;
    if (index < n)
    {
        do
        {
            kombinasi(operand, index + 1, number, n, x, y);
            operand[index] *= -1;
        } while (operand[index] != 1);
    }
    else
    {
        jumlah = 2;
        for (int i = 0; i < n; i++)
        {
            jumlah += number[i] * operand[i];
        }
        if (jumlah > x && jumlah < y)
        {
            printf("\n2 ");
            for (int i = 0; i < n; i++)
            {
                if (number[i] * operand[i] > 0)
                    printf("+ %i ", number[i] * operand[i]);
                else
                    printf("- %i ", number[i] * operand[i] * -1);
            }
            printf("= %i", jumlah);
            totalof10++;
            printf("\t");
        }
    }
}
int main()
{
    int x, y, n;
    int hasil = 0;
    printf("Masukkan nilai N: ");
    scanf("%d", &n);
    printf("number prima sampai %d adalah:\n", n);
    for (int i = 2; i <= n; i++)
    {
        int c = 0;
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
            {
                c++;
            }
        }
        if (c == 2)
        {
            printf("%d ", i);
            hasil += i;
        }
    }
    int sum = hasil;
    int *number, *operand;
    number = malloc((n) * sizeof(int));
    operand = malloc((n) * sizeof(int));
    for (int i = 0; i < sum; i++)
    {
        operand[i] = 1;
    }
    int iPrima = 1;
    for (int i = 3; i <= n; i++)
    {
        int prima = 1;
        for (int j = 2; j <= 1 / 2; j++)
        {
            if (i % j == 0)
                prima = 0;
        }
        if (prima == 1)
        {
            number[iPrima] = i;
            iPrima++;
        }
    }
    printf("\nMasukkan nilai X dan Y: ");
    scanf("%d %d", &x, &y);
    printf("Hasil kombinasi harus lebih besar dari %d dan lebih kecil dari %d\nKombinasi yang tepat adalah:\n", x, y);
    printf("\n");
    kombinasi(operand, 0, number, n, x, y);
    if (totalof10 == 0)
        printf("Tidak ada kombinasi pengurangan dan penjumlahan untuk bilangan prima 1 - %i yang > %i dan < %i", n, x, y);

    free(number);
    free(operand);

    return 0;
}