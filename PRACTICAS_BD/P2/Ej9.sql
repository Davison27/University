select p.nombrecompleto, count(c.consulta)
from partidos p, consultas_datos c
where c.partidos=p.idpartido
group by (p.nombrecompleto)
having (count(c.consulta)>'10')
