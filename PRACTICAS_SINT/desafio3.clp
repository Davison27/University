(deffunction fibonacci
	(?x)
	(if (or (not (integerp ?x)) (< ?x 0))
    	  then 
    		(printout t "Fibonacci no definido para " ?x crlf)
   	else
    		(if (< ?x 2) then ?x
      else
       	(+ (fibonacci (- ?x 1)) (fibonacci (- ?x 2)))
      )
   )
)







(defgeneric maximo)
(defmethod maximo
   ((?a NUMBER) (?x NUMBER))
   (if (< ?x ?a) then
   	?a
   else
   	?x)
)
(defmethod maximo
   ((?a STRING) (?x STRING))
   (if (< (length$ $?x) (length$ $?a)) then
   	?a
   else
   	?x)
)