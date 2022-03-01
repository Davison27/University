select l.nombre
from votante v, localidades l 
where v.localidad=l.idlocalidad
group by l.nombre
order by avg(decode(v.estudiossuperiores,'Ninguno',0,'Basicos',1,'Superiores',2,'Doctorado',3) desc