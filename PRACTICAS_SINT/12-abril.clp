(defrule buscar-animal-sonido-gallo
	(or (sonido kikiriki) (animal gallo))
	=>
	(printout t "El gallo hace kikiriki" ctrf)
)

################################################

(defrule buscar-animal
	(or (sonido ?x ?y) (animal ?y ?x))
	=>
	(printout t "El" " ?y " "hace"   ?x  crlf)
)

################################################

(deffacts salvar-dia
	(objetivo salvar-el-dia)
	(heroe spiderman desocupado)
	(heroe daredevil desocupado)
	(heroe ironman ocupado)
)

(defrule dia-salvado
	(objetivo salvar-el-dia)
	(heroe ? desocupado)
	=>
	(printout t "Dia salvado" crlf)
)

################################################

(defrule puedo-pasar
	(logical (semaforo verde))
	=>
	(assert (puedo pasar))
)


################################################

(defrule primera
	(declare (salience 10))
	=>
	(printout t "Me salgo la primera" crlf)
)
(defrule segunda
	=>
	(printout t "Me salgo la segunda" crlf)
)
(defrule tercera
	(declare (salience -35))
	=>
	(printout t "me ejecuto la tercera" crlf)
)