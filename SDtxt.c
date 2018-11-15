#include "r_cg_macrodriver.h"
#include "r_cg_cgc.h"
#include "r_cg_port.h"
#include "r_cg_serial.h"
#include "r_cg_rtc.h"
#include "r_cg_it.h"
#include "ff.h"
#include <stdio.h>

extern volatile int8_t Diarray[];
extern volatile int8_t Mesrray[];
extern volatile int nameflag;
extern FATFS FatFs;
extern FIL Fil;
char nombre[]="00Ene.txt";
uint16_t bw;

void CreatetxtSD(void){
    f_mount(&FatFs, "", 0);		/* Give a work area to the default drive */
    while (nameflag==0){;}
    strcpy(nombre, Diarray);
    strcat(nombre, Mesrray);
    strcat(nombre, ".txt");


    if (f_open(&Fil, nombre, FA_WRITE | FA_CREATE_ALWAYS) == FR_OK) {
    	char text[]="Fecha\tTemperatura\tHumedad\tSerial";
    	f_write(&Fil, text ,sizeof(text),bw);
    	//f_printf(&	Fil, "Fecha\tTemperatura\tHumedad\tSerial");
    	f_close(&Fil);}
	return;}

void WritetxtSD(char time[], int temp, int hume, int serial){
	int holi=5;
	if (f_open(&Fil, nombre, FA_WRITE | FA_OPEN_APPEND) == FR_OK) {
			char texto[]="\r\n00/00/00 00:00:00\t000 ";
			strcpy(texto, "\r\n");
			strcat(texto, time);
			char TempText[]="007";
			uint16_t Centenas = temp/100;
			TempText[0] = Centenas+0x30;
			uint16_t Decenas = (temp-Centenas)/10;
			TempText[1] = Decenas+0x30;
			uint16_t Unidades = (temp-Centenas-Decenas);
			TempText[2] = Unidades+0x30;
			strcat(texto, "\t");
			strcat(texto, TempText);
			f_write(&Fil, texto, sizeof(texto), bw);
        	f_close(&Fil);}
	return;}
