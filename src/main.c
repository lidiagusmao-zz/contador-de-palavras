//Lidia Gusmao 172323
#include <stdio.h>
#include <string.h>

int main() {

   char frase[1000];
   int numero_palavras=0, tamanho=0, i=0;

   fgets(frase, 999, stdin); //Lê a string toda (o 1000º caracter é reservado para \n)
   tamanho=strlen(frase); //Conta o numero de caracteres a serem lidos da string "frase"

   while(i<tamanho){
        //Caso em que ha um marcador de fim de palavra, incrementa-se a variavel "numero_palavras"
        if(frase[i]==' ' || frase[i]=='.' || frase[i]==',' || frase[i]==';' || frase[i]=='-' || frase[i]=='!' || frase[i]=='?'){
            numero_palavras++;
            //Caso em que ha um numero depois do ponto ou da virgula
            if(frase[i]=='.' || frase[i]==','){
                i++;
                //Se o proximo caracter depois da virgula ou do ponto for um numero, decrementa-se a variavel "numero_palavras"
                if(frase[i]=='0' || frase[i]=='1' || frase[i]=='2' || frase[i]=='3' || frase[i]=='4' || frase[i]=='5' || frase[i]=='6' || frase[i]=='7' || frase[i]=='8' || frase[i]=='9')
                numero_palavras--;

            }
            //Se o caracter for algum marcador senão ponto ou virgula
            else
            i++;

            //Caso em que há repetição de marcadores
            while(frase[i]==' ' || frase[i]=='.' || frase[i]==',' || frase[i]==';' || frase[i]=='-' || frase[i]=='!' || frase[i]=='?')
                i++;
        }

        //Caso em que o caracter nao e marcador
        while(frase[i]!=' ' && frase[i]!='.' && frase[i]!=',' && frase[i]!=';' && frase[i]!='-' && frase[i]!='!' && frase[i]!='?' && frase[i]!='\n'){
            i++;
            if(frase[i]=='\n')
                numero_palavras++;
        }

        //Caso em que chega no fim da frase e deve-se imprimir o valor de "numero_palavras"
        if(frase[i]=='\n'){
            printf("%d\n", numero_palavras);
            break;
        }
   }
   return 0;
 }