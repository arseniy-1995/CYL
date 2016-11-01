// Программа CYL.EXE 2016



// cyl.cpp: определяет точку входа для консольного приложения.
//
//#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <fstream>
#include <string.h> 
#include <iomanip>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath> 
#include <iostream>
#include "float.h"
#include <time.h>
#include <random>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <omp.h> // многопоточность процессора
#include<io.h>
#include<process.h>
#include<string.h>




using namespace std;
// функция подсчета длины массива
template<typename T> inline int arrlen(T *arr) {
	return static_cast<int>(_msize(arr) / sizeof(T));
}


/*

// Функция, генерирующая случайное действительное число от min до max  на языке C
long double random(long double min, long double max)
{
//задаем параметр случайности
srand((unsigned int)time(NULL) + rand()); // привязка генератора случайных чисел к системному времени
return (long double)rand() / RAND_MAX * (max - min) + min;

}


*/

// Функция, генерирующая случайное действительное число от min до max на языке C++ V.11
long double random(long double min, long double max)
{


	std::random_device rd;
	//	std::mt19937 gen(rd()+ time(NULL));
	std::mt19937_64 gen(rd() + time(NULL));
	std::uniform_real_distribution<> dis(min, max);

	return	dis(gen);




}



// поворот вокруг оси z + обратная матрица поворота

void rotate(char *s, long double x0, long double y0, long double z0, long double &x, long double &y, long double &z) {
	long double	temp_x = x;
	long double	temp_y = y;
	long double	temp_z = z;


	long double alpha;
	alpha = atan2(y0, x0);

	if (s == "matrix") {

		x = temp_x*cos(alpha) + temp_y*sin(alpha);
		y = -temp_x*sin(alpha) + temp_y*cos(alpha);
		z = temp_z;

	}

	if (s == "inverse_matrix") {

		x = temp_x*cos(alpha) - temp_y*sin(alpha);
		y = temp_x*sin(alpha) + temp_y*cos(alpha);
		z = temp_z;
	}

}


// Функция, строящая функцию распределения(гистограмму) числа частиц, попавших в бины гистограммы, распределение по радиусу

// гистограмма распределения по радиусу с учетом знака координаты y (проинтегрировано по половине полного угла)
long double **histo_x(char *s, long double **mass_histo, int N_histo, long double x, long double y, long double R, long double R_source) {


	long double h = 2.0*R / N_histo; // ширина бина


	if (s == "histo") {

		long double r = pow(pow(x, 2.0) + pow(y, 2.0), 1.0 / 2.0); // текущий радиус

		int lenrow = arrlen(mass_histo);

		for (int i = 0; i < (int)(lenrow / 2.0); i = i + 1) { // перебираем бины

			if ((r > (R - h*(i + 1.0))) && (r <= (R - h*i)) && (y <= 0))
			{
				mass_histo[i][0] = mass_histo[i][0] + 1; // если частица попала в бин, то содержимое бина увеличилось на одну частицу

			}

			if ((r > (R - h*(i + 1.0))) && (r <= (R - h*i)) && (y > 0))
			{
				mass_histo[lenrow - 1 - i][0] = mass_histo[lenrow - 1 - i][0] + 1; // если частица попала в бин, то содержимое бина увеличилось на одну частицу

			}

		}
	}

	if (s == "source") {

		long double r = 0.0;  // текущий радиус
		long double y0 = 0.0; // смещение детектора

		int lenrow = arrlen(mass_histo);

		for (int i = 0; i < lenrow; i = i + 1) { // перебираем бины

			y0 = -R + h*i;

			r = pow(pow(x, 2.0) + pow(y - y0, 2.0), 1.0 / 2.0);

			if (r <= R_source)
			{
				mass_histo[i][0] = mass_histo[i][0] + 1; // если частица попала в кольцо детектора, то содержимое бина увеличилось на одну частицу

			}


		}




	}


	return mass_histo;
}


// гистограмма распределения по модулю радиусу (проинтегрировано по полному углу)
long double **histo_r(char *s, long double **mass_histo, int N_histo, long double x, long double y, long double R, long double R_source) {


	long double h = R / N_histo; // ширина бина


	if (s == "histo") {

		long double r = pow(pow(x, 2.0) + pow(y, 2.0), 1.0 / 2.0); // текущий радиус

		int lenrow = arrlen(mass_histo);

		for (int i = 0; i < lenrow; i = i + 1) { // перебираем бины

			if ((r > (R - h*(i + 1.0))) && (r <= (R - h*i)))
			{
				mass_histo[lenrow - 1 - i][0] = mass_histo[lenrow - 1 - i][0] + 1; // если частица попала в бин, то содержимое бина увеличилось на одну частицу

			}


		}


	}





	if (s == "source") {

		long double r = 0.0;  // текущий радиус
		long double y0 = 0.0; // смещение детектора

		int lenrow = arrlen(mass_histo);

		for (int i = 0; i < lenrow; i = i + 1) { // перебираем бины

			y0 = h*i;

			r = pow(pow(x, 2.0) + pow(abs(y - y0), 2.0), 1.0 / 2.0);


			if ((r <= R_source))
			{
				mass_histo[i][0] = mass_histo[i][0] + 1; // если частица попала в кольцо детектора, то содержимое бина увеличилось на одну частицу

			}


		}

	}


	return mass_histo;
}








void mass_histo_out(long double **arr) { // печать содержимого двумерного массива в терминале
	int lenrow = arrlen(arr);
	int lencol = arrlen(arr[0]);
	for (int i = 0; i < lenrow; ++i) {
		std::cout << "[ ";
		for (int j = 0; j < lencol; ++j) {

			std::cout << std::fixed << std::setprecision(3) << arr[i][j] << " ";
		}

		std::cout << "]" << std::endl;
	}
}


