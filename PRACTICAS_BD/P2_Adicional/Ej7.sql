select dni 
from votantes 
join consultas 
on votantes.dni=consultas.votante
group by dni
having count(evento)>3