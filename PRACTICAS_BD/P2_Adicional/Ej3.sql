select l.nombre, p.nombre
from localidades l, provincias p
where substr(l.numerohabitantes,-1,1) like l.provincia
and p.idprovincia=l.provincia
