(defrule nohicenada "Inicializa el hecho hice en caso de que no exista"
	(not (hice $?))
	=>
	(assert (hice nada))
)

(defrule iniciaNumMoves
    (not (myNumMoves $?))
    =>
    (assert (myNumMoves 0))
)

(defrule moveWilly "Mueve a willy en una dirección elegida al azar, siempre que no haya amenazas actualmente"
   (directions $? ?direction $?)
   ?h <- (hice $?)
   (percepts) ; No se detecta ningún peligro
   (?h2<-(myNumMoves ?numMoves&:(< ?numMoves 999))) ; No se ha alcanzado el número máximo de pasos
   =>
   (retract ?h ?h2)
   (assert (hice ?direction)) ; Apuntar el movimiento que se hizo para que se puede volver a él si hay un peligro
   (assert (myNumMoves (+ ?numMoves 1))) ; Incrementar el número de pasos
   (moveWilly ?direction)
)


(defrule moveYRezaWilly "Mover a willy en una dirección aleatoria, en caso de detectar peligro y no tener apuntado el último movimiento"
   (directions $? ?direction $?)
   ?h <- (hice nada)
   (percepts ? $?) ; Se detecta algún peligro
   (?h2<-(myNumMoves ?numMoves&:(< ?numMoves 999))) ; No se ha alcanzado el número máximo de pasos
    =>
   (retract ?h ?h2)
   (assert (hice ?direction)) ; Apuntar el movimiento que se hizo para que se puede volver a él si hay un peligro
   (assert (myNumMoves (+ ?numMoves 1))) ; Incrementar el número de pasos
   (moveWilly ?direction)
)

(defrule volverNorthWilly "Retroceder cuando el movimiento realizado previamente fue al norte"
   (directions $? south $?)
   ?h <- (hice x?) ; Condición para que esta regla se ejecute sólo para volver de un movimiento hacia arriba
   (percepts ? $?) ; Se detecta algún peligro
   (?h2<-(myNumMoves ?numMoves&:(< ?numMoves 999))) ; No se ha alcanzado el número máximo de pasos
	=>
   (retract ?h ?h2) 
   ; No hace falta apuntar lo que se hizo
   (assert (myNumMoves (+ ?numMoves 1))) ; Incrementar el número de pasos
   (moveWilly south); Mover a willy en la dirección contraria
)

(defrule volverSouthWilly "Retroceder cuando el movimiento realizado previamente fue al sur"
   (directions $? north $?)
   ?h <- (hice x?) ; Condición para que esta regla se ejecute sólo para volver de un movimiento hacia abajo
   (percepts ? $?) ; Se detecta algún peligro
   (?h2<-(myNumMoves ?numMoves&:(< ?numMoves 999))) ; No se ha alcanzado el número máximo de pasos
   =>
   (retract ?h ?h2)
   ; No hace falta apuntar lo que se hizo
   (moveWilly north) ; Mover a willy en la dirección contraria
   (assert (myNumMoves (+ ?numMoves 1))) ; Incrementar el número de pasos

  )

(defrule volverWestWilly "Retroceder cuando el movimiento realizado previamente fue al oeste"
   (directions $? east $?) 
   ?h<-(hice x?) ; Condición para que esta regla se ejecute sólo para volver de un movimiento hacia la izquierda
   (percepts ? $?) ; Se detecta algún peligro
   (?h2<-(myNumMoves ?numMoves&:(< ?numMoves 999))) ; No se ha alcanzado el número máximo de pasos
	=>
   (retract ?h ?h2)
   ; No hace falta apuntar lo que se hizo
   (moveWilly east) ; Mover a willy en la dirección contraria
   (assert (myNumMoves (+ ?numMoves 1))) ; Incrementar el número de pasos
)

(defrule volverEastWilly "Retroceder cuando el movimiento realizado previamente fue al este"
   (directions $? west $?)
   ?h <- (hice x?) ; Condición para que esta regla se ejecute sólo para volver de un movimiento hacia la derecha
   (percepts ? $?) ; Se detecta algún peligro
   (?h2<-(myNumMoves ?numMoves&:(< ?numMoves 999))) ; No se ha alcanzado el número máximo de pasos
   =>
   (retract ?h ?h2)
   ; No hace falta apuntar lo que se hizo
   (moveWilly west) ; Mover a willy en la dirección contraria
   (assert (myNumMoves (+ ?numMoves 1))) ; Incrementar el número de pasos
)
 
