select v.nombrecompleto, avg(cd.certidumbre)
from votantes v 
join consultas c 
on v.dni=c.votante 
join consultas_datos cd
on cd.idconsulta=cd.consulta 
where cd.respuesta='Si'
having avg (cd.certidumbre)<0,5
and avg(cd.certidumbre)<0,8
group by v.nombrecompleto