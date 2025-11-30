//EV Máximo

/*
(r/m)^n - ((r-1)/m)^n = probabilidade de ter exatamente r como o maior resultado 
somatorio de P(r) * r = EV do maximo

n: numero de eventos
r: resultado
m: quantidade de resultados possiveis para um evento
*/

r * ((fastExpo((r/m), n)) - (fastExpo((ld)(r-1)/m, n)));
