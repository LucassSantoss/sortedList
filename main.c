#include "sortedList.h"
#include <stdio.h>
#include <stdlib.h>

//testando

/*
1. Indique ponto(s) forte(s) e fraco(s) de uma lista ordenada, justificando-os.


2. Descreva a estratégia utilizada para o aumento de memória quando o usuário 
deseja inserir mais itens que o alocado previamente
  
    Para lidar com o aumento de memória quando o usuário deseja inserir mais itens
  do que o espaço alocado previamente, foi adotada a estratégia de realocação de
  um novo vetor com capacidade maior. Para o calculo da nova capacidade, foi 
  definido um fator de crescimento igual a dois.
    Dessa forma, quando o limite de itens inseridos na lista é atingido, o vetor 
  é realocado com uma capacidade duas vezes maior do que a anterior, garantindo 
  que haja espaço suficiente para a inserção de mais elementos sem a necessidade
  de realocações frequentes, o que é custoso em termos de desempenho.
    Essa estratégia permite um equilíbrio entre o uso eficiente de memória 
  e o desempenho das operações de inserção, garantindo que a lista possa crescer
  conforme necessário sem incorrer em realocações excessivas.

*/
int main(){
  t_sorted_list *lista = create_list(10);
  append(lista, 4);
  append(lista, 1);
  append(lista, 2);
  append(lista, -2);
  append(lista, 133);
  append(lista, -1);
  print_list(lista);
  return 0;
}
