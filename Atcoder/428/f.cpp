/*
os intervalos nao crescem de tamanho, eles se movimentam
como wi > wi-1, e garantido que toda query de tipo 1/2 vai mexer tambem em todos os intervalos que vem antes de mim
entao quando eu faco uma query do tipo 1, eu movimento v intervalos para ter L = Meu l
e isso tambem garante que nenhum intervalo alterado vai passar da minha direita, ja que todos sao menores que eu
*/