void out_txt(char *filename, long double **mass_histo_x, long double **mass_histo_r, int start_time, int end_time, long double  R1_1, long double R2_1, long double R3_1, long double L_1, long double V_0, long double  R1_2, long double R2_2, long double R3_2, long double L_2, long double R1_3, long double R2_3, long double R3_3, long double L_3, long double R1_4, long double R2_4, long double R3_4, int  N, int N_histo, long double R, long double b1_left, long double b1_surface, long double b1_right, long double b2_left, long double b2_surface, long double b2_right, long double b3_left, long double b3_surface, long double b3_right, int N_on, int N_off, int N1_1, int N2_1, int N3_1, int N4_1, int N5_1, int N6_1, int N7_1, int N1_2, int N2_2, int N3_2, int N4_2, int N5_2, int N6_2, int N7_2, int N1_3, int N2_3, int N3_3, int N4_3, int N5_3, int N6_3, int N7_3, int n1, int n2, int n3, int n_travel, long double t, long double theta1_diffusion_left, long double theta1_diffusion_surface, long double theta1_diffusion_right, long double theta2_diffusion_left, long double theta2_diffusion_surface, long double theta2_diffusion_right, long double theta3_diffusion_left, long double theta3_diffusion_surface, long double theta3_diffusion_right, long double R_source, int N_histo_source,int normalization_x,int normalization_r) {


	// вывод полученных результатов в файл
	FILE *fd;
	fopen_s(&fd, filename, "wb");
	if (fd == NULL) {
		fprintf(stderr, "Ошибка открытия выводного файла.\n");
		cout << endl;
		Sleep(800); // пауза для того, чтобы успеть прочитать информацию
		exit(1);
	}
	else {
		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

		fprintf(fd, "\n");
		fprintf(fd, "### \n");
		fprintf(fd, "### Число Частиц в Бине || Нормированное Значение || Координата X Левого Конца Бина || Число Частиц в Бине || Нормированное Значение || Координата R Левого Конца Бина \n");
		fprintf(fd, "### \n");
		fprintf(fd, "\n");

		setlocale(LC_ALL, "C"); // установить используемую системой локаль для корректной отображении точки в выходном файле

		for (int i = 0; i < arrlen(mass_histo_x); i++) {

			if (i < arrlen(mass_histo_r)) {

				if ((normalization_x == 0)||(normalization_r==0)) {// исключение надписи nan(ind)
					fprintf(fd, "%.0f %.0f %f %.0f %.0f %f\n", mass_histo_x[i][0], 0.0, mass_histo_x[i][1], mass_histo_r[i][0], 0.0, mass_histo_r[i][1]);
				}
				else {
					fprintf(fd, "%.0f %.5e %f %.0f %.5e %f\n", mass_histo_x[i][0], (long double)(mass_histo_x[i][0] / normalization_x), mass_histo_x[i][1], mass_histo_r[i][0], (long double)(mass_histo_r[i][0] / normalization_r), mass_histo_r[i][1]);

				}
			}

			else {

				if ((normalization_x == 0) || (normalization_r == 0)) {// исключение надписи nan(ind)
					fprintf(fd, "%.0f %.0f %f %.0f %.0f %f\n", mass_histo_x[i][0], 0.0, mass_histo_x[i][1], 0.0, 0.0, 0.0);
				}
				else {
					fprintf(fd, "%.0f %.5e %f %.0f %.0f %f\n", mass_histo_x[i][0], (long double)(mass_histo_x[i][0] / normalization_x), mass_histo_x[i][1], 0.0, 0.0, 0.0);

				}
			}

		}
		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

		fprintf(fd, "\n");
		fprintf(fd, "### \n");
		fprintf(fd, "### Скорость = %.2f Число Частиц = %.2e Число Бинов = %.0f Максимальное время счета = %.2f (мин.)\n", V_0, (long double)N, (long double)N_histo, t);
		fprintf(fd, "### R1_1=%.1f R2_1=%.1f R3_1=%.1f L_1=%.1f\n", R1_1, R2_1, R3_1, L_1);
		fprintf(fd, "### R1_2=%.1f R2_2=%.1f R3_2=%.1f L_2=%.1f\n", R1_2, R2_2, R3_2, L_2);
		fprintf(fd, "### R1_3=%.1f R2_3=%.1f R3_3=%.1f L_3=%.1f\n", R1_3, R2_3, R3_3, L_2);
		fprintf(fd, "### R1_4=%.1f R2_4=%.1f R3_4=%.1f\n", R1_4, R2_4, R3_4);
		fprintf(fd, "### \n");

		fprintf(fd, "Радиус кольца детектора = %.2f\n", R_source);
		fprintf(fd, "Число точек, измеренных детектором = %.0f\n", (long double)N_histo_source);

		fprintf(fd, "### \n");
		fprintf(fd, "### (Цилиндр №1) Коэфф.Захвата Левого торца = %.2f Коэфф.Захвата Поверхности Образующей = %.2f Коэфф.Захвата Правого торца = %.2f\n", b1_left, b1_surface, b1_right);
		fprintf(fd, "### (Цилиндр №2) Коэфф.Захвата Левого торца = %.2f Коэфф.Захвата Поверхности Образующей = %.2f Коэфф.Захвата Правого торца = %.2f\n", b2_left, b2_surface, b2_right);
		fprintf(fd, "### (Цилиндр №3) Коэфф.Захвата Левого торца = %.2f Коэфф.Захвата Поверхности Образующей = %.2f Коэфф.Захвата Правого торца = %.2f\n", b3_left, b3_surface, b3_right);
		fprintf(fd, "### \n");
		fprintf(fd, "### (Цилиндр №1) Дифф. Угол Левого торца = %.2f Дифф. Угол Поверхности Образующей = %.2f Дифф. Угол Правого торца = %.2f\n", theta1_diffusion_left, theta1_diffusion_surface, theta1_diffusion_surface);
		fprintf(fd, "### (Цилиндр №2) Дифф. Угол Левого торца = %.2f Дифф. Угол Поверхности Образующей = %.2f Дифф. Угол Правого торца = %.2f\n", theta2_diffusion_left, theta2_diffusion_surface, theta2_diffusion_surface);
		fprintf(fd, "### (Цилиндр №3) Дифф. Угол Левого торца = %.2f Дифф. Угол Поверхности Образующей = %.2f Дифф. Угол Правого торца = %.2f\n", theta3_diffusion_left, theta3_diffusion_surface, theta3_diffusion_surface);
		fprintf(fd, "### \n");



		fprintf(fd, "### (Цилиндр №1) Максимальное число столкновений о стенки = %.0f\n", (long double)n1);
		fprintf(fd, "### (Цилиндр №2) Максимальное число столкновений о стенки = %.0f\n", (long double)n2);
		fprintf(fd, "### (Цилиндр №3) Максимальное число столкновений о стенки = %.0f\n", (long double)n3);
		fprintf(fd, "### Максимальное число переходов частицы между цилиндрами №1,2,3 = %.0f\n", (long double)n_travel);


		fprintf(fd, "### \n");
		fprintf(fd, "### Полное число частиц брошенных в круг, описанный вокруг торца цилиндра = %.1e\n", (long double)N);
		fprintf(fd, "### Число частиц, которые не вышли из круна в источник = %.1e\n", (long double)N_off);
		fprintf(fd, "### Число частиц выпущенных из кольца источника = %.0f\n", (long double)N_on);
		fprintf(fd, "### Полное число частиц, которые вышли из цилиндра №3 = %.0f\n", (long double)N2_3);
		fprintf(fd, "### Число частиц, которые вернулись обратно в источник из цилиндра №1 = %.0f\n", (long double)N1_1);
		fprintf(fd, "### Число частиц, которые были захвачены поверхностью цилиндра №1 = %.0f\n", (long double)(N3_1 + N4_1 + N5_1));
		fprintf(fd, "### Число частиц, которые были захвачены поверхностью цилиндра №2 = %.0f\n", (long double)(N3_2 + N4_2 + N5_2));
		fprintf(fd, "### Число частиц, которые были захвачены поверхностью цилиндра №3 = %.0f\n", (long double)(N3_3 + N4_3 + N5_3));
		fprintf(fd, "### Полное число частиц, которые были захвачены поверхностими цилиндров №1,2,3 = %.0f\n", (long double)(N3_1 + N4_1 + N5_1 + N3_2 + N4_2 + N5_2 + N3_3 + N4_3 + N5_3));


		//	fprintf(fd, "### \n");
		//	fprintf(fd, "### Число частиц, которые остались вечно саударяться со стенками цилиндра №1 = \n", n1);
		//	fprintf(fd, "### Число частиц, которые остались вечно саударяться со стенками цилиндра №2 = \n", n2);
		//	fprintf(fd, "### Число частиц, которые остались вечно саударяться со стенками цилиндра №3 = \n", n3);
		//	fprintf(fd, "### Число частиц, которые остались вечно гулять между цилиндрами №1,2,3 = \n", n_travel);

			//	fprintf(fd, "### Число частиц, которые сразу вышли из усточника и не коснулись стенок %.0f\n", (long double)N5);
			////	fprintf(fd, "### Число частиц, которые хотя бы раз коснулись стенок и вышли из источника %.0f\n", (long double)N6);
		fprintf(fd, "### \n");
		fprintf(fd, "### N_out/N_in=%.5f\n", ((long double)N2_3 / (long double)N_on));
		fprintf(fd, "### L_3/R_3=%.5f\n", ((long double)L_3 / (long double)R1_3));
		fprintf(fd, "### k=(N_out/N_in)/(L_3/R_3)=%.5f\n", ((long double)N2_3 / (long double)N_on) / ((long double)L_3 / (long double)R1_3));
		fprintf(fd, "### \n");


		unsigned int search_time = end_time - start_time; // искомое время в миллисекундах
		int search_time_ = (int)search_time / (1000 * 60); // минут
		int search_time__ = (int)(search_time / 1000.0) % 60; // секунд


		fprintf(fd, "### Время выполнения расчета: %.0f мин. и %.0f сек.\n", (long double)search_time_, (long double)search_time__);
		fprintf(fd, "\n");



		fclose(fd);

	}



	// удаление двумерного динамического массива гистограммы
	for (int count = 0; count < arrlen(mass_histo_x); count++) {
		delete[] mass_histo_x[count];
	}

	delete[] mass_histo_x;



	// удаление двумерного динамического массива гистограммы
	for (int count = 0; count < arrlen(mass_histo_r); count++) {
		delete[] mass_histo_r[count];
	}

	delete[] mass_histo_r;





}


// время контакта с цилиндром для частиц, испущенных с кольца
long double time1(long double r, long double theta, long double phi, long double psi, long double R, long double V_0) // определение времени момента столкновение со стенкой цилиндра, частица испущена с торца
{
	long double t = 0.0;
	t = (-r*cos(phi - psi) + pow(pow(R, 2.0) - pow(r, 2.0)*pow(sin(phi - psi), 2.0), 1.0 / 2.0)) / (sin(theta));
	return t;

}

