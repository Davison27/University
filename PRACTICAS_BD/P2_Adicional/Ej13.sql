select p.nombrecompleto, avg(cd.certidumbre)
from partidos partidos
join consultas_datos cd
on p.idpartido=cd.partido 
where cd.respuesta='No'
and cd.certidumbre>0,6
group by p.nombrecompleto