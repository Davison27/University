select v.nombrecompleto, count(c.evento)
from votantes v
join consultas c 
on v.dni=c.votante
group by v.nombrecompleto
having count(c.evento)>3
order by count(c.evento) asc