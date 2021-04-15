select v.dni "VOTANTE", count(c.votante)
from votantes v, consultas c 
where v.dni=c.votante
having count(c.votante)>
    (select avg(count(votante))
    from consultas
    group by votante)
group by v.dni
order by (count(c.votante)) desc