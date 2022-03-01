select v.dni "VOTANTE", count(c.votante)
from consultas c, votantes v 
where v.dni=c.votante 
group by v.dni
order by (count(c.votante)) desc