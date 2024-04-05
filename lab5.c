/*#include<stdio.h>
#include<stdlib.h>

void hexdump(char *cale)
{
	FILE* fisier=fopen(cale, "rb");
	if(fisier==NULL)
	{
		perror(NULL);
		exit(-1);
	}
	int offset=0;
	char buffer[16];
	size_t citire;
	while(!(feof(fisier)))
	{
		if((citire=fread(buffer, sizeof(char), sizeof(buffer),fisier))==0)
		{
			perror(NULL);
			exit(-1);
		}
		printf("%080X", offset);
		
		for(int i=0;i<16;i++)
		{
			printf("%02X ", buffer[i]);
		}
		printf(" ");
		for(int i=0;i<16;i++)
		{
			if((buffer[i]>32)&&(buffer[i]<255))
			{
				printf("%c", buffer[i]);
			}
			else
			{
				printf(".");
			}
		}
		printf("\n");
		offset=offset+citire;
	
	}
	if(!fclose(fisier))
	{
		perror(NULL);
		exit(-1);
	}
	
}

int main(int argc, char **argv)
{
	if(argc!=2)
	{
		printf("Eroare la argumente");
		exit(-1);
	}
	hexdump(argv[1]);
	return 0;
}




#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void compar(char* path1, char* path2)
{
	int offset=0;

	FILE* fisier1=fopen(path1, "rb");
	FILE* fisier2=fopen(path2, "rb");
	int lungime1=0;
	int lungime2=0;
	size_t citire;
	
	int *v1=NULL;
	int *v2=NULL;
	
	char buffer[1000];
	if(fisier1==NULL)
	{
		perror(NULL);
		exit(-1);
	}
	if(fisier2==NULL)
	{
		perror(NULL);
		exit(-1);
	}

	fseek(fisier1, 0, SEEK_END);
	lungime1=ftell(fisier1)/sizeof(int);
	rewind(fisier1);
	
	v1=(int*)malloc(lungime1*sizeof(int));
	if(v1==NULL)
	{
		perror(NULL);
		exit(-1);
	}
	fread(v1, sizeof(int), lungime1, fisier1);
	rewind(fisier1);
	
	fseek(fisier2,0, SEEK_END);
	lungime2=ftell(fisier2)/sizeof(int);
	rewind(fisier2);
	
	v2=(int*)malloc(lungime2*sizeof(int));
	if(v2==NULL)
	{
		perror(NULL);
		exit(-1);
	}
	
	fread(v2, sizeof(int), lungime2, fisier2);
	rewind(fisier2);
	
	if(lungime1>lungime2)
	{
		while((citire=fread(buffer,1, sizeof(buffer),fisier1))>0)
		{
			fwrite(buffer,1,sizeof(buffer),fisier1);
		}
		rewind(fisier2);
	}
	if(lungime2>lungime1)
	{
		while((citire=fread(buffer,1, sizeof(buffer),fisier2))>0)
		{
			fwrite(buffer,1,sizeof(buffer),fisier2);
		}
		rewind(fisier2);
	}
	int minim=0;
	if(lungime1<lungime2)
	{
		minim=lungime1;
	}
	if(lungime2<lungime1)
	{
		minim=lungime2;
	}
	if(lungime1==lungime2)
	{
		minim=lungime1;
	}
	for(int i=0;i<minim;i++)
	{
		if(v1[i]!=v2[i])
		{
			printf("%02X %02X %02x ", offset, v1[i], v2[i]);
		}
		offset++;
	}
	
	if(!fclose(fisier1))
	{
		perror(NULL);
		exit(-1);
	}
	if(!fclose(fisier2))
	{
		perror(NULL);
		exit(-1);
	}
}

int main(int argc, char**argv)
{
	if(argc!=3)
	{
		printf("Eroare la argumente");
		exit(-1);
	}
	compar(argv[1],argv[2]);
	return 0;
}


#include<stdio.h>
#include<stdlib.h>

int main(int argc, char**argv)
{
	if(argc!=3)
	{
		perror(NULL);
		exit(-1);
	}
	char buffer[4096];
	size_t citire;
	FILE*fisier_citire=fopen(argv[1],"rb");
	if(fisier_citire==NULL)
	{
		perror(NULL);
		exit(-1);
	}
	
	FILE*fisier_scriere=fopen(argv[2], "wb");
	if(fisier_scriere==NULL)
	{
		perror(NULL);
		exit(-1);
	}
	while((citire=fread(buffer,1,4096,fisier_citire))>0)
	{
		fwrite(buffer,1,4096,fisier_scriere);
	}
	if(fclose(fisier_citire)!=0)
	{
		perror(NULL);
		exit(-2);
	}
	if(fclose(fisier_scriere)!=0)
	{
		perror(NULL);
		exit(-2);
	}
	return 0;
}


#include<stdio.h>
#include<stdlib.h>
int main()
{
	int matrice[100][100];
	int n=0;
	int m=0;
	printf("n=");scanf("%d", &n);
	printf("m=");scanf("%d", &m);
	//int nr_elemente=n*m;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("matrice[%d][%d]=", i, j);scanf("%d", &matrice[i][j]);
		}
	}
	FILE*fisier=fopen("scriere.bin", "wb");
	if(fisier==NULL)
	{
		perror(NULL);
		exit(-1);
	}
	
	if(fwrite(&n,sizeof(int),1,fisier)==0)
	{
		perror(NULL);
		exit(-1);
	}
	if(fwrite(&m,sizeof(int),1,fisier)==0)
	{
		perror(NULL);
		exit(-1);
	}
	for(int i=0;i<m;i++)
	{
		if(fwrite(matrice[i],sizeof(int),n,fisier)==0)
		{
			perror(NULL);
			exit(-1);
		}
	}
	
	
	if(fclose(fisier)==0)
	{
		perror(NULL);
		exit(-1);
	}
	
	return 0;
}

*/