// время контакта с плоскостью z=h для частиц, испущенных с кольца
long double time1_(long double z0, long double h, long double theta, long double V_0) // частица испущена с торца
{
	long double t = 0.0;
	t = (h - z0) / cos(theta);
	return t;

}



// время контакта с цилиндром для частиц, испущенных со стенки цилиндра
long double time2(long double theta, long double psi, long double R, long double V_0) // определение времени момента столкновение со стенкой цилиндра, частица испущена с поверхности цилиндра
{
	long double t = 0.0;
	t = (2.0*R) / (cos(theta)*(1.0 + tan(theta)*sin(psi)*tan(theta)*sin(psi)));

	return t;

}

// время контакта с плоскостью z=h для частиц, испущенных со стенки цилиндра
long double time2_(long double z0, long double h, long double theta, long double psi, long double V_0) //  частица испущена с поверхности цилиндра
{
	long double t = 0.0;

	t = (z0 - h) / (sin(theta)*cos(psi));

	return t;

}

// вычисление координат после вылета из торца цилиндра
void func1(char *s, long double x_in, long double y_in, long double z_in, long double r_in, long double theta_in, long double phi_in, long double psi_in, long double &x_out, long double &y_out, long double &z_out, long double &r_out, long double t, long double V_0) { // передача аргументов по ссылке


	x_out = r_in*cos(phi_in) + t*sin(theta_in)*cos(psi_in);
	y_out = r_in*sin(phi_in) + t*sin(theta_in)*sin(psi_in);

	if (strcmp(s, "left") == 0) {
		z_out = z_in + t*cos(theta_in);

	}

	if (strcmp(s, "right") == 0) {
		z_out = z_in - t*cos(theta_in);
		//cout << "yes" << endl;

	}

	r_out = pow(pow(x_out, 2.0) + pow(y_out, 2.0), 1.0 / 2.0);

}


// вычисление координат после вылета с поверхности цилиндра с учетом того, что частица снова окажется на цилиндре
void func2(char *s, long double x_in, long double y_in, long double z_in, long double r_in, long double theta_in, long double psi_in, long double &x_out, long double &y_out, long double &z_out, long double &r_out, long double t, long double V_0) { // передача аргументов по ссылке
																																		 //	t = t*V_0;

	y_out = t*sin(theta_in)*sin(psi_in);
	x_out = r_in - abs(t*cos(theta_in));

	if (strcmp(s, "left") == 0) {
		z_out = z_in + abs(t*sin(theta_in)*cos(psi_in));
	}

	if (strcmp(s, "right") == 0) {
		z_out = z_in - abs(t*sin(theta_in)*cos(psi_in));
	}

	rotate("inverse_matrix", x_in, y_in, z_in, x_out, y_out, z_out);

	r_out = pow(pow(x_out, 2.0) + pow(y_out, 2.0), 1.0 / 2.0);


}



