select v.nombrecompleto
from votantes v
where v.fechanacimiento<'12/01/1990'
and v.nombrecompleto like '%5%'