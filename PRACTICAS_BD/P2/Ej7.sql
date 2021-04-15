select c.partido, count(c.consulta)
from consultas_datos c
group by c.partidos