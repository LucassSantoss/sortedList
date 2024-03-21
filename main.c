#include "sortedList.h"
#include <stdio.h>
#include <stdlib.h>

/*
  Feito por:
  SC3037916 Github: @LucassSantoss
  SC3038289 Github: @TiagoCatoia
  SC3038025 Github: @brunomascioli

1. Indique ponto(s) forte(s) e fraco(s) de uma lista ordenada, justificando-os.

  #### Pontos Fortes ####
    
    Busca Eficiente: A ordenação permite a utilização de algoritmos de busca
  rápida, como a busca binária, que tem uma complexidade de tempo O(log n). 
  Isso é significativamente mais rápido do que a busca linear O(n) necessária em 
  uma lista desordenada, especialmente para listas grandes.

    Acesso Ordenado: Manter os elementos em uma ordem específica (por exemplo, 
  crescente ou decrescente) é útil em aplicações que exigem processamento 
  sequencial de dados em uma determinada ordem. Isso facilita operações como a 
  geração de relatórios classificados, iteração ordenada para exibição 
  de dados, entre outras.

  #### Pontos Fracos ####
    
    Inserção e remoção: Ao inserir ou remover um novo elemento, sua posição
  correta dentro da ordem é identificada e feita a realocação dos elementos,
  onde tal realocação apresenta complexidade O(n), por outro lado um lista não
  ordenada poderia simplismente adicionar o elemento no final da lista.

    Dificuldade de implementação: Implementar uma estrutura de dados de 
  lista ordenada é uma tarefa um pouco mais complexa se comparado a de
  uma lista normal.

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
  t_sorted_list *lista = create_list(10, 0);
  append(lista, 4);
  append(lista, 1);
  append(lista, 2);
  append(lista, -2);
  append(lista, 133);
  append(lista, -1);
  print_list(lista);

  printf("\n\n");
  t_sorted_list *lista2 = create_list(10, 1);
  append(lista2, 4);
  append(lista2, 1);
  append(lista2, 2);
  append(lista2, -2);
  append(lista2, 133);
  append(lista2, -1);
  print_list(lista2);
  return 0;
}