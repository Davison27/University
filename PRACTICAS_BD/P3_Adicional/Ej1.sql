select substr(v.nombrecompleto,1,instr(v.nombrecompleto,' ')) "NOMBRE", l.nombre "LOCALIDAD", p.comunidad "COMUNIDAD"
from votantes v, localidades l, comunidad p
where v.localidad=l.idlocalidad
and l.provincia=p.idprovincia
and l.idlocalidad in (1,3,9)