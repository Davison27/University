select v.nombrecompleto, l.nombre
from votantes v, localidades l 
where v.localidad=l.idlocalidad
like decode(v.localidad,1,9,2,9,3,9,v.localidad)