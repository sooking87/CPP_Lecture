#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct names
{
    char first[20];
    char last[20];
};

struct date
{
    char month[12];
    int day, year;
};

struct person
{
    struct names name;
    struct date birthday;
};

/* Converts "January", "February", ..., "December"
   into corresponding numbers 1, 2, ..., 12 */
int convert(char *mon)
{
    static char *month_list[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int i = 0;
    for (i = 1; i < 13; i++)
    {
        if (strcmp(mon, month_list[i]) == 0)
        {
            break;
        }
    }
    return (i);

    /* TO BE COMPLETED  */
    /* 5���� month_name()�� ���ڸ� �Ű�������
    �޾� �� �̸��� ����Ű�� �����͸� ��ȯ�ϴµ�,
    �� �Լ��� �� ���� �ش��ϴ� �۾��� ������ */
}

/* argv[1] contains the filename: cast.txt */

int main(int argc, char *argv[])
{
    struct person cast[20];
    int ncast = 0;
    FILE *f;
    int i;

    if (argc < 2)
    {
        fprintf(stderr, "usage:  %s  filename\n", argv[0]);
        exit(1);
    }

    if ((f = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "%s: can't open %s\n", argv[0], argv[1]);
        exit(1);
    }

    /* Reads the file contents into cast[] */
    else
    {

        while (feof(f) == 0)
        {
            char str[100];

            fgets(str, 100, f);
            printf("%s", str);
            char *temp = strtok(str, " ");
            char *one_list[6];
            int k = 0;
            while (temp != NULL)
            {
                one_list[k] = temp;
                k++;
                temp = strtok(NULL, " ");
            }
            // cast �迭 �ʱ�ȭ
            strcpy(cast[ncast].name.first, one_list[0]);
            strcpy(cast[ncast].name.last, one_list[1]);
            strcpy(cast[ncast].birthday.month, one_list[2]);
            cast[ncast]
                .birthday.day = atoi(one_list[3]);
            cast[ncast]
                .birthday.year = atoi(one_list[4]);
            ncast++;
        }
    }
    /* TO BE COMPLETED */
    /* ���� ũ�⸦  �������� ����, EOF �� �ν��Ͽ� ó���ؾ� �� */
    fclose(f);
    // cast == EOF{char cast};
    printf("Cast of Captain America: Civil War\n");
    printf("==================================\n\n");
    printf("Name   (Birthday)\n\n");
    for (i = 0; i < ncast; i++)
        printf("%s, %s  (%02d/%02d/%02d)\n",
               cast[i].name.last, cast[i].name.first,
               convert(cast[i].birthday.month),
               cast[i].birthday.day,
               cast[i].birthday.year % 100);
}
