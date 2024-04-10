#include<stdio.h>
#include<string.h>
#include<stdlib.h>

FILE *cfg=NULL;

void abrir() {
	if(cfg==NULL) {
		cfg=fopen("cfg.bin", "rb+");
	}
}

void cerrar() {
	if(cfg!=NULL) fclose(cfg);
}

int farg(char *f) {
	printf("uso incorrecto");
	if(f!=NULL) {
		printf(" de la funcion %s", f);
	}
	printf("\n\n");
	cerrar();
	return 2;
}

int fnr(char * f) {
	printf("opcion %s no reconocida\n", f);
	cerrar();
	return 1;
}

unsigned int load() {
	unsigned int r=0;
	unsigned char c;
	rewind(cfg);
	for(int i=0;i<4;i++) {
		r<<=8;
		c=getc(cfg);
		r=r|c;
	}
	return r;
}

void list() {
	unsigned int l=load();
	for(int i=31;i>=0;i--) {
		printf("%d", (l>>i)&1);
	}
	printf("\n");
}

int save(unsigned int r) {
	rewind(cfg);
	for(int s=24;s>=0;s-=8) {
		unsigned int m=255<<s;
		char c=(char)((r&m)>>s);
		putc(c, cfg);
	}
	return 0;
}

int reset() {
	save((unsigned int)0);
	return 0;
}

int main(int argc, char **argv) {
	abrir();
	int p;
	switch(argc) {
	case 1:
		return farg(NULL);
		break;
	case 2:
		if(strcmp(argv[1], "on")==0 ||
		   strcmp(argv[1], "off")==0) {
			return farg(argv[1]);
		} else if (strcmp(argv[1], "reset")==0) {
			reset();
		} else if (strcmp(argv[1], "list")==0) {
			list();
		} else {
			return fnr(argv[1]);
		}
		break;
	case 3:
		p=atoi(argv[2]);
		unsigned int r=load();
		unsigned int n=1<<p;
		if(strcmp(argv[1], "on")==0) {
			r|=n;
			printf("on %d\n", p);
		} else if (strcmp(argv[1], "off")==0) {
			r&=(~n);
			printf("off %d\n", p);
		} else if (strcmp(argv[1], "reset")==0 ||
			   strcmp(argv[1], "list")==0  ||
			   strcmp(argv[1], "help")==0) {
			return farg(argv[1]);
		} else {
			return fnr(argv[1]);
		}
		save(r);
		break;
	default:
		return farg(NULL);
	}
	cerrar();
	return 0;
}