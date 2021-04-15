(deffacts vectores
	(vector A 2 5 3 7 6 4 9)
	(vector B 1 3 8 19 3 4)
	(vector C 4 8 9 2 3 4)
)
(defrule vec
	(or (vector ?nombre $?antes ?a&:(integerp ?a)&:(= ?a 3)
	$?medio ?b&:(integerp ?b)&:(= ?b 4) $?despues)
	 (vector ?nombre $?antes ?a&:(integerp ?a)&:(= ?a 4)
	$?medio ?b&:(integerp ?b)&:(= ?b 3) $?despues)
	)
	(test (oddp (length $?medio)))
	=>
	(printout t "El vector" ?nombre "cumple la condicion" crlf)
	)
	
########################################

(deffacts hechos
	(dato 1)
	(dato 5.0)
	(dato verde)
	(dato "hola")
)

(defrule assertTodos
	(not (todos-los-datos))
	=>
	(assert (todos-los-datos))
)

(defrule regla
	?f1<-(dato ?x)
	?f2<-(todos-los-datos $?a)
	=>
	(retract ?f1)	
	(retract ?f2)
	(assert (todos-los-datos $?a ?x))
)

########################################

(deffacts datos
	(vector A 3 35 7 23 4 1 13)
)

(defrule ordenMenorAMayor
	?f<-(vector ?nombre $?antes ?x ?y $?despues)
	(test (< ?y ?x))
	=>
	(retract ?f)
	(assert (vector ?nombre $?antes ?y ?x $?despues))
)