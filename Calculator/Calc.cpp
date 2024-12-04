#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
using namespace std;
void help() {
cout << "Возможные параметры калькулятора:\n"
<< "'-u' - умножение\n"
<< "'-d' - деление\n"
<< "кол-во операндов: 3-5\n";
exit(1);
}
int main(int argc, char **argv) {
int K = 0;
float a = 0.0f, a1 = 0.0f, a2 = 1.0f; // Изменено тип для работы с дробными числами
for (int i = 1; i < argc; i++) {
// Пробуем конвертировать строку в float
a = strtof(argv[i], nullptr);
if (a != 0.0f && K == 0) {
a1 = a;
K = 1;
continue;
}
if (a != 0.0f && K != 0) {
a2 *= a;
K += 1;
}
}
if (K < 3 || K > 5) {
help();
}
int opt, sd = 0;
while ((opt = getopt(argc, argv, "ud")) != -1) {
switch (opt) {
case 'u':
if (sd == 0) {
sd += 1;
cout << "Произведение: " << a1 * a2 << endl;
}
break;
case 'd':
if (sd == 0) {
if (a2 != 0.0f) { // Защита от деления на ноль
cout << "Частное: " << a1 / a2 << endl;
} else {
cout << "Ошибка: Деление на ноль!" << endl;
}
sd += 1;
}
break;
}
}
if (sd == 0) {
help();
}
}
