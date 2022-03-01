select v.nombrecompleto, p.comunidad
from votantes v, provincias p, localidades localidades
where l.numerohabitantes>'300000'
and v.localidad=l.idlocalidad
and l.provincia=p.idprovincia