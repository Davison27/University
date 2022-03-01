select c.partido, count(c.consulta)
from consultas_datos c
group by c.partido
having (count(c.consulta)>0)