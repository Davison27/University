(deftemplate paciente
	(slot nombre (type STRING) (default ?NONE))
	(slot apellidos (type STRING) (default ?NONE))
	(slot dni (type SYMBOL) (default ?NONE))
	(slot seguro_medico)
)

(deftemplate visita
	(slot dni_paciente (default ?NONE))
	(slot fecha (type SYMBOL) (default ?NONE))
	(slot sintomas (type STRING))
	(multislot pruebas (allowed-values resonancia radiografica pcr "test antigenos"))
	(multislot medicacion (type STRING))
)
