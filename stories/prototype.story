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
Era uma vez, um gerreiro destemido.
Um dia esse guerreiro decidiu viajar em direção ao 
{2
Norte|TrilhaDosPeregrinos
Oeste|VilaCatraca
}
'''
O operador -> (seta) direciona a história diretamente para a sena que ele aponta
Perante uma lista de opções. 	
O jogador sempre poderá responder utilizando a mesma palavra que aparece como 
opção ou um número, quer represente a ordem de uma das opções, em ordem 
crescente e iniciando sempre em 1.
'''

@TrilhaDosPeregrinos
Ao seguir pela trilha dos peregrinos você é surpreendido por um Goblin
que pula em sua direção sacudindo uma espada enferrujada e grunindo palavras
em seu idioma orrível e ininteligível. O que você vai fazer?
{3
Correr|VilaCatraca
Lutar|CombateGoblin
Esconder-se|DescobertoGoblin
}


@VilaCatraca
Você corre até suas pernas não aguentarem mais, mas quando se da conta percebe
que foi parar na terrível vila catraca.
{2
Entrar na Cidade|EntrarVilaCatraca
Voltar|CombateGoblin
}

@EntrarVilaCatraca
A Vila Catraca é conhecida por ser o lugar mais perigoso da região, por isso 
não é nada sábil ficar atoa por aí. O que você irá fazer?
{2
Atravessar a Cidade|EmboscadaGoblin
Entrar na Taverna|TavernaVilaCatraca
}

@TavernaVilaCatraca
Você tomou uma cerveja envenenada, esse é o seu fim.


@EmboscadaGoblin
O Goblin estava te esperando na saída da cidade, acompanhado de seus capangas.
Esse é o seu Fim.

@CombateGoblin
Você decide bravamente ficar e enfrentar o Goblin, afinal ele poder possuir
algum bem de valor...
[ATK:5, ENERGY:20]
{2
Vitoria|VitoriaNaVilaCatraca
Derrota|MortoPeloGoblin	
}

@VitoriaNaVilaCatraca
Parabéns você derrotou o Goblin e será lembrado por toda a eternidade!
{2
Recomeçar|Inicio
Sair|Fim
}

@MortePeloGoblin
Mesmo pequeno e desprezivel um Goblin ainda é mortal...
{2
Recomeçar|Inicio
Recarregar o ultimo save|CombateGoblin
}

@DescobertoGoblin
Infelizmente a vil criatura sente o seu cheiro e sem pensar duas vezes 
te atravessa com um golpe de espada, este é o seu fim.
{2
Recomeçar|Inicio
Recarregar o ultimo save|TrilhaDosPeregrinos
}


@Fim
Fim.