select p.nombrecompleto, max(cd.certidumbre)
from partidos p, consultas_datos cd
where cd.partido=p.idpartido
group by p.nombrecompleto
