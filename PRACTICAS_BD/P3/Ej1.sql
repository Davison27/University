select v.nombrecompleto
from votantes
where substr(v.dni,-legth(v.localidad+1),length(v.localidad+1))=v.localidad+1