select p.nombrecompleto
from partidos p, consultas_datos c
where c.partido=p.idpartido
group by (p.nombrecompleto)
having (count(c.consulta)>'10')