void cyl(long double x_in, long double y_in, long double z_in, long double r_in, long double theta_in, long double phi_in, long double psi_in, long double &x_out, long double &y_out, long double &z_out, long double &r_out, long double &theta_out, long double &phi_out, long double &psi_out, int &N1, int &N2, int &N3, int &N4, int &N5, long double L_initial, long double L_final, long double R1_initial, long double R2_initial, long double R3_initial, long double R1_final, long double R2_final, long double R3_final, long double b_left, long double b_surface, long double b_right, long double V_0, bool &out, int n, long double theta_diffusion_left, long double theta_diffusion_surface, long double theta_diffusion_right) {

	long double x0 = x_in, y0 = y_in, z0 = z_in, r0 = r_in, theta0 = theta_in, phi0 = phi_in, psi0 = psi_in; // значения на предыдущей итерации
	long double x = x_in, y = y_in, z = z_in, r = r_in, theta = theta_in, phi = phi_in, psi = psi_in;// значения на текущей итерации
	int n1 = N1; // число частиц, вылетевших с левого торца цилинлра
	int n2 = N2; // число частиц, вылетевших с правого торца цилинлра
	int n3 = N3; // число частиц, захваченных левым торцом цилинлра
	int n4 = N4; // число частиц, захваченных образующей цилинлра
	int n5 = N5; // число частиц, захваченных правым торцом цилинлра

	x_out = 0.0;
	y_out = 0.0;
	z_out = 0.0;
	r_out = 0.0;

	out = true; // Булева переменная для индикации вылета частицы из цилиндра

	long double t1 = abs(time1(r0, theta0, phi0, psi0, R1_initial, V_0));
	long double t2 = abs(time1_(z0, L_final, theta0, V_0));
	long double t3 = abs(time1_(z0, L_initial, theta0, V_0));
	if (z0 == L_initial) {
		long double t = min(t1, t2);
		func1("left", x0, y0, z0, r0, theta0, phi0, psi0, x, y, z, r, t, V_0);
	}

	if (z0 == L_final) {
		long double t = min(t1, t3);
		func1("right", x0, y0, z0, r0, theta0, phi0, psi0, x, y, z, r, t, V_0);
	}


	//cout << x << "  " << y << "  " << z << "    " << r << endl;





#pragma omp parallel
	{
#pragma omp for // распараллеливание большого цикла на многопоточность



		for (int i = 1; i <= n; i = i + 1) { // ограничение на число саударений, иначе, прочесс может идти бесконечность

			//cout << x << "  " << y << "  " << z << "    " << r << endl;

			// вылет из правого конца цилиндра
			if ((z == L_final) && ((r <= R2_final) && (r >= R3_final))) {

				//cout << z0 << endl;
				if ((z0 == L_initial)) {
					theta_out = theta;
					phi_out = phi;
					psi_out = psi;
				}
				else {
					theta_out = M_PI_2 - theta;
					phi_out = atan2(-y0, x0);
					psi_out = phi;

				}
				x_out = x;
				y_out = y;
				z_out = z;
				r_out = r;
				out = true;
				n2 = n2 + 1;

				//	cout << x_out << "  " << y_out << "  " << z_out << "    " << r_out << endl;
				//return;
				break;


			}


			// удар о правый торец цилиндра
			if ((z == L_final) && ((r > R2_final) || (r < R3_final))) {

				//break;

				srand((unsigned int)time(NULL) + rand()); // привязка генератора случайных чисел к системному времени


				long double mu = random(0.0, 1.0); // случайное число для учета захвата частицы поверхностью цилиндра
				//cout << mu;
				if (mu <= b_right) {
					//return;
					out = false;
					n5 = n5 + 1;
					break;
				}

				else {

					if (z0 = L_initial) {
						theta0 = theta;
						phi0 = phi;
						psi0 = psi;
					}
					else {
						theta0 = M_PI_2 - theta;
						phi0 = atan2(-y0, x0);
						psi0 = phi;

					}

					x0 = x;
					y0 = y;
					z0 = z;
					r0 = r;





					if (theta0 <= theta_diffusion_right) {
						srand((unsigned int)time(NULL) + rand()); // привязка генератора случайных чисел к системному времени
																  //theta_0 = acos(pow(1.0 - pow(random(0.0, 1.0), 2.0), 1.0 / 2.0)); // от -pi/2 до pi распределена по закону cos(), получена методом обратной функции
																  //theta_0 = asin(pow(random(0.0, 1.0), 1.0 / 2.0));
						theta = asin(random(0.0, 1.0));// от 0 до pi/2 распределена по закону cos(), получена методом обратной функции, максимум вероятности при theta=0

						srand((unsigned int)time(NULL) + rand()); // привязка генератора случайных чисел к системному времени
						phi = random(0.0, 2.0*M_PI); //от 0 до 2*pi равномерно распределена

						srand((unsigned int)time(NULL) + rand()); // привязка генератора случайных чисел к системному времени
						psi = random(0.0, 2.0*M_PI); //от 0 до 2*pi равномерно распределена

					}

					else {
						theta = theta0;
						phi = phi0;
						psi = psi - M_PI;

					}



					long double t1 = abs(time1(r0, theta, phi, psi, R1_initial, V_0));
					long double t2 = abs(time1_(z0, L_initial, theta, V_0));



					long double t = min(t1, t2);
					//cout << t1 << "  " << t2<< "  " <<t<<  endl;
					func1("right", x0, y0, z0, r0, theta, phi, psi, x, y, z, r, t, V_0);
					//cout << x << "  " << y << "  " << z << "    " << r << endl;
					//break;
					continue;
				}

			}

			// вылет из левого конца цилиндра
			if ((z == L_initial) && ((r <= R2_initial) && (r >= R3_initial))) {

				//break;

				if (z0 == L_final) {
					theta_out = theta;
					phi_out = phi;
					psi_out = psi;
				}
				else {
					theta_out = M_PI_2 - theta;
					phi_out = atan2(-y0, x0);
					psi_out = phi;

				}


				x_out = x;
				y_out = y;
				z_out = z;
				r_out = r;
				n1 = n1 + 1;

				out = true;

				//	cout << "8888" << endl;
					//cout << x_out << "  " << y_out << "  " << z_out << "    " << r_out << endl;

					//return;
				break;
			}

			// удар о левый торец цилиндра
			if ((z == L_initial) && ((r > R2_initial) || (r < R3_initial))) {

				//break;
				srand((unsigned int)time(NULL) + rand()); // привязка генератора случайных чисел к системному времени


				long double mu = random(0.0, 1.0); // случайное число для учета захвата частицы поверхностью цилиндра

				if (mu <= b_left) {

					out = false;
					n3 = n3 + 1;
					//	return;
					break;

				}

				else {

					if (z0 = L_initial) {
						theta0 = theta;
						phi0 = phi;
						psi0 = psi;
					}
					else {
						theta0 = M_PI_2 - theta;
						phi0 = atan2(-y0, x0);
						psi0 = phi;

					}

					x0 = x;
					y0 = y;
					z0 = z;
					r0 = r;


					if (theta0 <= theta_diffusion_left) {
						srand((unsigned int)time(NULL) + rand()); // привязка генератора случайных чисел к системному времени
																  //theta_0 = acos(pow(1.0 - pow(random(0.0, 1.0), 2.0), 1.0 / 2.0)); // от -pi/2 до pi распределена по закону cos(), получена методом обратной функции
																  //theta_0 = asin(pow(random(0.0, 1.0), 1.0 / 2.0));
						theta = asin(random(0.0, 1.0));// от 0 до pi/2 распределена по закону cos(), получена методом обратной функции, максимум вероятности при theta=0

						srand((unsigned int)time(NULL) + rand()); // привязка генератора случайных чисел к системному времени
						phi = random(0.0, 2.0*M_PI); //от 0 до 2*pi равномерно распределена

						srand((unsigned int)time(NULL) + rand()); // привязка генератора случайных чисел к системному времени
						psi = random(0.0, 2.0*M_PI); //от 0 до 2*pi равномерно распределена

					}

					else {
						theta = theta0;
						phi = phi0;
						psi = psi - M_PI;

					}



					long double t1 = abs(time1(r0, theta, phi, psi, R1_initial, V_0));
					long double t2 = abs(time1_(z0, L_final, theta, V_0));



					long double t = min(t1, t2);
					//cout << t1 << "  " << t2<< "  " <<t<<  endl;
					func1("left", x0, y0, z0, r0, theta, phi, psi, x, y, z, r, t, V_0);
					//cout << x << "  " << y << "  " << z << "    " << r << endl;
					//break;
					continue;
				}

			}




			// частица внутри цилиндра
			if ((z > L_initial) && (z < L_final)) {


				//break;
				srand((unsigned int)time(NULL) + rand()); // привязка генератора случайных чисел к системному времени


				long double mu = random(0.0, 1.0); // случайное число для учета захвата частицы поверхностью цилиндра

				if (mu <= b_surface) {

					out = false;
					n4 = n4 + 1;
					//return;
					break;

				}

				else {

					if ((z0 = L_initial) || (z0 = L_final)) {
						theta0 = theta;
						phi0 = phi;
						psi0 = psi;
					}
					else {
						theta0 = M_PI_2 - theta;
						phi0 = atan2(-y0, x0);
						psi0 = phi;

					}

					x0 = x;
					y0 = y;
					z0 = z;
					r0 = r;

					//	cout << x0 << "  " << y0 << "  " << z0 << "    " << r0 << endl;

					if (theta0 <= theta_diffusion_surface) {
						srand((unsigned int)time(NULL) + rand()); // привязка генератора случайных чисел к системному времени
																  //theta_0 = acos(pow(1.0 - pow(random(0.0, 1.0), 2.0), 1.0 / 2.0)); // от -pi/2 до pi распределена по закону cos(), получена методом обратной функции
																  //theta_0 = asin(pow(random(0.0, 1.0), 1.0 / 2.0));
						theta = asin(random(0.0, 1.0));// от 0 до pi/2 распределена по закону cos(), получена методом обратной функции, максимум вероятности при theta=0

						srand((unsigned int)time(NULL) + rand()); // привязка генератора случайных чисел к системному времени
						phi = random(0.0, 2.0*M_PI); //от 0 до 2*pi равномерно распределена

						srand((unsigned int)time(NULL) + rand()); // привязка генератора случайных чисел к системному времени
						psi = random(0.0, 2.0*M_PI); //от 0 до 2*pi равномерно распределена

					}

					else {
						theta = theta0;
						phi = phi0;
						psi = psi - M_PI;

					}




					long double t1 = abs(time2(theta, psi, R1_initial, V_0));
					long double t2 = abs(time2_(z0, L_initial, theta, psi, V_0));
					long double t3 = abs(time2_(z0, L_final, theta, psi, V_0));





					//	long double t = min(t1, t2, t3);

					//	func2("right", x0, y0, z0, r0, theta, psi, x, y, z, r, t, V_0);

					//	cout << x << "  " << y << "  " << z << "    " << r << endl;



					if (cos(psi) > 0) {

						//	break;


						long double t = min(t1, t2);
						//cout << t1 << "  " << t2<< "  " <<t<<  endl;
						func2("right", x0, y0, z0, r0, theta, psi, x, y, z, r, t, V_0);
						if (z <= L_initial + 100.0*DBL_EPSILON) {
							z = L_initial; // из-за погрешоности вычеслений координата может быть немного меньше L_initial (10^-18)
						}

						if ((z > L_initial + 100.0*DBL_EPSILON) && (z < L_final - 100.0*DBL_EPSILON)) {

							r = R1_initial;
						}




						//	cout << x << "  " << y << "  " << z << "    " << r << endl;

						continue;
					}

					if (cos(psi) <= 0) {


						//break;



						long double t = min(t1, t3);
						//cout << t1 << "  " << t2<< "  " <<t<<  endl;
						func2("left", x0, y0, z0, r0, theta, psi, x, y, z, r, t, V_0);
						if (z >= L_final - 100.0*DBL_EPSILON) {
							z = L_final; // из-за погрешоности вычеслений координата может быть немного больше L_final (1*10^-18)
						}

						if ((z > L_initial + 100.0*DBL_EPSILON) && (z < L_final - 100.0*DBL_EPSILON)) {

							r = R1_initial;
						}

						//cout << x << "  " << y << "  " << z << "    " << r << endl;

						continue;

					}







					//cout << x << "  " << y << "  " << z << "    " << r << endl;



					//continue;

				}


			}






			//cout << x_out << "  " << y_out << "  " << z_out << "    " << r_out << endl;

		}
	}



	N1 = n1;
	N2 = n2;
	N3 = n3;
	N4 = n4;
	N5 = n5;

	return;


}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы
	cout << endl;
	cout << "Добро Пожаловать В Программу CYL.EXE" << endl;

	long double  R1_1 = 0.0, R2_1 = 0.0, R3_1 = 0.0, L_1 = 0.0, V_0 = 0.0;// начальные данные для первого цилиндра, радиус 1, радиус 2,радиус 3, длина цилиндра, начальная скорость
	long double  R1_2 = 0.0, R2_2 = 0.0, R3_2 = 0.0, L_2 = 0.0;// начальные данные для второго цилиндра, радиус 1, радиус 2,радиус 3, длина цилиндра
	long double R1_3 = 0.0, R2_3 = 0.0, R3_3 = 0.0, L_3 = 0.0;// начальные данные для третьего цилиндра, радиус 1, длина цилиндра, начальная скорость
	long double R1_4 = 0.0, R2_4 = 0.0, R3_4 = 0.0;// начальные данные для третьего цилиндра, радиус 1, длина цилиндра, начальная скорость
	int  N = 0, N_histo = 0; // начальное число частиц, число бинов гистограммы распределения
	long double R = 0.0; // максимальный радиус экрана

	long double b1_left = 0.0, b1_surface = 0.0, b1_right = 0.0;
	long double b2_left = 0.0, b2_surface = 0.0, b2_right = 0.0;
	long double b3_left = 0.0, b3_surface = 0.0, b3_right = 0.0; // коэффициент захвата частицы поверхность цилиндра

	int N_on = 0, N_off = 0;

	int N1_1 = 0, N2_1 = 0, N3_1 = 0, N4_1 = 0, N5_1 = 0, N6_1 = 0, N7_1 = 0; // _1_первый цилиндр
	int N1_2 = 0, N2_2 = 0, N3_2 = 0, N4_2 = 0, N5_2 = 0, N6_2 = 0, N7_2 = 0; // _2_второй цилиндр
	int N1_3 = 0, N2_3 = 0, N3_3 = 0, N4_3 = 0, N5_3 = 0, N6_3 = 0, N7_3 = 0; // _3_третий цилиндр

	int	n1 = 0, n2 = 0, n3 = 0; // если за это число ударов о стенки цилиндра частица из него не выходит, то считаем, что она осталась в нем жить вечно и переходим к рассмотрению следующей частице 
	int n_travel = 0;// если за это число переходов между цилиндрами частица не выходит,то считаем, что частица осталась жить между цилиндрами вечно, переходим к рассмотрению следующей частице 

	long double t = 0.0;


	long double theta1_diffusion_left = 0.0, theta1_diffusion_surface = 0.0, theta1_diffusion_right = 0.0;
	long double theta2_diffusion_left = 0.0, theta2_diffusion_surface = 0.0, theta2_diffusion_right = 0.0;
	long double theta3_diffusion_left = 0.0, theta3_diffusion_surface = 0.0, theta3_diffusion_right = 0.0;


	//	N1  число частиц, вылетевших с левого торца цилинлра
	//	N2  число частиц, вылетевших с правого торца цилинлра
	//	N3  число частиц, захваченных левым торцом цилинлра
	//	N4  число частиц, захваченных образующей цилинлра
	//	N5  число частиц, захваченных правым торцом цилинлра																  


	int N_histo_source = 0; //число бинов гистограммы распределения
	long double	R_source = 0.0;

	// переменные для подсчета числа частиц
