(deftemplate jugador
	(slot nombre (type STRING) (default ?NONE))
	(multislot historial (allowed-symbols victoria derrota empate))
	(slot nivel (type INTEGER) (default 1)(range 1 5))
)

(deftemplate barco
	(slot tipo (allowed-symbols patrullera dragaminas fragata acorazado destructor portaaviones)(default ?NONE))
	(slot fila (allowed-symbols A B C D E F G H I J K L))
	(slot columna (type INTEGER)(range 1 12))
	(slot orientacion (allowed-symbols horizontal vertical))
	(slot estado (allowed-symbols indemne tocado hundido))
	(slot jugador (type STRING))
)

(deffacts jugadores
	(jugador (nombre "Ana"))
	(jugador (nombre "Juan")(historial victoria victoria)(nivel 4))
)

(deffacts partidas
	(barco (tipo patrullera)(fila A)(columna 1)(orientacion horizontal)(estado indemne)(jugador "Ana"))
	(barco (tipo fragata)(fila H)(columna 3)(orientacion vertical)(estado indemne)(jugador "Juan"))
)