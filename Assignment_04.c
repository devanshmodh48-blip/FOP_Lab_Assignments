#include <stdio.h>

int main() {
    float basic_pay, hra, ta, gross_salary, prof_tax, net_salary;

    printf("Enter Basic Pay: ");
    scanf("%f", &basic_pay);

    hra = 0.10 * basic_pay;
    ta = 0.05 * basic_pay;
    gross_salary = basic_pay + hra + ta;
    prof_tax = 0.02 * gross_salary;
    net_salary = gross_salary - prof_tax;

    printf("Gross Salary: %.2f\n", gross_salary);
    printf("Net Salary: %.2f\n", net_salary);

    return 0;
}
