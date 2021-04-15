select v.nombrecompleto
from votantes v, consultas c 
where v.dni=c.votante 
and v.situacionlaboral like 'Activo'
having count(c.votante)<
    (select avg(count(votante))
    from consultas 
    group by votante)
group by v.nombrecompleto