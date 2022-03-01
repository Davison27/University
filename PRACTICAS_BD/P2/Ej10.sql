select p.nombrecompleto, count(c.consulta)
from partidos p, consultas_datos c
where c.partido=p.idpartido
and c.certidumbre>'0,8'
and c.respuesta='Si'
group by p.nombrecompleto