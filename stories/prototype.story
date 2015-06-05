[[setup]]
'''
Aqui é onde você fara a configuração de exibição da sua hitória.
'''
[[endsetup]]
= Text Adventure Game =
'''
Tudo que estiver entre três aspas simples será ignorado completamente pelo 
leitor. Sinta-se a vontade para utilizar esse artifício para explicar algum 
aspecto técnico da sua história. Como por eu estou fazendo aqui por exemplo.
'''
# Qualquer coisa escrita após um simbolo de # também é ignorada.
 
# O simbolo @ é utilizado para declarar uma cena.
# Uma cena pode ter qualquer nome desde que não possua acentuaçao e seja único 
# em toda a história.

@Inicio
Era uma vez, um gerreiro muito medroso.
Um dia esse guerreiro decidiu viajar em direção ao 

    - Norte -> TrilhaDosPeregrinos
    - Sul -> BrejoDosSussuros
    - Leste -> MontanhaSolitaria
    - Oeste -> FlorestaSombria

'''
O operador -> (seta) direciona a história diretamente para a sena que ele aponta
Perante uma lista de opções. 	
O jogador sempre poderá responder utilizando a mesma palavra que aparece como 
opção ou um número, quer represente a ordem de uma das opções, em ordem 
crescente e iniciando sempre em 1.
'''

@TrilhaDosPeregrinos
# <variavel> é a sintaxe para criar uma variável no escopo de uma cena.
# essa <<variavel>> é uma variável global e pode ser acessada de qualquer cena.
