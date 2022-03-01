select v.nombrecompleto, l.idlocalidad, decode(trunc((sysdate-to_date(v.fechanacimiento))/365,25),
0,'menor de edad',
1,'menor de edad',
2,'menor de edad',
3,'menor de edad',
4,'menor de edad',
5,'menor de edad',
6,'menor de edad',
7,'menor de edad',
8,'menor de edad',
9,'menor de edad',
10,'menor de edad',
11,'menor de edad',
12,'menor de edad',
13,'menor de edad',
14,'menor de edad',
15,'menor de edad',
16,'menor de edad',
17,'menor de edad',
'mayor de edad')
from votantes v, localidades l 
where l.idlocalidad=v.localidad 
and v.localidad in (2,4,8)