(defrule fireWilly "En caso de percibir algún sonido, dispara en una dirección aleatoria"
   (hasLaser)
   (percepts $? Noise $?)
   (directions $? ?direction $?)
   =>
   (fireLaser ?direction)
 )

(defrule foundAlienCol "Encontrar dos ruidos en la misma columna"
  (declare (salience 10))
  (hasLaser)
  (casilla (peligros $? Noise $?)
      (-------) ; Añadir las condiciones de fila y columna de la casilla 1
   ) 
   (casilla (peligros $? Noise $?)
      (-------) ; Añadir las condiciones de fila y columna de la casilla 2
   )
   (casilla (-------)) ; Añadir las condiciones de fila y columna de la casilla 3
   =>
   (-------) ; Crear el hecho alien con su fila y columna
)

(defrule foundAlienRow "Encontrar dos ruidos en la misma fila"
     (declare (salience 10))
  (hasLaser)
  (casilla (peligros $? Noise $?)
      (-------) ; Añadir las condiciones de fila y columna de la casilla 1
   ) 
   (casilla (peligros $? Noise $?)
      (-------) ; Añadir las condiciones de fila y columna de la casilla 2
   )
   (casilla (-------)) ; Añadir las condiciones de fila y columna de la casilla 3
   =>
   (-------) ; Crear el hecho alien con su fila y columna
)

(defrule killAlienNorth "Dispara al alien si está al norte"
   (declare (salience 20)) ; Más priorirdad que ninguna regla previa
   (hasLaser) ; Aún se tiene el láser para disparar
   (----------) ; Capturar la posición actual de Willy
   ?ha <- (--------) ; Capturar la posición del alien y comprobar si está al norte de la posición de Willy
   ?hm <- (myNumMoves ?m&:(< ?m 999))
   =>
   (retract ?ha ?hm)
   ((directions $? north $?)
   =>
   (fireLaser ?direction)) ; Disparar al norte
   (assert (myNumMoves (+ ?m 1))) ; El disparo también disminuye las reservas de oxígeno de Willy
)


(defrule killAlienSouth "Dispara al alien si está al sur"
      (declare (salience 20)) ; Más priorirdad que ninguna regla previa
   (hasLaser) ; Aún se tiene el láser para disparar
   (----------) ; Capturar la posición actual de Willy
   ?ha <- (--------) ; Capturar la posición del alien y comprobar si está al norte de la posición de Willy
   ?hm <- (myNumMoves ?m&:(< ?m 999))
   =>
   (retract ?ha ?hm)
   ((directions $? south $?)
   =>
   (fireLaser ?direction)) ; Disparar al sur
   (assert (myNumMoves (+ ?m 1))) ; El disparo también disminuye las reservas de oxígeno de Willy
)


(defrule killAlienEast "Dispara al alien si está al este"
     (declare (salience 20)) ; Más priorirdad que ninguna regla previa
   (hasLaser) ; Aún se tiene el láser para disparar
   (----------) ; Capturar la posición actual de Willy
   ?ha <- (--------) ; Capturar la posición del alien y comprobar si está al norte de la posición de Willy
   ?hm <- (myNumMoves ?m&:(< ?m 999))
   =>
   (retract ?ha ?hm)
   ((directions $? east $?)
   =>
   (fireLaser ?direction)) ; Disparar al este
   (assert (myNumMoves (+ ?m 1))) ; El disparo también disminuye las reservas de oxígeno de Willy
)


(defrule killAlienWest "Dispara al alien si está al oeste"
      (declare (salience 20)) ; Más priorirdad que ninguna regla previa
   (hasLaser) ; Aún se tiene el láser para disparar
   (----------) ; Capturar la posición actual de Willy
   ?ha <- (--------) ; Capturar la posición del alien y comprobar si está al norte de la posición de Willy
   ?hm <- (myNumMoves ?m&:(< ?m 999))
   =>
   (retract ?ha ?hm)
   ((directions $? west $?)
   =>
   (fireLaser ?direction)) ; Disparar al oeste
   (assert (myNumMoves (+ ?m 1))) ; El disparo también disminuye las reservas de oxígeno de Willy
)
