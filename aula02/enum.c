#include <stdio.h>

enum Status { LOW, MEDIUM, HIGH };
enum Semana { Seg = 1, Ter, Qua, Qui, Sex, Sab, Dom };

int main() {
    enum Status resultado = MEDIUM;
    enum Semana dia = Ter;
    ...

