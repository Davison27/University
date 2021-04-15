select v.nombrecompleto
from votantes v
where substr(v.dni,-1,1)=substr(v.telefono,-1,1)