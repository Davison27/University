select concat(concat(A.nombre,' va antes que '),b.nombre) "ORDENACION"
from localidades a, localidades b
where b.idlocalidad like a.idlocalidad+1