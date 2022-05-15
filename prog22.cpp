/* Autor: Andriks Imanol Ruiz M�rtinez, Realizado: 03/03/2022
Escuela: Universidad del Valle de Mexico Campus Villahermosa
Materia: Programaci�n Estructrada
Ciclo: 01/2022

Este es un programa de  funciones, condicionales y ciclos en Lenguaje C de la materia de Programaci�n Estructurada
Muestra el uso de:

    -Variables flotantes y enteros</li>
    -printf para mostrar mensajes y variables
    -scanf
    -Funciones
    -for
    -Prototipos
    -Condicionales
    -El uso de include para las librerias
    -Comentarios para la documentaci�n interna del programa
*/
#include<stdio.h>
//prototipos
float liquidacion(float salarioQ, float ant,float isr, float salarioMin);
//Main
int main() {
	//Declaraci�n de variables
	int empleados;
	float liq, salario, antiguedad, impuesto, salarioMinimo;
	//Proceso
	printf("Introduce la cantidad de empleados: ");
	scanf("%d",&empleados);
	printf("Introduce el salario minimo actual: $");
	scanf("%f",&salarioMinimo);
	for(int i=1; i<= empleados; i++){ //Ciclo
		printf("Empleado #%d \n", i);
		printf("Salario quincenal: $");
		scanf("%f",&salario);
		printf("Antiguedad en a�os: ");
		scanf("%f",&antiguedad);
		printf("ISR: ");
		scanf("%f",&impuesto);
		liq= liquidacion(salario, antiguedad, impuesto, salarioMinimo);
		//Salida
		printf("Liquidacion neta: $%.2f\n", liq);	
	}
	return 0;
}
//Funciones
float liquidacion(float salarioQ, float ant,float isr, float salarioMin){
	float bonoLiquidacion, salarioP, pago20, primaAnt,liqBruto, exento, grabable, impuesto, liqNeta;
	//Proceso
	bonoLiquidacion=salarioQ*6; //Se le paga un bono de liquidaci�n de 3 meses de salario
	//salarioP= (salarioQ/15 > salarioMin*2) ? salarioQ/15 : salarioMin;
	if (salarioQ/5 > salarioMin*2){ //Condicionales
		salarioP=salarioQ/15;
	}
	else {
		salarioP=salarioMin;
	}
	pago20=salarioP*20*ant; // Se le paga 20 dias de salario ponderado por cada a�o de antig�edad
	primaAnt=salarioQ/15*12/ant; // Se le da una prima de antig�edad de 12 d�as.
	liqBruto=bonoLiquidacion+pago20+primaAnt;
	exento=90*salarioMin*ant; //Se le exenta la cantidad de 90 salario m�nimos por cada a�o trabajado
	grabable=liqBruto-exento;
	impuesto=grabable*isr;
	liqNeta=liqBruto-impuesto;
	return liqNeta;
}


