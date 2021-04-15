(deftemplate profesor
	(slot dni (type SYMBOL) (default ?NONE))
	(slot nombre (type STRING) (default ?NONE))
	(slot apellidos (type STRING) (default ?NONE))
)

(deftemplate alumno
	(slot dni (type SYMBOL) (default ?NONE))
	(slot nombre (type STRING) (default ?NONE))
	(slot apellidos (type STRING) (default ?NONE))
	(slot nota_examen (type FLOAT) (default ?NONE))
	(slot nota_practicas (type FLOAT) (default ?NONE))
	
)

(deftemplate grupo
	(multislot dni_paciente (type SYMBOL) (default ?NONE))
	(slot nota (type FLOAT) (default ?NONE))
)