// объявление одномерного динамического массива на n элементов входных начальных данных:										   
	int n = 44;
	long double *mass = new long double[n]; // одномерный массив входных параметров

	for (int i = 0; i < n; i = i + 1) {
		mass[i] = 0.0;
	}


	//открываем файл с входными данными в режиме чтения
	cout << endl;
	cout << "Открытие файла с входными данными..." << endl;
	FILE *F;
	fopen_s(&F, "in.txt", "r");


	//если открытие файла прошло некорректно, то вывод
	//сообщения об отсутствии такого файла
	if (F == NULL) {
		fprintf(stderr, "Ошибка открытия выводного файла.\n");
		cout << endl;
		Sleep(800); // пауза для того, чтобы успеть прочитать информацию
		exit(1);
	}


	else {

		cout << "Чтение данных..." << endl;
		cout << endl;

		setlocale(LC_ALL, "C"); // установить используемую системой локаль для корректной отображении точки в выходном файле

		int i = 0; // индекс массива

		const int SIZE = n;
		const int MAX_SIZE = 255;

		char **str = new char*[SIZE];
		for (int i = 0; i < SIZE; i++) {
			str[i] = new char[MAX_SIZE];
		}



		//цикл для чтения значений из файла; выполнение цикла прервется,
		//когда достигнем конца файла, в этом случае F.eof() вернет истину.
		while (!feof(F)) {
			//while(	fscanf_s(F, "%Lf", &mass[i]) != EOF)

			Sleep(100); // пауза для того, чтобы успеть прочитать информацию
						//чтение очередного значения из потока F в переменную mass
			cout << " .";

			if (i == (int)(n / 2)) {
				cout << endl;
			}



			//чтение очередного значения из потока F в переменную mass
			fscanf_s(F, "%Lf // %s", &mass[i], str[i], MAX_SIZE + 1); /* чтение из файла */
			//fscanf_s(F, "%Lf", &mass[i]); /* чтение из файла */

			i = i + 1;

		}

		for (i = 0; i < SIZE; i++) {
			delete[] str[i];
		}

		delete[] str;

		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

		cout << endl;
		cout << endl;
		cout << "Чтение данных завершено." << endl;

	}


	//закрытие потока

	fclose(F);




	// присваиваем данные из входного файла начальным константам задачи


	// первый цилиндр
	R1_1 = mass[0]; // большой радиус цилиндра
	R2_1 = mass[1]; // внешний радиус кольца
	R3_1 = mass[2]; // внутренний радиус кольца
	L_1 = mass[3]; // длина цилиндра


	// второй цилиндр
	R1_2 = mass[4]; // большой радиус цилиндра
	R2_2 = mass[5]; // внешний радиус кольца
	R3_2 = mass[6]; // внутренний радиус кольца
	L_2 = mass[7]; // длина цилиндра

	// третий цилиндр
	R1_3 = mass[8]; // большой радиус цилиндра
	R2_3 = mass[9]; // внешний радиус кольца
	R3_3 = mass[10]; // внутренний радиус кольца
	L_3 = mass[11]; // длина цилиндра


	R1_4 = mass[12]; // большой радиус цилиндра
	R2_4 = mass[13]; // внешний радиус кольца
	R3_4 = mass[14]; // внутренний радиус кольца


	b1_left = mass[15];
	b1_surface = mass[16];
	b1_right = mass[17];
	b2_left = mass[18];
	b2_surface = mass[19];
	b2_right = mass[20];
	b3_left = mass[21];
	b3_surface = mass[22];
	b3_right = mass[23];

	V_0 = mass[24]; // начальная скорость
	N = (int)mass[25]; // число частиц
	N_histo = (int)mass[26]; //число бинов гистограммы распределения
	R = mass[27];

	n1 = (int)mass[28];
	n2 = (int)mass[29];
	n3 = (int)mass[30];
	n_travel = (int)mass[31];

	t = mass[32];



	theta1_diffusion_left = mass[33];
	theta1_diffusion_surface = mass[34];
	theta1_diffusion_right = mass[35];

	theta2_diffusion_left = mass[36];
	theta2_diffusion_surface = mass[37];
	theta2_diffusion_right = mass[38];

	theta3_diffusion_left = mass[39];
	theta3_diffusion_surface = mass[40];
	theta3_diffusion_right = mass[41];

	R_source = mass[42]; // радиус кольца детектора
	N_histo_source = (int)mass[43]; //число точек, измеренных детектором


	// вывод начальных значений на экран

	cout << endl;
	cout << "Входные данные:" << endl;

	cout << endl;
	cout << "------------------------------" << endl;
	cout << endl;
	cout << "Начальные данные" << endl;
	cout << endl;
	cout << "Скорость ||" << " Число Частиц ||" << " Число Бинов ||" << " Радиус Экрана" << " Максимальное время счета (мин.)" << endl;
	cout << endl;
	printf("%.2f\t  %.2e\t %.0f\t %.2f\t %.2f\n", V_0, (long double)N, (long double)N_histo, R, t);

	cout << endl;
	cout << "Первый цилиндр" << endl;
	cout << "Коэфф. Захвата 1 левый ||" << " Коэфф. Захвата 1 поверхность ||" << " Коэфф. Захвата 1 правый" << endl;
	printf("%.2f\t  %.2f\t %.2f\n", b1_left, b1_surface, b1_right);
	cout << endl;
	cout << "Второй цилиндр" << endl;
	cout << "Коэфф. Захвата 2 левый ||" << " Коэфф. Захвата 2 поверхность ||" << " Коэфф. Захвата 2 правый" << endl;
	printf("%.2f\t  %.2f\t %.2f\n", b2_left, b2_surface, b2_right);
	cout << endl;
	cout << "Третий цилиндр" << endl;
	cout << "Коэфф. Захвата 3 левый ||" << " Коэфф. Захвата 3 поверхность ||" << " Коэфф. Захвата 3 правый" << endl;
	printf("%.2f\t  %.2f\t %.2f\n", b3_left, b3_surface, b3_right);
	cout << endl;


	printf("(Цилиндр №1) Дифф. Угол Левого торца = %.2f Дифф. Угол Поверхности Образующей = %.2f Дифф. Угол Правого торца = %.2f\n", theta1_diffusion_left, theta1_diffusion_surface, theta1_diffusion_surface);
	printf("(Цилиндр №2) Дифф. Угол Левого торца = %.2f Дифф. Угол Поверхности Образующей = %.2f Дифф. Угол Правого торца = %.2f\n", theta2_diffusion_left, theta2_diffusion_surface, theta2_diffusion_surface);
	printf("(Цилиндр №3) Дифф. Угол Левого торца = %.2f Дифф. Угол Поверхности Образующей = %.2f Дифф. Угол Правого торца = %.2f\n", theta3_diffusion_left, theta3_diffusion_surface, theta3_diffusion_surface);

	cout << endl;
	printf("(Цилиндр №1) Максимальное число столкновений о стенки = %.0f\n", (long double)n1);
	printf("(Цилиндр №2) Максимальное число столкновений о стенки = %.0f\n", (long double)n2);
	printf("(Цилиндр №3) Максимальное число столкновений о стенки = %.0f\n", (long double)n3);
	printf("Максимальное число переходов частицы между цилиндрами №1,2,3 = %.0f\n", (long double)n_travel);

	//for (int i = 10; i <= 13; i++) {
	//	cout << mass[i] << "  \t";

	//}
	Sleep(250); // пауза для того, чтобы успеть прочитать информацию
	cout << endl;
	cout << endl;
	cout << "------------------------------" << endl;
	cout << endl;
	cout << "Первый цилиндр" << endl;
	cout << endl;
	cout << "R1_1 ||" << " R2_1 ||" << " R3_1 ||" << " L_1" << endl;
	cout << endl;
	for (int i = 0; i <= 3; i++) {
		cout << mass[i] << "  \t";

	}
	Sleep(250); // пауза для того, чтобы успеть прочитать информацию
	cout << endl;
	cout << endl;
	cout << "------------------------------" << endl;
	cout << endl;
	cout << "Второй цилиндр" << endl;
	cout << endl;
	cout << "R1_2 ||" << " R2_2 ||" << " R3_2 ||" << " L_2" << endl;
	cout << endl;
	for (int i = 4; i <= 7; i++) {
		cout << mass[i] << "  \t";

	}
	Sleep(250); // пауза для того, чтобы успеть прочитать информацию
	cout << endl;
	cout << endl;
	cout << "------------------------------" << endl;
	cout << endl;
	cout << "Третий цилиндр" << endl;
	cout << endl;
	cout << "R1_3 ||" << " R2_3 ||" << " R3_3 ||" << " L_3" << endl;
	cout << endl;
	for (int i = 8; i <= 11; i++) {
		cout << mass[i] << "  \t";

	}
	cout << endl;
	cout << endl;
	cout << "R1_4 ||" << " R2_4 ||" << " R3_4" << endl;
	cout << endl;
	for (int i = 12; i <= 14; i++) {
		cout << mass[i] << "  \t";

	}

	cout << endl;
	cout << endl;
	cout << "------------------------------" << endl;

	Sleep(250); // пауза для того, чтобы успеть прочитать информацию


	cout << endl;
	printf("Радиус кольца детектора = %.2f\n", R_source);
	printf("Число точек, измеренных детектором = %.0f\n", (long double)N_histo_source);


	cout << endl;
	cout << "------------------------------" << endl;

	//Sleep(250); // пауза для того, чтобы успеть прочитать информацию
	cout << endl;





	// массив для функцию распределения(гистограммы) числа частиц, попавших в бины гистограммы
	// объявление двумерного динамического массива на N_histo*2 элементов:
	// массивколичества частиц попавших в каждый бин, всего бинов N_histo, второй столбец двумерного массива это координата левого конца бина
	long double **mass_histo_x = new long double*[N_histo]; // N_histo строк в массиве
	for (int count = 0; count < arrlen(mass_histo_x); count++)
		mass_histo_x[count] = new long double[2]; // и два столбца
										   //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double

	long double h_x = 2.0*R / N_histo; // ширина бина

								   // заполнение массива
	for (int count_row = 0; count_row < arrlen(mass_histo_x); count_row++) {
		mass_histo_x[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_x[count_row][1] = -1.0*R + 1.0*h_x*count_row; // второй столбец это координата левого конца бина

	}



	long double **mass_histo_r = new long double*[(int)(N_histo / 2)]; // N_histo строк в массиве
	for (int count = 0; count < arrlen(mass_histo_r); count++) {
		mass_histo_r[count] = new long double[2]; // и два столбца
											 //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double

	}
	long double h_r = 2.0*R / (N_histo); // ширина бина

								 // заполнение массива
	for (int count_row = 0; count_row < arrlen(mass_histo_r); count_row++) {
		mass_histo_r[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_r[count_row][1] = h_r*count_row; // второй столбец это координата левого конца бина

	}











	// массив для функцию распределения(гистограммы) числа частиц, попавших в бины гистограммы
	// объявление двумерного динамического массива на N_histo*2 элементов:
	// массивколичества частиц попавших в каждый бин, всего бинов N_histo, второй столбец двумерного массива это координата левого конца бина
	long double **mass_histo_x_source = new long double*[N_histo_source]; // N_histo строк в массиве
	for (int count = 0; count < arrlen(mass_histo_x_source); count++)
		mass_histo_x_source[count] = new long double[2]; // и два столбца
												  //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double

	long double h_x_source = 2.0*R / N_histo_source; // ширина бина

									   // заполнение массива
	for (int count_row = 0; count_row < arrlen(mass_histo_x_source); count_row++) {
		mass_histo_x_source[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_x_source[count_row][1] = -1.0*R + 1.0*h_x_source*count_row; // второй столбец это координата левого конца бина

	}



	long double **mass_histo_r_source = new long double*[(int)(N_histo_source / 2)]; // N_histo строк в массиве
	for (int count = 0; count < arrlen(mass_histo_r_source); count++) {
		mass_histo_r_source[count] = new long double[2]; // и два столбца
												  //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double

	}
	long double h_r_source = 2.0*R / (N_histo_source); // ширина бина

										 // заполнение массива
	for (int count_row = 0; count_row < arrlen(mass_histo_r_source); count_row++) {
		mass_histo_r_source[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_r_source[count_row][1] = h_r_source*count_row; // второй столбец это координата левого конца бина

	}










//	Sleep(500); // пауза для того, чтобы успеть прочитать информацию
//	cout << endl;
	//cout << "Условные обозначения:" << endl;
	//cout << endl;
	//cout << "......\t " << "Частицы, которые сразу вышли из усточника и не коснулись стенок," << endl;
	//cout << "++++++\t " << "Частицы, которые хотя бы раз коснулись стенок и вышли из источника." << endl;
	//cout << endl;
	//Sleep(500); // пауза для того, чтобы успеть прочитать информацию


	Sleep(500); // пауза для того, чтобы успеть прочитать информацию
	cout << "Нажми на клавишу Yes для отображения данных во время расчета" << endl;
	cout << "ИЛИ" << endl;
	cout << "Нажми на клавишу No для неотображения данных во время расчета" << endl;


	bool console_out = true;

	while (true) {

		//cout << " .";
		//Sleep(400); // пауза для того, чтобы успеть прочитать информацию


		if ((_getch() == 0x59) || (_getch() == 0x79) || (_getch() == 0x8D) || (_getch() == 0xAD)) //YES
		{

			cout << endl;
			cout << "Вы нажали Yes." << endl;
			cout << endl;
			cout << "Далее будут выводится столбцы с информацие о частицах на вылете из цилиндра...." << endl;
			cout << endl;
			cout << "X ||" << " Y ||" << " Z ||" << " R ||" << " № частицы ||" << " % выполнения программы ||" << " время с начала счета, сек" << endl;
			cout << endl;
			console_out = true;

			break;
		}

		if ((_getch() == 0x4E) || (_getch() == 0x6E) || (_getch() == 0x92) || (_getch() == 0xB2)) // NO
		{

			cout << endl;
			cout << "Вы нажали No." << endl;
			cout << endl;
			cout << "Промежуточные данные не будут выводится на экран" << endl;
			cout << endl;
			console_out = false;

			break;
		}

		else {
			cout << endl;
			cout << "Вы нажали какую то клавишу другую клавишу, повторите попытку снова..." << endl;
			//	cout << endl;

		}

		cout << endl;
		continue;
	}

	cout << endl;
	Sleep(200); // пауза для того, чтобы успеть прочитать информацию
	cout << "Нажми на клавишу ENTER для продолжения расчетов." << endl;

	while (true) {

		//cout << " .";
		//Sleep(400); // пауза для того, чтобы успеть прочитать информацию


		if (_getch() == VK_RETURN)
		{

			cout << endl;
			cout << "Вы нажали ENTER." << endl;

			break;
		}
		else {
			cout << endl;
			cout << "Вы нажали какую то клавишу, но точно не enter, повторите попытку снова..." << endl;
			//	cout << endl;

		}





		cout << endl;
		continue;

	}













	Sleep(800); // пауза для того, чтобы успеть прочитать информацию

	cout << endl;
	printf("Идет расчет... Пожалуйста,Ждите... Примерное время счета равно=%.3f мин.\n", (long double)(N * 20.0) / (pow(10.0, 6.0) * 60));
	//cout << "Идет расчет... Ждите...Примерное время счета равно=" << N*20/(pow(10.0,5.0)*60)<< "мин."<< endl;
	cout << endl;
	Sleep(800); // пауза для того, чтобы успеть прочитать информацию

	unsigned int start_time = clock(); // начальное время
#pragma omp parallel
	{
#pragma omp for // распараллеливание большого цикла на многопоточность



		unsigned int end_time = clock(); // конечное время
		unsigned int search_time = end_time - start_time; // искомое время в миллисекундах
		double search_time_ = search_time / (1000.0 * 60.0); // минут



		for (int ii = 1; (ii <= N) && (search_time_ <= t); ii = ii + 1) {




			srand((unsigned int)time(NULL) + rand()); // привязка генератора случайных чисел к системному времени

			long double r_in = pow(random(pow(R3_1, 2.0), pow(R2_1, 2.0)), 1.0 / 2.0);
			long double phi = random(0.0, 2.0*M_PI);
			long double x_in = r_in*cos(phi);
			long double y_in = r_in*sin(phi);
			// генерируем случайные величины с помощью пользовательской функции random()
		//	long double x_in = random(-R1_1, R1_1); // от -R1_1 до R1_1
			srand((unsigned int)time(NULL) + rand()); // привязка генератора случайных чисел к системному времени
		//	long double y_in = random(-R1_1, R1_1); // от -R1 до R1


			long double z_in = 0.0; // частицы вылетают из левого торца цилиндра
		//	long double r_in = pow(pow(x_in_1, 2.0) + pow(y_in_1, 2.0), 1.0 / 2.0); // начальный радиус

		//	cout << x_in << "  " << y_in << "  " << z_in << "    " << r_in << endl;







			if ((r_in <= R2_1) && (r_in >= R3_1)) {

				N_on = N_on + 1;



				long double	x_in_1 = x_in, y_in_1 = y_in, z_in_1 = z_in, r_in_1 = r_in, theta_in_1 = 0.0, phi_in_1 = 0.0, psi_in_1 = 0.0;
				long double	x_in_2 = 0.0, y_in_2 = 0.0, z_in_2 = 0.0, r_in_2 = 0.0, theta_in_2 = 0.0, phi_in_2 = 0.0, psi_in_2 = 0.0;
				long double	x_in_3 = 0.0, y_in_3 = 0.0, z_in_3 = 0.0, r_in_3 = 0.0, theta_in_3 = 0.0, phi_in_3 = 0.0, psi_in_3 = 0.0;


				long double	x_out_1 = 0.0, y_out_1 = 0.0, z_out_1 = 0.0, r_out_1 = 0.0, theta_out_1 = 0.0, phi_out_1 = 0.0, psi_out_1 = 0.0;
				long double	x_out_2 = 0.0, y_out_2 = 0.0, z_out_2 = 0.0, r_out_2 = 0.0, theta_out_2 = 0.0, phi_out_2 = 0.0, psi_out_2 = 0.0;
				long double	x_out_3 = 0.0, y_out_3 = 0.0, z_out_3 = 0.0, r_out_3 = 0.0, theta_out_3 = 0.0, phi_out_3 = 0.0, psi_out_3 = 0.0;




				// углы внутри первого цилиндра

				// начальные углы вылета
				srand((unsigned int)time(NULL) + rand()); // привязка генератора случайных чисел к системному времени
				theta_in_1 = asin(random(0.0, 1.0));// от 0 до pi/2 распределена по закону cos(theta), получена методом обратной функции, максимум вероятности при theta=0
				srand((unsigned int)time(NULL) + rand()); // привязка генератора случайных чисел к системному времени
				phi_in_1 = random(0.0, 2.0*M_PI); //от 0 до 2*pi равномерно распределена
				srand((unsigned int)time(NULL) + rand()); // привязка генератора случайных чисел к системному времени
				psi_in_1 = random(0.0, 2.0*M_PI); //от 0 до 2*pi равномерно распределена

				bool out1 = true, out2 = true, out3 = true;



				cyl(x_in_1, y_in_1, z_in_1, r_in_1, theta_in_1, phi_in_1, psi_in_1, x_out_1, y_out_1, z_out_1, r_out_1, theta_out_1, phi_out_1, psi_out_1, N1_1, N2_1, N3_1, N4_1, N5_1, 0.0, L_1, R1_1, R2_1, R3_1, R1_1, R2_2, R3_2, b1_left, b1_surface, b1_right, V_0, out1, n1, theta1_diffusion_left, theta1_diffusion_surface, theta1_diffusion_right);
				//	cout << x_out_1 << "  " << y_out_1 << "  " << z_out_1 << "    " << r_out_1 << endl;



				for (int i = 1; i <= n_travel; i = i + 1) {


					//	bool out1 = true, out2 = true, out3 = true;


					if (out1 == false) {

						break;
					}


					if ((out1 == true) && (z_out_1 == 0.0)) {


						break;


					}



					if ((out1 == true) && (z_out_1 == L_1)) {

						//	printf("%+.3f %+.3f %.3f %.3f\n", x_out_1, y_out_1, z_out_1, r_out_1 );


						x_in_2 = x_out_1;
						y_in_2 = y_out_1;
						z_in_2 = z_out_1;
						r_in_2 = r_out_1;
						theta_in_2 = theta_out_1;
						phi_in_2 = phi_out_1;
						psi_in_2 = psi_out_1;

						cyl(x_in_2, y_in_2, z_in_2, r_in_2, theta_in_2, phi_in_2, psi_in_2, x_out_2, y_out_2, z_out_2, r_out_2, theta_out_2, phi_out_2, psi_out_2, N1_2, N2_2, N3_2, N4_2, N5_2, L_1, L_1 + L_2, R1_2, R2_2, R3_2, R1_2, R2_3, R3_3, b2_left, b2_surface, b2_right, V_0, out2, n2, theta2_diffusion_left, theta2_diffusion_surface, theta2_diffusion_right);



					}

					if (out2 == false) {

						break;
					}


					if ((out2 == true) && (z_out_2 == L_1)) {


						x_in_1 = x_out_2;
						y_in_1 = y_out_2;
						z_in_1 = z_out_2;
						r_in_1 = r_out_2;
						theta_in_1 = theta_out_2;
						phi_in_1 = phi_out_2;
						psi_in_1 = psi_out_2;

						cyl(x_in_1, y_in_1, z_in_1, r_in_1, theta_in_1, phi_in_1, psi_in_1, x_out_1, y_out_1, z_out_1, r_out_1, theta_out_1, phi_out_1, psi_out_1, N1_1, N2_1, N3_1, N4_1, N5_1, 0.0, L_1, R1_1, R2_1, R3_1, R1_1, R2_2, R3_2, b1_left, b1_surface, b1_right, V_0, out1, n1, theta1_diffusion_left, theta1_diffusion_surface, theta1_diffusion_right);


						continue;






					}





					if ((out2 == true) && (z_out_2 == L_1 + L_2)) {


						x_in_3 = x_out_2;
						y_in_3 = y_out_2;
						z_in_3 = z_out_2;
						r_in_3 = r_out_2;
						theta_in_3 = theta_out_2;
						phi_in_3 = phi_out_2;
						psi_in_3 = psi_out_2;
						//cout << x_in_3 << "  " << y_in_3 << "  " << z_in_3 << "    " << r_in_3 << endl;


						cyl(x_in_3, y_in_3, z_in_3, r_in_3, theta_in_3, phi_in_3, psi_in_3, x_out_3, y_out_3, z_out_3, r_out_3, theta_out_3, phi_out_3, psi_out_3, N1_3, N2_3, N3_3, N4_3, N5_3, L_1 + L_2, L_1 + L_2 + L_3, R1_3, R2_3, R3_3, R1_3, R2_4, R3_4, b3_left, b3_surface, b3_right, V_0, out3, n3, theta3_diffusion_left, theta3_diffusion_surface, theta3_diffusion_right);

						//	cout << x_out_3 << "  " << y_out_3 << "  " << z_out_3 << "    " << r_out_3 << endl;
						//	out1 = false;
						//	out2 = false;

						//	continue;

					}







					if (out3 == false) {
						break;

					}


					if ((out3 == true) && (z_out_3 == L_1 + L_2)) {



						x_in_2 = x_out_3;
						y_in_2 = y_out_3;
						z_in_2 = z_out_3;
						r_in_2 = r_out_3;
						theta_in_2 = theta_out_3;
						phi_in_2 = phi_out_3;
						psi_in_2 = psi_out_3;
						//cout << x_in_3 << "  " << y_in_3 << "  " << z_in_3 << "    " << r_in_3 << endl;

						cyl(x_in_2, y_in_2, z_in_2, r_in_2, theta_in_2, phi_in_2, psi_in_2, x_out_2, y_out_2, z_out_2, r_out_2, theta_out_2, phi_out_2, psi_out_2, N1_2, N2_2, N3_2, N4_2, N5_2, L_1, L_1 + L_2, R1_2, R2_2, R3_2, R1_2, R2_3, R3_3, b2_left, b2_surface, b2_right, V_0, out2, n2, theta2_diffusion_left, theta2_diffusion_surface, theta2_diffusion_right);



						continue;

					}



					if ((out3 == true) && (z_out_3 == L_1 + L_2 + L_3)) {




						if (console_out == true) {

							double procent = ((double)ii / N)*100.0;
							unsigned int end_time = clock(); // текущее время
							unsigned int search_time = end_time - start_time; // искомое время в миллисекундах
							printf("%+.3f %+.3f %.3f %.3f %.3e %.3f %.2f\n", x_out_3, y_out_3, z_out_3, r_out_3, (double)ii, procent, (double)search_time / 1000.0);
							//cout << x_out_3 << "  " << y_out_3 << "  " << z_out_3 << "    " << r_out_3 << endl;
						}







						mass_histo_x = histo_x("histo", mass_histo_x, N_histo, x_out_3, y_out_3, R, R_source);
						mass_histo_r = histo_r("histo", mass_histo_r, (int)(N_histo / 2), x_out_3, y_out_3, R, R_source);


						mass_histo_x_source = histo_x("source", mass_histo_x_source, N_histo_source, x_out_3, y_out_3, R, R_source);
						mass_histo_r_source = histo_r("source", mass_histo_r_source, (int)(N_histo_source / 2), x_out_3, y_out_3, R, R_source);


						break;

					}




				}



			}

			else {

				N_off = N_off + 1;
				continue;
			}


			end_time = clock(); // конечное время
			search_time = end_time - start_time; // искомое время в миллисекундах
			search_time_ = search_time / (1000.0 * 60.0); // минут

		}


	}

	Sleep(800); // пауза для того, чтобы успеть прочитать информацию

	if (console_out == true) {


		cout << endl;
		cout << "Выходные данные: Гистограмма распределения по радиусу" << endl;
		cout << endl;
		cout << "Первый столбец: Число частиц, попавших в бин ||" << " Второй столбец: Координата левого конца бина" << endl;
		cout << endl;

		Sleep(800); // пауза для того, чтобы успеть прочитать информацию

		mass_histo_out(mass_histo_x);

	}








	WORD ATTR = FOREGROUND_BLUE;
	HANDLE CH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(CH, ATTR);
	cout << endl;
	//	printf("Полное число частиц брошенных в квадрат, описанный вокруг торца цилиндра %.1e\n", (long double)N);
	//	printf("Число частиц, которые не вышли из квадрата в источник %.1e\n", (long double)N4);
		//cout << "Число частиц выпущенных из кольца источником " << N1 << endl;
	//	printf("Полное число частиц выпущенных из кольца источником  %.1e\n", (long double)N);

	//	cout << "Полное число частиц, которые вышли из цилиндра " << N2 << endl;
	//	cout << "Число частиц, которые вернулись обратно в источник " << N3 << endl;
	//	cout << "Число частиц, которые были захвачены поверхностью цилиндра " << N7 << endl;
	cout << endl;
	//	cout << "Число частиц, которые сразу вышли из усточника и не коснулись стенок " << N5 << endl;
	//	cout << "Число частиц, которые хотя бы раз коснулись стенок и вышли из источника " << N6 << endl;
	cout << endl;
	//	cout << "N_out/N_in=" << ((long double)N2 / (long double)N1) << endl;
	cout << "L_3/R_2=" << ((long double)L_3 / (long double)R1_2) << endl;
	//	cout << "k=(N_out/N_in)/(L_3/R_3)=" << ((long double)N2 / (long double)N1) / ((long double)L_3 / (long double)R1_3) << endl;
	cout << endl;

	ATTR = FOREGROUND_GREEN;

	SetConsoleTextAttribute(CH, ATTR);





	unsigned int end_time = clock(); // конечное время
	unsigned int search_time = end_time - start_time; // искомое время в миллисекундах
	unsigned int search_time_ = (int)(search_time / (1000.0 * 60.0)); // минут
	unsigned int search_time__ = (int)(search_time / 1000.0) % 60; // секунд

	int normalization_x = 0; // число частиц для нормировки гитограммы, урседеннной по детектору
	int normalization_r = 0; // число частиц для нормировки гитограммы, урседеннной по детектору

	int normalization_x_source = 0; // число частиц для нормировки гитограммы, урседеннной по детектору
	int normalization_r_source = 0; // число частиц для нормировки гитограммы, урседеннной по детектору


	for (int i = 0; i < arrlen(mass_histo_x_source); i = i + 1) {
		normalization_x_source = normalization_x_source +(int) mass_histo_x_source[i][0];
	}

	for (int i = 0; i < arrlen(mass_histo_r_source); i = i + 1) {
		normalization_r_source = normalization_r_source + (int)mass_histo_r_source[i][0];
	}


	for (int i = 0; i < arrlen(mass_histo_x); i = i + 1) {
		normalization_x = normalization_x + (int)mass_histo_x[i][0];
	}

	for (int i = 0; i < arrlen(mass_histo_r); i = i + 1) {
		normalization_r = normalization_r + (int)mass_histo_r[i][0];
	}

	out_txt("out.txt", mass_histo_x, mass_histo_r, start_time, end_time, R1_1, R2_1, R3_1, L_1, V_0, R1_2, R2_2, R3_2, L_2, R1_3, R2_3, R3_3, L_3, R1_4, R2_4, R3_4, N, N_histo, R, b1_left, b1_surface, b1_right, b2_left, b2_surface, b2_right, b3_left, b3_surface, b3_right, N_on, N_off, N1_1, N2_1, N3_1, N4_1, N5_1, N6_1, N7_1, N1_2, N2_2, N3_2, N4_2, N5_2, N6_2, N7_2, N1_3, N2_3, N3_3, N4_3, N5_3, N6_3, N7_3, n1, n2, n3, n_travel, t, theta1_diffusion_left, theta1_diffusion_surface, theta1_diffusion_right, theta2_diffusion_left, theta2_diffusion_surface, theta2_diffusion_right, theta3_diffusion_left, theta3_diffusion_surface, theta3_diffusion_right, R_source, N_histo_source, normalization_x, normalization_r);

	out_txt("out_source.txt", mass_histo_x_source, mass_histo_r_source, start_time, end_time, R1_1, R2_1, R3_1, L_1, V_0, R1_2, R2_2, R3_2, L_2, R1_3, R2_3, R3_3, L_3, R1_4, R2_4, R3_4, N, N_histo, R, b1_left, b1_surface, b1_right, b2_left, b2_surface, b2_right, b3_left, b3_surface, b3_right, N_on, N_off, N1_1, N2_1, N3_1, N4_1, N5_1, N6_1, N7_1, N1_2, N2_2, N3_2, N4_2, N5_2, N6_2, N7_2, N1_3, N2_3, N3_3, N4_3, N5_3, N6_3, N7_3, n1, n2, n3, n_travel, t, theta1_diffusion_left, theta1_diffusion_surface, theta1_diffusion_right, theta2_diffusion_left, theta2_diffusion_surface, theta2_diffusion_right, theta3_diffusion_left, theta3_diffusion_surface, theta3_diffusion_right, R_source, N_histo_source,normalization_x_source, normalization_r_source);


	cout << "Данные выведены в файл" << endl;
	cout << endl;

	cout << "Время выполнения расчета: " << search_time_ << " мин. и " << search_time__ << " сек." << endl;
	cout << endl;


	delete[] mass; // высвобождение памяти одномерного динамического массива


	system("pause");
	return 0;
}



