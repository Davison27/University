select v.nombrecompleto, l.nombre 
from votantes v, localidades l 
where v.localidad=l.idlocalidad 
and l.numerohabitantes>300000


select v.nombrecompleto, l.nombre 
from votantes v 
join localidades l 
on v.localidad=l.idlocalidad 
where l.numerohabitantes>300000