#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void Kvad(float a, float b, float c)
{
	float discr, x1, x2;
	FILE* filekv = fopen("quadratic_equation.txt", "w");
	if ((a != 0) && (b != 0) && (c != 0))
	{
		discr = b * b - 4 * a * c;
		if (discr < 0)
		{
			printf("������ ���");
			fprintf(filekv, "������������ = %f ������ ���", discr);
			fclose(filekv);

		}
		else if (discr == 0)
		{
			x1 = -b / (2 * a);
			fprintf(filekv, "������������ = %f ���������� ������:1 x: %f ", discr, x1);
			fclose(filekv);
		}
		else if (discr > 0)
		{
			x1 = (-b + sqrt(discr)) / (2 * a);
			x2 = (-b - sqrt(discr)) / (2 * a);
			printf("x1: % f  x2 : % f", x1, x2);
			fprintf(filekv, "������������ = %f ���������� ������:2 x1: %f  x2: %f", discr, x1, x2);
			fclose(filekv);
		}
	}
	else if ((c == 0) && (b == 0))
	{
		x1 = 0;
		printf("����� ��������� = %f ", x1);
		fprintf(filekv, "����� ��������� = %f ", x1);
		fclose(filekv);
	}
	else if (b == 0)
	{

		if (-c / a < 0)
		{
			printf("�� ����� ������");
		}
		else
		{
			x1 = sqrt((-c / a));
			printf("����� ��������� = %f � -%f", x1, x1);
			fprintf(filekv, "����� ��������� = %f � -%f", x1, x1);
			fclose(filekv);
		}
	}
	else if (c == 0)
	{
		x1 = -b / a;
		x2 = 0;
		printf("����� ��������� = %f � %f", x1, x2);
		fprintf(filekv, "����� ��������� = %f � %f", x1, x2);
		fclose(filekv);
	}
	else if (a == 0)
	{
		x1 = -c / b;
		printf("����� ��������� = %f ", x1);
		fprintf(filekv, "����� ��������� = %f ", x1);
		fclose(filekv);
	}

}


int main()
{
	system("chcp 1251 > nul");
	float a, b, c;
	float f[3];
	FILE* file = fopen("./Start_coefficent.txt", "r");
	if (file == NULL)
	{
		printf("��������� ������ ��� �������� �����"); \
			return 0;
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			fscanf(file, "%f", &f[i]);
		}
		fclose(file);
		if ((f[0] == 0) && (f[1] == 0) && (f[2] == 0))
		{
			printf("������,��� ����������� ����� 0 \n");
			return 0;
		}
		else if (f[0] == -107374176. || f[1] == -107374176. || f[2] == -107374176.)
		{
			printf("����������� ������� ������");
			return 0;
		}
		Kvad(f[0], f[1], f[2]);
	}

}