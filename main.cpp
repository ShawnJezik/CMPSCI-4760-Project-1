#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void help(void);

int main(int argc, char **argv)
{
int c;
int j=0,len,i;
char *input = "inputFile.dat";
char *output = "outputFile.dat";
FILE *fptr_input = NULL;
FILE *fptr_output = NULL;
char data[100];
char reverse[100];

while ((c = getopt (argc, argv, "ab:c:")) != -1)
{
switch (c)
{
case 'a':
help();
return 1;
break;
case 'b':
input = optarg;
break;
case 'c':
output = optarg;
break;
case '?':
printf("Unknown option");
help();
return 1;
default:
break;
}
}

printf("Input file %s\n",input);
printf("Output File %s\n",output);

fptr_input = fopen(input,"r");

if(fptr_input == NULL){
perror("FILE open");
}

fptr_output = fopen(output,"w+");

if(fptr_output == NULL){
perror("FILE open");
}

while(!feof(fptr_input))
{
fgets(data,sizeof(data),fptr_input);
char *pos;
if ((pos=strchr(data, '\n')) != NULL){
*pos = '\0';

}

len = strlen(data);

for (i = len - 1; i >= 0; i--)
{
reverse[j++] = data[i];
}
reverse[i] = '\0';

fprintf(fptr_output,reverse,sizeof(reverse));
reverse[0]='\0';
data[0]='\0';
}

fclose(fptr_input);
fclose(fptr_output);
return 0;
}
void help(void)
{
printf("Help -->\n");
printf("-a : all help\n");
printf("-b : input file name\n");
printf("-c : output file name\n");
}
