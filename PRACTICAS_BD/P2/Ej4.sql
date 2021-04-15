select v.nombrecompleto, l.nombre
from votantes v, localidades localidades
where l.numerohabitantes>'300000'
and l.idlocalidad=v.localidad