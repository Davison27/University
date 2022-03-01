(deftemplate camion
    (slot id)
    (slot estado-frenos (range 0 100))
    (slot estado-neumaticos (range 0 100))
)

(deftemplate alarma
    (slot camion)
    (slot color (allowed-values naranja rojo))
)

(deffacts flota-camiones
    (camion (id 123) (estado-frenos 90) (estado-neumaticos 40))
    (camion (id 789) (estado-frenos 30) (estado-neumaticos 40))
    (camion (id 246) (estado-frenos 20) (estado-neumaticos 10))
    (camion (id 357) (estado-frenos 60) (estado-neumaticos 80))
)

(defrule alarma-grave
	(declare (salience 20))
	(and (camion (estado-frenos (range 0 50))) (camion (estado-neumaticos (range 0 50))))
	=>
	(assert (alarma (camion id) rojo))
)




(defrule alarma-media
	(declare (salience 10))
	(or (camion (estado-frenos (range 0 50))) (camion (estado-neumaticos (range 0 50))))
	=>
	(assert (alarma (camion id) naranja))
)



(defrule aviso-pantalla
	(declare (salience 0))
	(exists (alarma rojo))
	=>
	(printout t "Hay camiones que requieren revision" crlf)
	
)



(defrule visita-taller
	(declare (salience -10))
	(exists (alarma ?x rojo))
	=>
	(printout t "El camion" ?x "se ha puesto a punto" crlf)
	(assert (camion estado-frenos(100)) (camion estado-neumaticos(100)))
	
	(logical (alarma ?x rojo))
	=>
	(assert (NULL))
)

	