select v.nombrecompleto, avg(cd.certidumbre)
from votantes v
join consultas c 
on c.idconsulta=cd.consulta
where cd.respuesta='Si'
group by v.nombrecompleto